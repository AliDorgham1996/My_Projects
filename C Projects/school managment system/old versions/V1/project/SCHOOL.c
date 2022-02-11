#include "CLASS.h"


void School_Fun(School* S)
{
    Greeting(greeting_arr[WELCOMESCHOOL]); //school
    s32 temp,choice;
    Class * C;
    s32 ST_NO;
    for(;;)  //task form
    {
        Main_Menu (menu_arr[SCHOOL_MENU]);
        scanf("%d",&choice);
        switch(choice)
        {
        case NEW_CLASS://1
            {
                //New_Class(S);
            break;
            }
        case DELETE_CLASS://2
            {
                printf("Enter The Index of Class\n");
                scanf("%d",&temp);
                C = searchClass(S,temp);  //Binary search
                ST_NO = C->C_no_students;
                if(C == NULL){printf("Class not found\n");}
                else if(NULL != Delete_Class(C,temp))
                {
                    printf("Class is Deleted\n");
                    S->S_no_students -= ST_NO;
                    S->no_classes--;
                }
            break;
            }
        case PRINT_CLASS://3
            {
                printf("Enter The Index of Class\n");
                scanf("%d",&temp);
                C = searchClass(S,temp);  //Binary search
                if(C == NULL){printf("Class not found\n");}
                else
                {
                    Main_Menu (menu_arr[PRINT_MENU]);
                    scanf("%d",&temp);
                    //Print_Class(C,temp);
                }
            break;
            }
        case CLASS_SCORE ://4
            {
                printf("Enter The Index of Class\n");
                scanf("%d",&temp);
                C = searchClass(S,temp);  //Binary search
                if(C == NULL){printf("Class not found\n");}
                else
                {
                    Main_Menu (menu_arr[SUBJECT_MENU]);
                    scanf("%d",&temp);
                    //Class_Score(C,temp);
                }
            break;
            }
        case RANK_CLASS ://5
           {
                printf("Enter The Index of Class\n");
                scanf("%d",&temp);
                C = searchClass(S,temp);  //Binary search
                if(C == NULL){printf("Class not found\n");}
                else {/*Rank_Class(C);*/}
            break;
           }
        case ENTER_CLASS ://6
            {
                printf("Enter The Index of Class\n");
                scanf("%d",&temp);
                C = searchClass(S,temp);  //Binary search
                if(C == NULL){printf("Class not found\n");}
                else {Class_Enter(S,C);}
            break;
            }
        case EXIT_SCHOOL ://7
                printf("EXIT_FROM_SCHOOL\n");
            break;
        default:
                printf("Wrong Choice\n");
        }
        if(choice == EXIT_SCHOOL){break;}
    }
}
