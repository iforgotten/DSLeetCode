//
//  DataStructure.h
//  LinkedList
//
//  Created by AlvinLi on 03/03/2018.
//  Copyright © 2018 iforgotten. All rights reserved.
//

#ifndef DataStructure_h
#define DataStructure_h


typedef struct ListNode {
    int val;                                                // 数据域
    struct ListNode *next;                                  // 指针域
    ListNode(int value) : val(value), next(nullptr) {}      // 构造函数
}LISTNODE,*PLISTNODE;

#endif /* DataStructure_h */
