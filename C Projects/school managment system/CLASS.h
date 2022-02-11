#ifndef CLASS_H_INCLUDED
#define CLASS_H_INCLUDED

#include "structure.h"

extern SchoolRootPtr searchClass(SchoolRootPtr Root, s32 index);//binary search
void Class_new_index(School* S, s32* new_index);

//tree
extern SchoolRootPtr New_Class(SchoolRootPtr C , s32 index);// add new class then loop with calling add student for filling students data , initiate Class();
extern SchoolRootPtr Delete_Class(SchoolRootPtr C, s32 index);// delete the whole class with its students with their data  , destroy class();
extern void Print_Class(Class* C);// print all the class due to id==Random or name==Alphabetical or index==Queue or Score of one subject
extern void Edit_Class_Score(Class*C);// print all class scores of one subjects
extern void Rank_Class(Class* C);//define first, second, third rank due to the avg of all subjects
extern void School_Rank(School* S);//define first, second,... , tenth rank due to the avg of all subjects
extern void Class_Enter(School*,Class*);

#endif // CLASS_H_INCLUDED
