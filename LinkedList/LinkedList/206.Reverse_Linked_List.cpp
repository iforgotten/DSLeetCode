// LeetCode 206 Reverse Linked List;  Difficulty: Easy
// 已知链表头结点指针head，将链表原地逆置,分三步
// 1. 备份后续节点地址，以便下一次寻址
// 2. 将当前节点从链表中断开，并填充其指针域（如果reverse链初始化为nullptr，则可以用reverse进行填充）
// 3. 寻址后续节点
ListNode* reverseList(ListNode *head) {
    if(!head) {
        return nullptr;
    }
    
    // 指向当前节点
    PLISTNODE pCurNode = head;
    PLISTNODE pNext = nullptr;
    PLISTNODE reverse = nullptr;
    
    while(pCurNode) {
        // 保存当前节点的后一个节点，进行备份，以免后面无法寻址
        pNext = pCurNode->next;
        // 断开当前节点与后一节点的连接，因为reverse初始化为nullptr，故可以直接赋值
        pCurNode->next = reverse;
        // 指向刚刚摘下来的节点
        reverse = pCurNode;
        // 进行下一个节点的寻址操作
        pCurNode = pNext;
    }
    return reverse;
} // 就地逆置

ListNode* reverseListAtHeadNode(ListNode *head) {
    PLISTNODE reverse = nullptr;
    PLISTNODE pCur = head;
    PLISTNODE pNext = nullptr;
    LISTNODE tmpNode(0);
    
    while (pCur) {
        // 保存当前节点的后继节点，以便寻址
        pNext = pCur->next;
        // 作为后继节点插入头结点
        pCur->next = tmpNode.next;
        tmpNode.next = pCur;
        // 继续寻址
        pCur = pNext;
    }
    reverse = tmpNode.next;
    return reverse;
} // 头插法逆序