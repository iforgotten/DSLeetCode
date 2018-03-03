//
//  funDef.cpp
//  LinkedList
//
//  Created by AlvinLi on 03/03/2018.
//  Copyright © 2018 iforgotten. All rights reserved.
//

#include "funDef.h"
#include <stdio.h>

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
