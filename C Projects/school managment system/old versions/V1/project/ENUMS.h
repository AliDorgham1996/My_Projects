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
    NEW_CLASS     = 1,
    DELETE_CLASS  = 2,
    PRINT_CLASS   = 3,
    CLASS_SCORE   = 4,
    RANK_CLASS    = 5,
    ENTER_CLASS   = 6,
    EXIT_SCHOOL   = 7
}S_Menu;

typedef enum C_Menu
{
    NEW_STUDENT    = 1,
    DELETE_STUDENT = 2,
    STUDENT_PRINT  = 3,
    STUDENT_EDIT   = 4,
    RANK_PRINT     = 5,
    EDIT_SCORE     = 6,
    EXIT_CLASS     = 7
}C_Menu;


#endif // ENUMS_H_INCLUDED
