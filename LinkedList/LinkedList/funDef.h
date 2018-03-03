//
//  funDef.h
//  LinkedList
//
//  Created by AlvinLi on 03/03/2018.
//  Copyright © 2018 iforgotten. All rights reserved.
//

/**
    所有函数的头文件
 **/

#ifndef funDef_h
#define funDef_h

#include "DataStructure.h"
// 基础知识
void basicsKnowledge();

// 链表构造及析构
PLISTNODE initList();
bool releaseList(PLISTNODE head);
// 打印链表
void printList(PLISTNODE head, const char *name);

// LeetCode 206 Reverse Linked List; Difficul Degree: Easy
// 已知链表头结点指针head，将链表原地逆置
ListNode* reverseList(ListNode *head);


#endif /* funDef_h */
