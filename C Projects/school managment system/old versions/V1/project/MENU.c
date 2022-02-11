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
    printf("1-NEW_CLASS\n2-DELETE_CLASS\n3-PRINT_CLASS\n4-CLASS_SCORE\n5-RANKS_CLASS\n6-ENTER_CLASS\n7-EXIT_SCHOOL\n");
    printf("\n===================================\n");
}


static void CLASS_menu(void)
{
    printf("\n===================================\n");
    printf("Please Enter your choice\n");
    printf("1-NEW_STUDENT\n2-DELETE_STUDENT\n3-STUDENT_PRINT\n4-STUDENT_EDIT\n5-RANK_PRINT\n6-EDIT_SCORE\n7-EXIT_CLASS\n");
    printf("\n===================================\n");
}


static void SUBJECT_menu(void)
{
    printf("\n===================================\n");
    printf("Please Enter your choice\n");
    printf("1-C_Programming\n2-Data_Structure\n3-Algorithms\n4-Embedded_C\n");
    printf("\n===================================\n");
}


static void PRINT_menu(void)
{
    printf("\n===================================\n");
    printf("Please Enter your choice\n");
    printf("1-BY NAME\n2-BY ID\n3-BY index\n");
    printf("\n===================================\n");
}
