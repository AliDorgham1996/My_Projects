#include "STUDENT.h"

void Class_Enter(School * S, Class * C)
{
    Greeting(greeting_arr[WELCOMECLASS]); //class
    printf("\n=======================================\n\a");
    printf("\nYou are in Class no %d\n",C->class_ID);
    printf("\n=======================================\n");
    s32 choice,temp;
    Student * ST;
    for(;;)  //task form
    {
        Main_Menu (menu_arr[CLASS_MENU]);
        scanf("%d",&choice);
        switch(choice)
        {
        case NEW_STUDENT://done
            {
                New_Student(S,C);
                printf("\n=======================================\n\a");
                printf("\nStudent no %d is added\n",C->C_no_students);
                printf("\n=======================================\n");
            break;
            }
        case DELETE_STUDENT://done
            {
                printf("Enter The Index of Student\n\a");
                scanf("%d",&temp);
                ST = searchStudent(C,temp);
                if(ST == NULL){printf("Student not found\n\a");}
                else
                {
                    Delete_Student(C,ST);
                    printf("\n=======================================\n\a");
                    printf("Student no %d is Deleted\n",temp);
                    printf("Now no of Students is : %d\n",-- C->C_no_students);
                    printf("\n=======================================\n");
                    S->S_no_students -- ;
                }
            break;
            }
        case PRINT_DATA_STUDENT://done
            {
                printf("Enter The Index of Student\n\a");
                scanf("%d",&temp);
                ST = searchStudent(C,temp);
                if(ST == NULL){printf("Student not found\n\a");}
                else{Print_Data_Student(ST,CARD);}
            break;
            }
        case EDIT_DATA_STUDENT://done
            {
                printf("Enter The Index of Student\n\a");
                scanf("%d",&temp);
                ST = searchStudent(C,temp);
                if(ST == NULL){printf("Student not found\n\a");}
                else {Edit_Data_Student(ST);}
            break;
            }
        case PRINT_SCORE_STUDENT ://done
            {
                printf("Enter The Index of Student\n\a");
                scanf("%d",&temp);
                ST = searchStudent(C,temp);
                if(ST == NULL){printf("Student not found\n\a");}
                else
                {
                    Main_Menu (menu_arr[SUBJECT_MENU]);
                    scanf("%d",&temp);
                    Print_Score_Student(ST,temp,CARD);
                }
            break;
            }
        case EDIT_SCORE_STUDENT ://done
            {
                printf("Enter The Index of Student\n\a");
                scanf("%d",&temp);
                ST = searchStudent(C,temp);
                if(ST == NULL){printf("Student not found\n\a");}
                else
                {
                    Main_Menu (menu_arr[SUBJECT_MENU]);
                    scanf("%d",&temp);
                    Edit_Score_Student(ST,temp);
                }
            break;
            }
        case EXIT_CLASS ://7
            {
                printf("Exit From Class no %d\n\a",C->class_ID);
                break;
            }
        default:
            printf("Wrong Choice\n\a");
        }
        if(choice == EXIT_CLASS){break;}
    }
    Greeting(greeting_arr[WELCOMESCHOOL]); //back to school
}
