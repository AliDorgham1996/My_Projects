#include "structure.h"
#include "Types.h"
#include <stdio.h>


Student* searchStudent(Class* C, s32 ID)
{
    Student * temp;
    temp = C->pHead;
    while(temp != NULL && temp->index != ID)
    {
        temp = temp->pNext;
    }
    return temp ;
}


Class* searchClass(School * S, s32 ID)
{
    //binary search on a binary search tree
    //return SchoolRootPtr == Class *
    Class * C = NULL ;
    return C;
}

