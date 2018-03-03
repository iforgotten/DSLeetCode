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
        printf("NULL");
        return;
    }
    
    while(pNode) {
        printf("[%d] ",pNode->val);
        pNode = pNode->next;
    }
    printf("\r\n");
} // 遍历输出链表所有元素
