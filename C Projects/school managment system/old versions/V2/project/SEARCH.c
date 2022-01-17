#include "structure.h"
#include "Types.h"
#include <stdio.h>


Student* searchStudent(Student* ST, s32 index)
{
    while(ST != NULL && ST->index != index)
    {
        ST = ST->pNext;
    }
    return ST ;
}


SchoolRootPtr searchClass(SchoolRootPtr Root, s32 index)
{
    if (Root == NULL || Root->class_ID == index)
       return Root;

    if (Root->class_ID < index)
       return searchClass(Root->pRight, index);

    return searchClass(Root->pLeft, index);
}
