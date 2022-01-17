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
extern Student* searchStudent(Student* ST, s32 index);


//list
extern void New_Student(School* S ,Class* C);
extern void Delete_Student(Class* C ,Student* ST);
extern void Print_Data_Student(Student* ST);  // print data of identical student without subjects
extern void Edit_Data_Student(Student* ST);   // fixed id , name , no relation with scores
extern void Print_Score_Student(Student* ST ,s32 choice); // print only subjects
extern void Edit_Score_Student(Student* ST ,s32 choice); // choice witch subject to edit




#endif // STUDENT_H_INCLUDED
