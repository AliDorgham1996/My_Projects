#ifndef CLASS_H_INCLUDED
#define CLASS_H_INCLUDED

#include "structure.h" //School , Class
#include "ENUMS.h"     //choice options , greeting wrapper , menu wrapper
#include <stdio.h>     //printf , NULL
#include <stdlib.h>    //malloc
#include "Types.h"     //s32


//tree
//Extern variables : pointer to function
extern void (*menu_arr[])(void);  // global variable
extern void (*greeting_arr[])(void);  // global variable
//Extern functions
extern void Main_Menu (void(*)(void));
extern void Greeting (void(*)(void));
extern SchoolRootPtr searchClass(SchoolRootPtr Root, s32 index);//binary search
extern void Class_Enter(School*,Class*);


//done prototypes , but without body
extern SchoolRootPtr New_Class(School* S);// add new class then loop with calling add student for filling students data , initiate Class();
extern SchoolRootPtr Delete_Class(SchoolRootPtr C, s32 index);// delete the whole class with its students with their data  , destroy class();
extern void Print_Class(Class* C, s32 choice);// print all the class due to id==Random or name==Alphabetical or index==Queue
extern void Class_Score(Class*C, s32 subject);// print all class scores of all subjects
extern void Rank_Class(Class* C);//define first, second, third rank due to the avg of all subjects



#endif // CLASS_H_INCLUDED
