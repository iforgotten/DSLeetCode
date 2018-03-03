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
    // releaseList(head);
    return 0;
}


