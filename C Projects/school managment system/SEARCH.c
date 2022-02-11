#include "structure.h"

static Student* BinarySearch(Class * C, s32 l, s32 r, s32 index);

Student* searchStudent(Class* C, s32 index)
{
    if(C->pHead == NULL){return NULL;} // precaution : if C->pHead == NULL , so C->pHead->index will cause crash
    return (BinarySearch( C , C->pHead->index , C->pTail->index , index ));
}

static Student* BinarySearch(Class * C, s32 l, s32 r, s32 index) // iteratively
{
    Student * temp = C->pHead ;
    s32 m ;
    while (l <= r)
    {
        m = l + (r - l) / 2;
        if (temp->index == index){return temp;}
        if (temp->index < index)
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
        temp = temp->pNext;
    }
    return temp; // no dangling pointer because C->pHead does exist in heap
}

SchoolRootPtr searchClass(SchoolRootPtr Root, s32 index)//binary search on a (BST) , recursively
{
    if (Root == NULL || Root->class_ID == index)
       return Root;

    if (Root->class_ID < index)
       return searchClass(Root->pRight, index);

    return searchClass(Root->pLeft, index);
}

void Class_new_index(School* S, s32* new_index)
{
    s32 i;
    for(i=1 ; i<S->no_classes ; i++)
    {
        if(searchClass(S->Root , i) == NULL)
        {
            break;
        }
    }
    *new_index = i;
}
