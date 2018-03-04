//
//  main.cpp
//  LinkedList
//
//  Created by AlvinLi on 03/03/2018.
//  Copyright © 2018 iforgotten. All rights reserved.
//

#include "funDef.h"

int main(int argc, char **argv)
{
    // basicsKnowledge();
    PLISTNODE head = nullptr;
    head = initList();
    printList(head, "origin");
    
    PLISTNODE newList = reverseList(head);
    printList(newList, "reverse");
    
    PLISTNODE headList = reverseListAtHeadNode(newList);
    printList(headList, "AtHead");
    
    PLISTNODE rangeList = reverseBetween(headList,3,4);
    printList(rangeList, "rangeList");
    
    PLISTNODE l1 = nullptr;
    PLISTNODE l2 = nullptr;
    l1 = initList();
    l2 = initList();
    PLISTNODE mergeList = mergeTwoLists(l1,l2);
    printList(mergeList, "mergeList");
    
    releaseList(rangeList);
    releaseList(mergeList);
    
    head = nullptr;
    newList = nullptr;
    headList = 
    mergeList = nullptr;
    l1 = nullptr;
    l2 = nullptr;
    return 0;
}


