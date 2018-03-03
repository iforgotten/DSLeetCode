//
//  funDef.cpp
//  LinkedList
//
//  Created by AlvinLi on 03/03/2018.
//  Copyright © 2018 iforgotten. All rights reserved.
//

#include "DataStructure.h"
#include "funDef.h"
#include <stdio.h>

// 链表的基础知识
void basicsKnowledge() {
    ListNode a(10);
    ListNode b(20);
    ListNode c(30);
    ListNode d(40);
    ListNode e(50);
    
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = nullptr;
    
    PListNode pHead = &a;
    while(pHead) {
        printf("The current Node value is %d, Address is %p, The next node address is %p\r\n",pHead->val,&pHead, pHead->next);
        pHead = pHead->next;
    }
    printf("\r\n");
    return;
}
