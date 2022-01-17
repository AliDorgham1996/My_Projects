#ifndef STRUCTURE_H_INCLUDED
#define STRUCTURE_H_INCLUDED

#include "Types.h"

#define NAMESIZE       20
#define ADDRESSSIZE    20
#define PHONESIZE      15
#define IDSIZE         15

typedef struct student_data
{
    struct name
    {
        s8 first_name  [NAMESIZE];
        s8 middle_name [NAMESIZE];
        s8 last_name   [NAMESIZE];
    }Name; //
    struct birth_day
    {
        s32 day;
        s32 month;
        s32 year;
    }Birth_day; //
    struct address
    {
        s32 street_no;
        s8 street_name [ADDRESSSIZE];
        s8 city        [ADDRESSSIZE];
        s8 government  [ADDRESSSIZE];
    }Address; //
    s8 phone_number [PHONESIZE];
    s8 id [IDSIZE];  //dependent on input data
    struct subjects
    {
        s32 c_programming;
        s32 data_structure;
        s32 algorithms;
        s32 embedded_c;
        s32 subject_NO;
        f64 subjects_average;
    }Subjects;//
}Data;


typedef struct Node //list
{
    s32 index;      //for better use, instead of including it in Data
    Data* Entry;     //listEntry as structure , will use malloc again
    struct Node * pNext;  //as a list of node
    struct Node * pPrev;  //as a list of node
}Student;


typedef struct Class //tree(key, pLeft, pRight) +list(pHead, pTail, entry = pHead->Entry)
{
    Student * pHead;  //the enter point to students in class
    Student * pTail;  //the enter point to students in class
    s32 C_no_students;//size of class = how many students are there ?
    //////////////////////////////////////////////////////////
    struct Class * pLeft;  //(class is a node in school tree)
    struct Class * pRight; //(class is a node in school tree)
    s32 class_ID;     //the key for tree
}Class;

typedef Class* SchoolRootPtr; //root of tree

typedef struct School //list
{
    SchoolRootPtr Root;  //this is the entry of school
    s32 no_classes ;    //school size
    s32 S_no_students ;  //no of all students
}School;
/*
////////////////////////////////////////////////////////////////////////////////////////////
//searching in students

//1-Queue for Names , ID
typedef struct queueNode //every node in queue carry address of particular Student
{
    Student * target;
}QueueNode;

typedef struct Queue_ //circular buffer (dynamic array queue)
{
    QueueNode * pFront;
    QueueNode * pRear;
    u32 QueueSize;
}Queue;
typedef Queue* Report_1; //information report;


//2
typedef struct stackNode //every node in queue carry address of particular Student
{
    Student * target;
}StackNode;

typedef struct Stack //calling by value by using referance
{
    StackNode * pTop;
    u32 StackSize;
}Report;
*/

#endif // STRUCTURE_H_INCLUDED
