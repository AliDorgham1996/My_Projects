#ifndef ENUMS_H_INCLUDED
#define ENUMS_H_INCLUDED


#define SCHOOL_MENU    0
#define CLASS_MENU     1
#define SUBJECT_MENU   2
#define PRINT_MENU     3
#define WELCOMEAPP     0
#define WELCOMESCHOOL  1
#define WELCOMECLASS   2
#define GOODBYEAPP     3

typedef enum S_Menu
{
    NEW_CLASS          = 1,
    DELETE_CLASS       = 2,
    PRINT_CLASS_DATA   = 3,
    PRINT_CLASS_SCORE  = 4,
    EDIT_CLASS_SCORE   = 5,
    CLASS_RANK         = 6,
    ENTER_CLASS        = 7,
    EXIT_SCHOOL        = 8
}S_Menu;

typedef enum C_Menu
{
    NEW_STUDENT         = 1,
    DELETE_STUDENT      = 2,
    PRINT_DATA_STUDENT  = 3,
    EDIT_DATA_STUDENT   = 4,
    PRINT_SCORE_STUDENT = 5,
    EDIT_SCORE_STUDENT  = 6,
    EXIT_CLASS          = 7
}C_Menu;


typedef enum Subjects_Menu
{
    C_Programming  = 1,
    Data_Structure = 2,
    Algorithms     = 3,
    Embedded_C     = 4
}Subjects_Menu;

#endif // ENUMS_H_INCLUDED
