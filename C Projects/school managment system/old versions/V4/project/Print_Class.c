#include "structure.h"


//static global variable
static Buffer* Wrapper(Buffer*(*)(Buffer*,s32),Buffer*,s32);
//extern functions
extern void Print_Score_Student(Student* ST ,s32 subject ,s32 choice);
extern void Print_Data_Student(Student* ST , s32 choice); // choice == TABLE
extern void mergeSort(Buffer*,s32,s32);                                // merge sort
extern void quickSort(Buffer* arr, s32 low, s32 high);                 // quick sort
extern void SubjectSort(Buffer* arr,SubBuffer* A ,s32 subject ,s32 n); // heap sort
//static functions
static void Get_Buffer (Class * C , Buffer * B); //done
static void print_Buffer(Buffer* B);
static void print_Score(SubBuffer* B,s32 subject,s32 size);
static Buffer* Sort_ID    (Buffer*,s32 size);
static Buffer* Sort_Name  (Buffer*,s32 size);
//////////////////////////////////////////////////////////////////////////////


//print class
void Print_Class(Class* C)// print all the class due to id==Random or name==Alphabetical or index==Queue
{
    s32 choice;
    Main_Menu (menu_arr[PRINT_MENU]);
    scanf("%d",&choice);
    Buffer* (*Sort_arr[])(Buffer*,s32) = {Sort_ID,Sort_Name};
    Buffer* B = (Buffer*)malloc(sizeof(Buffer)*C->C_no_students);
    Get_Buffer(C,B);
    switch (choice)
    {
        case PRINT_ID :
            {
                print_Buffer(Wrapper(Sort_arr[ID],B,C->C_no_students));
            }
            break ;
        case PRINT_NAME :
            {
                print_Buffer(Wrapper(Sort_arr[NAME],B,C->C_no_students));
            }
            break ;
        case PRINT_SCORE :
            {
                s32 subject;
                Main_Menu (menu_arr[SUBJECT_MENU]);
                scanf("%d",&subject);
                SubBuffer* A = (SubBuffer*)malloc(C->C_no_students*sizeof(SubBuffer));
                SubjectSort(B,A,subject,C->C_no_students);
                print_Score(A,subject,C->C_no_students);
                free(A);
            }
            break ;
        case PRINT_INDEX :
            {
                print_Buffer(B);
            }
            break ;
    }
    free(B);
}

static void Get_Buffer (Class * C , Buffer * B)
{
    Student * ST = C->pHead;
    s32 i = 0;
    while(ST)
    {
        B[i++] = ST;
        ST = ST->pNext;
    }
}

static Buffer* Wrapper (Buffer*(*fun)(Buffer*,s32), Buffer * B,s32 size)
{
    return fun(B,size);
}

static void print_Buffer (Buffer* B)
{
    printf("INDEX\t\t   ID   \t\tNAME\n\n");
    while(*B)
    {
        Print_Data_Student(*B,TABLE);
        *B = (*B)->pNext ;
    }
}

static void print_Score (SubBuffer* A,s32 subject,s32 size)
{
    switch (subject)
    {
    case C_Programming  : {printf("Class Scores of C Programming\n\a");}
        break;
    case Data_Structure : {printf("Class Scores of Data Structure\n\a");}
        break;
    case Algorithms     : {printf("Class Scores of Algorithms\n\a");}
        break;
    case Embedded_C     : {printf("Class Scores of Embedded C\n\a");}
        break;
    }
    s32 i;
    for(i=0 ; i<size ;i++)
    {
        printf("%d\n",*A[i]);
    }
}

static Buffer* Sort_ID (Buffer* B,s32 size)
{
    mergeSort(B,0,size-1);
    return B;
}

static Buffer* Sort_Name (Buffer* B,s32 size)
{
    quickSort(B,0,size-1);
    return B;
}
