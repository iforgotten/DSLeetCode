// LeetCode 160. Intersection of Two Linked Lists Difficulty: Easy
// 已知链表A的头结点headA，链表B的头结点headB，两个链表相交，求两链表交点对应的结点
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    // 边界判断
    if(headA == nullptr || headB == nullptr) {
        return nullptr;
    } else if (headA == headB) {
        return headA;
    }
    
    ListNode* pA = headA;
    ListNode* pB = headB;
    int lenA = 0;
    int lenB = 0;
    
    // 获取A,B链表的长度
    while (pA || pB) {
        if(pA) {
            lenA++;
            pA = pA->next;
        }
        if(pB) {
            lenB++;
            pB = pB->next;
        }
    }

    // 对齐
    pA = headA;
    pB = headB;
    int minus = lenB - lenA;
    for(int i = 1; i <= abs(minus); ++i) {
        if(minus < 0) {
            // lenB < lenA
            pA = pA->next;
        }
        if(minus > 0) {
            pB = pB->next;
        }
    }
    
    // 两个指针开始遍历
    while (pA && pB && pA != pB) {
        pA = pA->next;
        pB = pB->next;
    }
    
    if(pA == nullptr || pB == nullptr) {
        return nullptr;
    } else {
        return pA;
    }
} // 获取两相交链表的对应的结点

ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
    std::set<ListNode*> buff;
    ListNode* pA = headA;
    ListNode* pB = headB;
    
    // 初始化set
    while(pA) {
        buff.insert(pA);
        pA = pA->next;
    }
    
    while(pB) {
        // 如果能找到相同的地址，说明有交点，返回第一个交点即可
        if(buff.find(pB) != buff.end()) {
            return pB;
        }
        pB = pB->next;
    }
    return nullptr;
} // 利用STL中的set集合的特性，进行去重操作；