// LeetCode 21. Merge Two Sorted Lists Difficulty: Easy
// 已知两个已排序链表头结点指针l1与l2，将这两个链表合并后仍为有序的，返回合并后的头结点
ListNode* mergeTwoLists(ListNode* l1,ListNode* l2) {
    ListNode head(-1);
    
    // 初始化三个指针，分别用来遍历三个链表：l1, l2, newList
    ListNode* pl1 = l1;
    ListNode* pl2 = l2;
    ListNode* pHead = &head;
    
    while(pl1 && pl2) {
        if(pl1->val <= pl2->val) {
            // 1. 备份
            l1 = pl1->next;
            // 2. 锻炼
            pl1->next = nullptr;
            // 3. 插入
            pHead->next = pl1;
            // 4. 寻址
            pHead = pHead->next;
            pl1 = l1;
        } else {
            l2 = pl2->next;
            pl2->next = nullptr;
            pHead->next = pl2;
            pHead = pHead->next;
            pl2 = l2;
        }
    }
    
    if (pl1) {
        pHead->next = pl1;
    }
    
    if (pl2) {
        pHead->next = pl2;
    }
    pl1 = nullptr;
    pl2 = nullptr;
    pHead = nullptr;
    return head.next;
} // 合并两个已经排好序的链表