#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED


#include "structure.h"  // Class , Student
#include "ENUMS.h"      // choice options , greeting wrapper , menu wrapper
#include <stdio.h>      // printf
#include <stdlib.h>     // malloc
#include "Types.h"      // s32



//Extern variables : pointer to function
extern void (*menu_arr[])(void);  // global variable
extern void (*greeting_arr[])(void);  // global variable
//Extern functions
extern void Main_Menu (void(*)(void));
extern void Greeting (void(*)(void));
extern Student* searchStudent(Class*,s32);


//list
extern void New_Student(School* S ,Class* C);
extern void Delete_Student(School* S ,Class* C ,s32 index);
extern void Student_print(Student* ST);  // print data of identical student without subjects
extern void Student_Edit(Student* ST);   // fixed id , name , no relation with scores
extern void Rank_Print(Student* ST ,s32 choice); // print only subjects
extern void Edit_Score(Class* C ,s32 choice); // choice witch subject to edit

#endif // STUDENT_H_INCLUDED
