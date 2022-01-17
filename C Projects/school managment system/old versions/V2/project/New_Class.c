#include "structure.h"
#include <stdlib.h>
#include "Types.h"
#include <stdio.h>

extern void Class_init(Class *C , s32 ID);

static SchoolRootPtr Insert_Class(SchoolRootPtr C, s32 index);
static SchoolRootPtr NewClassNode(s32 index);
////////////////////////////////////////////////////////////////////


SchoolRootPtr New_Class(School* S)
{
    return Insert_Class(S->Root, ++ S->no_classes);
}

static SchoolRootPtr Insert_Class(SchoolRootPtr C, s32 index)
{
    if (C == NULL){return NewClassNode(index);}
    if (index < C->class_ID)
    {
        C->pLeft = Insert_Class(C->pLeft, index);
    }
    else
    {
        C->pRight = Insert_Class(C->pRight, index);
    }
    return C;
}


static SchoolRootPtr NewClassNode(s32 index)
{
    SchoolRootPtr C = (SchoolRootPtr)malloc(sizeof(Class));
    if(C != NULL)
    {
        Class_init(C ,index);
    }
    else {printf("Heap is Full no more place for any Class\n");}
    return C;
}


