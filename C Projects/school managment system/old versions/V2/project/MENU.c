#include <stdio.h>

static void SCHOOL_menu (void);
static void CLASS_menu(void);
static void SUBJECT_menu(void);
static void PRINT_menu(void);

void (*menu_arr[])(void) = {SCHOOL_menu,CLASS_menu,SUBJECT_menu,PRINT_menu};  // global variable

void Main_Menu (void(*fun)(void))
{
    fun();
}


static void SCHOOL_menu(void)
{
    printf("\n===================================\n");
    printf("Please Enter your choice\n");
    printf("1-NEW_CLASS\t\t2-DELETE_CLASS\n3-PRINT_CLASS\t\t4-CLASS_SCORE\n5-RANKS_CLASS\t\t6-ENTER_CLASS\n7-EXIT_SCHOOL\n\a");
    printf("\n===================================\n");
}


static void CLASS_menu(void)
{
    printf("\n===================================\n");
    printf("Please Enter your choice\n");
    printf("1-NEW_STUDENT\t\t2-DELETE_STUDENT\n3-STUDENT_PRINT\t\t4-STUDENT_EDIT\n5-RANK_PRINT\t\t6-EDIT_SCORE\n7-EXIT_CLASS\n\a");
    printf("\n===================================\n");
}


static void SUBJECT_menu(void)
{
    printf("\n===================================\n");
    printf("Please Enter your choice\n");
    printf("1-C_Programming\t\t2-Data_Structure\t\t3-Algorithms\n4-Embedded_C\n\a");
    printf("\n===================================\n");
}


static void PRINT_menu(void)
{
    printf("\n===================================\n");
    printf("Please Enter your choice\n");
    printf("1-BY NAME\n2-BY ID\n3-BY index\n");
    printf("\n===================================\n");
}
