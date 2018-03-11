// LeetCode 142. Linked List Cycle Difficulty: Medium
// 已知链表中可能有环，如有环，返回环的起始结点，否则返回NULL
ListNode *detectCycle(ListNode *head) {
    std::set<ListNode*> buff;
    ListNode* pNode = head;
    while(pNode) {
        // 如果在buff里面有相同地址的内存单元，则会在最后一个迭代器之前
        if(buff.find(pNode) != buff.end()) {
            // 找到，表示有环
            return pNode;
        }
        buff.insert(pNode);
        pNode = pNode->next;
    }
    return nullptr;
} // 返回有环的第一个结点

ListNode *detectCycle2(ListNode *head) {
    ListNode* fast = head;
    ListNode* slow = head;
    ListNode* meet = nullptr;
    
    // 快慢指针
    while(fast) {
        fast = fast->next;
        if(fast) {
            return nullptr;
        }
        // 慢指针每次走一步，快指针每次走两步
        slow = slow->next;
        fast = fast->next;
        
        // 快慢指针相遇
        if(fast == slow) {
            meet = fast;
            break;
        }
    }
    
    // 如果meet等于空，则表示没有环
    while(meet == nullptr) {
        return nullptr;
    }
    
    while(head != meet) {
        head = head->next;
        meet = meet->next;
    }
    return head;
} // 快慢指针进行判断是否有环，有环返回其环的首节点