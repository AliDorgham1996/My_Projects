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
    printf("1-New Class\t\t2-Delete Class\n3-Print Class\t\t4-Edit Class Score\n5-Rank Class\t\t6-Enter Class\n7-School Rank\t\t8-Exit School\a");
    printf("\n===================================\n");
}

static void CLASS_menu(void)
{
    printf("\n===================================\n");
    printf("Please Enter your choice\n");
    printf("1-New Student\t\t\t2-Delete Student\n3-Print Data Student\t\t4-Edit Data Student\n5-Print Score Student\t\t6-Edit Score\n7-Exit Class\n\a");
    printf("\n===================================\n");
}

static void SUBJECT_menu(void)
{
    printf("\n===================================\n");
    printf("Please Enter your choice\n");
    printf("1-C Programming\t\t2-Data Structure\n3-Algorithms\t\t4-Embedded C\n\a");
    printf("\n===================================\n");
}

static void PRINT_menu(void)
{
    printf("\n===================================\n");
    printf("Please Enter your choice\n");
    printf("1-BY ID\t\t2-BY NAME\n3-BY SCORE\t4-BY INDEX\n");
    printf("\n===================================\n");
}
