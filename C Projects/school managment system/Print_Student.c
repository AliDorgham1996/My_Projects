#include "structure.h"

void Print_Data_Student(Student* ST, s32 choice)
{
    switch (choice)
    {
        case CARD :
            {
                printf("\n\nStudent no  : %d\n\n\a",ST->index);
                printf("Name is         : ");
                printf("%s ",ST->Entry->Name.first_name);
                printf("%s ",ST->Entry->Name.middle_name);
                printf("%s\n",ST->Entry->Name.last_name);

                printf("ID is           : %s\n",ST->Entry->id);

                printf("Phone Number is : %s\n",ST->Entry->phone_number);

                printf("Birthday is     : ");
                printf("%-2d / ",ST->Entry->Birth_day.day);
                printf("%-2d / ",ST->Entry->Birth_day.month);
                printf("%-4d\n" ,ST->Entry->Birth_day.year);

                printf("Address is      : ");
                printf("%-2d Street, ",ST->Entry->Address.street_no);
                printf("%-s, ",ST->Entry->Address.street_name);
                printf("%s, ",ST->Entry->Address.city);
                printf("%s\n",ST->Entry->Address.government);
                printf("\n=======================================\n");
            }
            break;
        case TABLE :
            {
                printf("\n%d\t\t",ST->index);
                printf("%s\t\t",ST->Entry->id);
                printf("%s  ",ST->Entry->Name.first_name);
                printf("%s  ",ST->Entry->Name.middle_name);
                printf("%s\n",ST->Entry->Name.last_name);
            }
            break;
    }
}

void Print_Score_Student(Student* ST ,s32 subject, s32 choice)
{
    if(choice == CARD)
    {
        printf("Score of Student no %d\n\a",ST->index);
        switch (subject)
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
    else if (choice == TABLE)
    {
        switch (subject)
        {
        case C_Programming :
            {
                printf("\t%d\n",ST->Entry->Subjects.c_programming);
            }
            break;
        case Data_Structure :
            {
                printf("\t%d\n",ST->Entry->Subjects.data_structure);
            }
            break;
        case Algorithms :
            {
                printf("\t%d\n",ST->Entry->Subjects.algorithms);
            }
            break;
        case Embedded_C :
            {
                printf("\t%d\n",ST->Entry->Subjects.embedded_c);
            }
            break;
        }
    }
}
