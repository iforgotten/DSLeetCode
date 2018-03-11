// LeetCode 141. Linked List Cycle Difficulty: Easy
// 已知链表中可能有环，如有环，返回true，没有，返回FALSE；
bool hasCycle(ListNode *head) {
    // 创建集合，set为平衡树实现的
    std::set<ListNode*> buff;
    ListNode* pNode = head;
    while(pNode) {
        // 如果在buff里面有相同地址的内存单元，则会在最后一个迭代器之前
        if(buff.find(pNode) != buff.end()) {
            // 找到，表示有环
            return true;
        }
        buff.insert(pNode);
        pNode = pNode->next;
    }
    return false;
} // 判断是否有环

bool hasCycle2(ListNode *head) {
    if(!head) {
        return false;
    }
    ListNode* fast = head;
    ListNode* slow = head;
    
    while(fast) {
        fast = fast->next;
        if(!fast) {
            return false;
        }
        slow = slow->next;
        fast = fast->next;
        
        // 是否相遇，如果相遇，则跳出循环；
        if(fast == slow) {
            return true;
        }
    }
    return false;
} // 快慢指针进行判断是否有环