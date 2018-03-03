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
    releaseList(head);
    return 0;
}


