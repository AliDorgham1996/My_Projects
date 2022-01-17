#include "structure.h"

void student_destroy(Student * ST)
{
    free(ST->Entry);  //free Data created by malloc
    ST->pNext = NULL;
    ST->pPrev = NULL;
}

void class_destroy(Class * C)
{
    Student * temp ;
    while(C->pHead != NULL)
    {
        temp = C->pHead->pNext;
        student_destroy(C->pHead); //first destroy student
        free(C->pHead); // then destroy the node
        C->pHead = temp;
    }
    C->pTail = NULL;
    C->C_no_students = 0;
    C->class_ID = 0;
}

void school_destroy(SchoolRootPtr root)
{
    if (!root) {return;}
    school_destroy(root->pLeft);
    school_destroy(root->pRight);
    class_destroy(root);
    free(root);
}
