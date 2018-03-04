//
//  funDef.cpp
//  LinkedList
//
//  Created by AlvinLi on 03/03/2018.
//  Copyright © 2018 iforgotten. All rights reserved.
//

#include "funDef.h"
#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <vector>

// 链表的基础知识
void basicsKnowledge() {
    LISTNODE a(10);
    LISTNODE b(20);
    LISTNODE c(30);
    LISTNODE d(40);
    LISTNODE e(50);
    
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = nullptr;
    
    PLISTNODE pHead = &a;
    while(pHead) {
        printf("The current Node value is %d, Address is %p, The next node address is %p\r\n",pHead->val,&pHead, pHead->next);
        pHead = pHead->next;
    }
    printf("\r\n");
    return;
}

PLISTNODE initList() {
    PLISTNODE head = new LISTNODE(1);
    PLISTNODE pNode = head;
    for(int i = 2; i <= 5; ++i) {
        pNode->next = new LISTNODE(i);
        pNode = pNode->next;
    }
    return head;
} // 初始化链表

bool releaseList(PLISTNODE head) {
    if (!head) {
        return false;
    }
    PLISTNODE pHead = head;
    while(pHead) {
        head = pHead->next;
        delete pHead;
        pHead = head;
    }
    head = nullptr;
    return true;
} // 释放链表空间

void printList(PLISTNODE head, const char *name) {
    printf("%s :", name);
    PLISTNODE pNode = head;
    if(!pNode) {
        printf("NULL\r\n");
        return;
    }
    
    while(pNode) {
        printf("[%d] ",pNode->val);
        pNode = pNode->next;
    }
    printf("\r\n");
} // 遍历输出链表所有元素

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
    LISTNODE tmpHead(-1);
    tmpHead.next = head;
    PLISTNODE preNode = &tmpHead;
    // 找到第m个结点的前驱结点，并保存
    for(int i = 1; i <= m - 1; ++i) {
        preNode = preNode->next;
    }
    // 第m个结点，即，第一个待交换的结点
    PLISTNODE pCurNode = preNode->next;
    // n的后继节点
    PLISTNODE pTailNode = preNode->next;

    PLISTNODE reverse = nullptr;
    PLISTNODE pNext = nullptr;
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

ListNode* mergeTwoLists(ListNode* l1,ListNode* l2) {
    LISTNODE head(-1);
    
    // 初始化三个指针，分别用来遍历三个链表：l1, l2, newList
    PLISTNODE pl1 = l1;
    PLISTNODE pl2 = l2;
    PLISTNODE pHead = &head;
    
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

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    // 边界判断
    if(headA == nullptr || headB == nullptr) {
        return nullptr;
    } else if (headA == headB) {
        return headA;
    }
    
    PLISTNODE pA = headA;
    PLISTNODE pB = headB;
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
    std::set<PLISTNODE> buff;
    PLISTNODE pA = headA;
    PLISTNODE pB = headB;
    
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

bool hasCycle(ListNode *head) {
    // 创建集合，set为平衡树实现的
    std::set<PLISTNODE> buff;
    PLISTNODE pNode = head;
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
    PLISTNODE fast = head;
    PLISTNODE slow = head;
    
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
}

ListNode *detectCycle(ListNode *head) {
    std::set<PLISTNODE> buff;
    PLISTNODE pNode = head;
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
    PLISTNODE fast = head;
    PLISTNODE slow = head;
    PLISTNODE meet = nullptr;
    
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
