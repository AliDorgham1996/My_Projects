#include "structure.h"
#include <stdlib.h>
#include "Types.h"
#include <stdio.h>

extern void Student_init(Student *ST ,s32 index);

static void InsertStudent(Class* C , Student * ST);

////////////////////////////////////////////////////////////////////////

void New_Student(School* S ,Class* C)
{
    Student* ST = (Student*)malloc(sizeof(Student));
    if(ST != NULL)
    {
        Data* info = (Data*)malloc(sizeof(Data));
        if(info != NULL)
        {
            ST->Entry = info;   //connections
            ST->index = ++ C->C_no_students;
            S->S_no_students ++;
            Student_init(ST , S->S_no_students);
            InsertStudent(C,ST);
        }
        else{printf("Heap is Full no more place to insert info\n");}
    }
    else{printf("Heap is Full no more place for any Students\n");}
}


static void InsertStudent(Class* C , Student * ST)
{
    if(C->pHead == NULL)//Class is empty
    {
        C->pHead = ST;
        C->pTail = ST;
    }
    else //Class is not Empty
    {
       Student *temp = C->pHead ; //slider
       while( (temp != NULL) && (temp->index < (ST->index)) )
       {
           temp = temp->pNext;
       }
       if(temp == C->pHead)//insert at head
       {
           C->pHead->pPrev = ST;   //1- assign new node to be (old head prev)
           ST->pNext = C->pHead;   //2- assign new node next to be old head
           C->pHead = ST;          //3- assign new head
       }
       else if(temp == NULL)//insert at Tail
       {
           C->pTail->pNext = ST;
           ST->pPrev = C->pTail;
           C->pTail = ST;
       }
       else //insert in mid
       {
           ST->pPrev = temp->pPrev;
           ST->pNext = temp;
           temp->pPrev->pNext = ST;
           temp->pPrev = ST;
       }
    }
}
