//
//  DataStructure.h
//  LinkedList
//
//  Created by AlvinLi on 03/03/2018.
//  Copyright © 2018 iforgotten. All rights reserved.
//

#ifndef DataStructure_h
#define DataStructure_h


struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int value) : val(value), next(NULL) {}
};

#endif /* DataStructure_h */
