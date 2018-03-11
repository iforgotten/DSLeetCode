// LeetCode 92 Reverse Linked List II Difficulty: Medium
// 已知链表头结点指针head，将链表位置[m,n]逆序，要求空间复杂度为O(1)
ListNode* reverseBetween(ListNode *head,const int m,const int n) {
    // 分治策略
    // 先考虑单一结点，再考虑两个结点
    // 考虑中间，考虑两边
    // 最后合并结果即可
    // [m,n]; 1 <= m <= n <= length
    // 边界判断
    if(!head) {
        return nullptr;
    } else if(!head->next || m - n == 0) {
        return head;
    }
    // 设置临时头结点,方便运算
    ListNode tmpHead(-1);
    tmpHead.next = head;
    ListNode* preNode = &tmpHead;
    // 找到第m个结点的前驱结点，并保存
    for(int i = 1; i <= m - 1; ++i) {
        preNode = preNode->next;
    }
    // 第m个结点，即，第一个待交换的结点
    ListNode* pCurNode = preNode->next;
    // n的后继节点
    ListNode* pTailNode = preNode->next;

    ListNode* reverse = nullptr;
    ListNode* pNext = nullptr;
    int len = n - m + 1;
    
    // 就地逆置
    for(int i = 1; i <= len; ++i) {
        // 1. 备份后继，以便寻址
        pNext = pCurNode->next;
        // 2. 断链
        pCurNode->next = reverse;
        reverse = pCurNode;
        pCurNode = pNext;
    }
    if(pTailNode) {
        pTailNode->next = pNext;
    }
    preNode->next = reverse;
    return tmpHead.next;
} // 逆置[m,n]的链表结点，并返回原链表指针