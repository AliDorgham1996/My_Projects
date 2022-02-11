#include "STUDENT.h"
#include <stdio.h>


void Class_Enter(School * S, Class * C)
{
    Greeting(greeting_arr[WELCOMECLASS]); //class
    s32 choice,temp;
    Student * ST;
    for(;;)  //task form
    {
        Main_Menu (menu_arr[CLASS_MENU]);
        scanf("%d",&choice);
        switch(choice)
        {
        case NEW_STUDENT://1
            {
                //New_Student(S,C);
            break;
            }
        case DELETE_STUDENT://2
            {
                printf("Enter The Index of Student\n");
                scanf("%d",&temp);
                ST = searchStudent(C,temp);
                if(ST == NULL){printf("Student not found\n");}
                else
                {
                    Delete_Student(S,C,temp);
                    printf("Student is Deleted\n");
                }
            break;
            }
        case STUDENT_PRINT://3
            {
                printf("Enter The Index of Student\n");
                scanf("%d",&temp);
                ST = searchStudent(C,temp);
                if(ST == NULL){printf("Student not found\n");}
                else{/*Student_print(ST);*/}
            break;
            }
        case STUDENT_EDIT://4
            {
                printf("Enter The Index of Class\n");
                scanf("%d",&temp);
                ST = searchStudent(C,temp);
                if(ST == NULL){printf("Student not found\n");}
                else {/*Student_Edit(ST);*/}
            break;
            }
        case RANK_PRINT ://5
            {
                printf("Enter The Index of Class\n");
                scanf("%d",&temp);
                ST = searchStudent(C,temp);
                if(ST == NULL){printf("Student not found\n");}
                else
                {
                    Main_Menu (menu_arr[SUBJECT_MENU]);
                    scanf("%d",&temp);
                    //Rank_Print(ST,temp);
                }
            break;
            }
        case EDIT_SCORE ://6
            {
                printf("Enter The Index of Class\n");
                scanf("%d",&temp);
                ST = searchStudent(C,temp);
                if(ST == NULL){printf("Student not found\n");}
                else
                {
                    Main_Menu (menu_arr[SUBJECT_MENU]);
                    scanf("%d",&temp);
                    //Edit_Score(C,temp);
                }
            break;
            }
        case EXIT_CLASS ://7
            {
                printf("EXIT_FROM_CLASS\n");
                break;
            }
        default:
            printf("Wrong Choice\n");
        }
        if(choice == EXIT_CLASS){break;}
    }
}
