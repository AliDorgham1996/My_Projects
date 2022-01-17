#include "Types.h"
#include <stdlib.h>
#include <stdio.h>
#include "structure.h"
#define ROOT_OF_SCHOOL 0

extern SchoolRootPtr Delete_Class(SchoolRootPtr root, s32 key);

// Precautions : Student exists
//free(student);
//this student = NULL;
void student_destroy(Student * ST)
{
    free(&ST->Entry);  //free Data created by malloc
    ST->pNext = NULL;
    ST->pPrev = NULL;
}


// Precautions : Class exists , class as a list (HEAD)
//loop Student_destroy();
//this class = NULL;
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



void school_destroy(School * S)
{
    if(NULL == Delete_Class(S->Root ,ROOT_OF_SCHOOL))  // root : 0 is the first node of tree
    {
        printf("School has been destroyed\n");
    }
}
