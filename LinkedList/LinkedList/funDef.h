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
// 已知链表头结点指针head，将链表原地逆置,分三步
// 1. 备份后续节点地址，以便下一次寻址
// 2. 将当前节点从链表中断开，并填充其指针域（如果reverse链初始化为nullptr，则可以用reverse进行填充）
// 3. 寻址后续节点
ListNode* reverseList(ListNode *head);

// 头插法
ListNode* reverseListAtHeadNode(ListNode *head);
#endif /* funDef_h */
