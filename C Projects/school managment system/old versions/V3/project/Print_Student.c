#include "structure.h"
#include "ENUMS.h"
#include <stdio.h>


void Print_Data_Student(Student* ST)
{
    printf("\n\t\tStudent no : %d\n\n\a",ST->index);

    printf("Name is :\t");
    printf("%s\t",ST->Entry->Name.first_name);
    printf("%s\t",ST->Entry->Name.middle_name);
    printf("%s\n",ST->Entry->Name.last_name);

    printf("ID is :\t%s\n",ST->Entry->id);

    printf("Phone Number is :\t%s\n",ST->Entry->phone_number);

    printf("Birthday is :\t");
    printf("%d / ",ST->Entry->Birth_day.day);
    printf("%d / ",ST->Entry->Birth_day.month);
    printf("%d\n" ,ST->Entry->Birth_day.year);

    printf("Address is :\t");
    printf("%d Street, ",ST->Entry->Address.street_no);
    printf("%s, ",ST->Entry->Address.street_name);
    printf("%s, ",ST->Entry->Address.city);
    printf("%s\n",ST->Entry->Address.government);
    printf("\n=======================================\n");
}

void Print_Score_Student(Student* ST ,s32 choice)
{
    switch (choice)
    {
    case C_Programming :
        {
            printf("\nScore of C Programming = ");
            printf("%d\n\a",ST->Entry->Subjects.c_programming);
        }
        break;
    case Data_Structure :
        {
            printf("\nScore of Data Structure = ");
            printf("%d\n\a",ST->Entry->Subjects.data_structure);
        }
        break;
    case Algorithms :
        {
            printf("\nScore of Algorithms = ");
            printf("%d\n\a",ST->Entry->Subjects.algorithms);
        }
        break;
    case Embedded_C :
        {
            printf("\nScore of Embedded C = ");
            printf("%d\n\a",ST->Entry->Subjects.embedded_c);
        }
        break;
    }
}
