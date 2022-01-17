#include "CLASS.h"

void School_Fun(School* S)
{
    Greeting(greeting_arr[WELCOMESCHOOL]); //school
    s32 temp,choice;
    Class * C;
    for(;;)  //task form
    {
        Main_Menu (menu_arr[SCHOOL_MENU]);
        scanf("%d",&choice);
        switch(choice)
        {
        case NEW_CLASS://done
            {
                S->no_classes ++ ;
                if(S->Root == NULL)
                {
                    S->Root = New_Class(S->Root, S->no_classes);
                }
                else
                {
                    Class_new_index(S, &temp);
                    S->Root = New_Class(S->Root, temp);
                }
            break;
            }
        case DELETE_CLASS://done
            {
                printf("Enter The Index of Class\n\a");
                scanf("%d",&temp);
                C = searchClass(S->Root,temp);  //precaution for delete
                if(C == NULL){printf("Class not found\n\a");}
                else
                {
                    printf("\n=======================================\n\a");
                    printf("Class no %d is Deleted\n",temp);
                    printf("%d Students are Deleted\n",C->C_no_students);
                    S->S_no_students -= C->C_no_students;
                    printf("Now no of Students in School is : %d\n",S->S_no_students);
                    S->Root = Delete_Class(S->Root,temp); //always recieve in School root because if there is a new root after delete
                    S->no_classes--;
                    printf("Now no of Classes in School is : %d",S->no_classes);
                    printf("\n=======================================\n");
                }
            break;
            }
        case PRINT_CLASS://semi
            {
                printf("Enter The Index of Class\n\a");
                scanf("%d",&temp);
                C = searchClass(S->Root,temp);  //Binary search
                if(C == NULL){printf("Class not found\n\a");}
                else
                {
                    if(C->pHead != NULL)
                    {
                        Print_Class(C);
                    }
                    else{printf("Class is Empty\n");} // avoid crash
                }
            break;
            }
        case EDIT_CLASS_SCORE ://done
            {
                printf("Enter The Index of Class\n\a");
                scanf("%d",&temp);
                C = searchClass(S->Root,temp);  //Binary search
                if(C == NULL){printf("Class not found\n\a");}
                else
                {
                    if(C->pHead != NULL)
                    {
                        Edit_Class_Score(C);
                    }
                    else{printf("Class is Empty\n");} // avoid crash
                }
            break;
            }
        case CLASS_RANK ://5
           {
                printf("Enter The Index of Class\n\a");
                scanf("%d",&temp);
                C = searchClass(S->Root,temp);  //Binary search
                if(C == NULL){printf("Class not found\n\a");}
                else
                {
                    if(C->pHead != NULL)
                    {
                        //Rank_Class(C);
                    }
                    else{printf("Class is Empty\n");} // avoid crash
                }
            break;
           }
        case ENTER_CLASS ://done
            {
                printf("Enter The Index of Class\n\a");
                scanf("%d",&temp);
                C = searchClass(S->Root,temp);  //Binary search
                if(C == NULL){printf("Class not found\n\a");}
                else {Class_Enter(S,C);}
            break;
            }
        case SCHOOL_RANK ://7
           {
                if(S->Root != NULL)
                {
                    //School_Rank(S);
                }
                else{printf("School is Empty\n");} // avoid crash
            break;
           }
        case EXIT_SCHOOL ://8
                printf("EXIT_FROM_SCHOOL\n\a");
            break;
        default:
                printf("Wrong Choice\n\a");
        }
        if(choice == EXIT_SCHOOL){break;}
    }
}
