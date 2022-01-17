#include "structure.h"

void Edit_Score_Student(Student* ST ,s32 subject)
{
    switch (subject)
    {
    case C_Programming :
        {
            printf("Enter Score of C Programming\n\a");
            scanf("%d",&ST->Entry->Subjects.c_programming);
        }
        break;
    case Data_Structure :
        {
            printf("Enter Score of Data Structure\n\a");
            scanf("%d",&ST->Entry->Subjects.data_structure);
        }
        break;
    case Algorithms :
        {
            printf("Enter Score of Algorithms\n\a");
            scanf("%d",&ST->Entry->Subjects.algorithms);
        }
        break;
    case Embedded_C :
        {
            printf("Enter Score of Embedded C\n\a");
            scanf("%d",&ST->Entry->Subjects.embedded_c);
        }
        break;
    }
}

void Edit_Class_Score(Class*C)// print all class scores of one subjects
{
    s32 subject;
    Main_Menu (menu_arr[SUBJECT_MENU]);
    scanf("%d",&subject);
    switch (subject)
    {
    case C_Programming  : {printf("Edit Class Scores of C Programming\n\a");}
        break;
    case Data_Structure : {printf("Edit Class Scores of Data Structure\n\a");}
        break;
    case Algorithms     : {printf("Edit Class Scores of Algorithms\n\a");}
        break;
    case Embedded_C     : {printf("Edit Class Scores of Embedded C\n\a");}
        break;
    }
    Student* ST = C->pHead;
    while(ST != C->pTail)
    {
        Edit_Score_Student(ST, subject);
        ST = ST->pNext;
    }
}

void Edit_Data_Student(Student* ST)
{
    s8 choice;
    printf("Change Birthday ?  (y/n)\n\a");
    fflush(stdin);
    scanf("%c",&choice);
    if(choice == 'y')
    {
        printf("\n\t\tBirthday\n\n\a");
        printf("Enter Day\n\a");
        scanf("%d",&ST->Entry->Birth_day.day);
        printf("Enter Month\n\a");
        scanf("%d",&ST->Entry->Birth_day.month);
        printf("Enter Year\n\a");
        scanf("%d",&ST->Entry->Birth_day.year);
    }
    printf("Change Address ?  (y/n)\n\a");
    fflush(stdin);
    scanf("%c",&choice);
    if(choice == 'y')
    {
        printf("\n\t\tAddress\n\n\a");
        printf("Enter Street No\n\a");
        scanf("%d",&ST->Entry->Address.street_no);
        printf("Enter Street Name\n\a");
        scanf("%s",ST->Entry->Address.street_name);
        printf("Enter City Name\n\a");
        scanf("%s",ST->Entry->Address.city);
        printf("Enter Government\n\a");
        scanf("%s",ST->Entry->Address.government);
    }
    printf("Change Phone Number ?  (y/n)\n\a");
    fflush(stdin);
    scanf("%c",&choice);
    if(choice == 'y')
    {
        printf("\nEnter phone Number like : +20 1234567890 \n\a");
        fflush(stdin);
        scanf("%[^\n]%*c",ST->Entry->phone_number);  // to take space in consideration !
    }
}
