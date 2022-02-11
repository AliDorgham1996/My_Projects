#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include "structure.h"

extern Student* searchStudent(Class * C, s32 index);
//list
extern void New_Student(School* S ,Class* C);
extern void Delete_Student(Class* C ,Student* ST);
extern void Print_Data_Student(Student* ST, s32 choise);  // print data of identical student without subjects
extern void Edit_Data_Student(Student* ST);   // fixed id , name , no relation with scores
extern void Print_Score_Student(Student* ST ,s32 subject,s32 choice); // print only subjects
extern void Edit_Score_Student(Student* ST,s32 subject); // choice witch subject to edit

#endif // STUDENT_H_INCLUDED
