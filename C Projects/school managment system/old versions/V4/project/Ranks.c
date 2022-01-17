#include "structure.h"

extern void SubjectSort(Buffer* arr,SubBuffer* A ,s32 subject ,s32 size);

/*
static Student * Calculate_Top_5 (School* S);
static Student * Calculate_Top_3 (Class* C);
static void Print_Top (Student * ST , s32 Rank);


void Rank_Class(Class* C)//define first, second, third rank due to the avg of all subjects
{
    Student * Top = (Student*)malloc(sizeof(Student)*TOP_3);
    Top = Calculate_Top_3(C);
    printf("\n==========================================\n");
    Print_Top(Top[FIRST] , FIRST);
    printf("\n==========================================\n");
    Print_Top(Top[SECOND] , SECOND);
    printf("\n==========================================\n");
    Print_Top(Top[THIRD] , THIRD);
    printf("\n==========================================\n");
    free(Top);
}


void School_Rank(School* S)//define first, second,... , tenth rank due to the avg of all subjects
{
    Student * Top = (Student*)malloc(sizeof(Student)*TOP_5);
    Top = Calculate_Top_5(C);
    printf("\n==========================================\n");
    Print_Top(Top[FIRST] , FIRST);
    printf("\n==========================================\n");
    Print_Top(Top[SECOND] , SECOND);
    printf("\n==========================================\n");
    Print_Top(Top[THIRD] , THIRD);
    printf("\n==========================================\n");
    Print_Top(Top[FOURTH] , FOURTH);
    printf("\n==========================================\n");
    Print_Top(Top[FIFTH] , FIFTH);
    printf("\n==========================================\n");
    free(Top);

}

static void Print_Top (Student * ST , s32 Rank)
{

    printf("NO %d :\n\a",Rank+1);
    printf("Name : %s ",ST->Entry->Name.first_name);
    printf("%s ",ST->Entry->Name.middle_name);
    printf("%s\n",ST->Entry->Name.last_name);
    printf("Over all Score = %lf\n",ST->Entry->Subjects.subjects_average);
}

static Student * Calculate_Top_3 (Class* C)
{

}

static Student * Calculate_Top_5 (School* S)
{

}
*/
