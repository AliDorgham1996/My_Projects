#include "structure.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


extern Student* searchStudent(Class *,s32);
extern void student_destroy(Student * ST);




void Delete_Student(School *S,Class* C, s32 index)
{
    Student* ST;
    ST = searchStudent(C,index);
    if(ST == NULL)//not found
    {
        printf("Student is't Found\n");
    }
    else if(ST == C->pHead && C->pHead == C->pTail)//it is the only student which is head and tail
    {
        student_destroy(ST);
        free(ST);
        C->pHead = NULL;
        C->pTail = NULL;
    }
    else if(ST == C->pHead)//delete head
    {
        C->pHead->pNext->pPrev = NULL;
        C->pHead = C->pHead->pNext;
        student_destroy(ST);
        free(ST);
    }
    else if(ST == C->pTail)//delete tail
    {
        C->pTail->pPrev->pNext = NULL;
        C->pTail = C->pTail->pPrev;
        student_destroy(ST);
        free(ST);
    }
    else
    {
        ST->pNext->pPrev = ST->pPrev;
        ST->pPrev->pNext = ST->pNext;
        student_destroy(ST);
        free(ST);
    }
    C->C_no_students--;
    S->S_no_students--;
}
