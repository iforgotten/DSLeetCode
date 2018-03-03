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
