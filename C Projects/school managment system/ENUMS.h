#ifndef ENUMS_H_INCLUDED
#define ENUMS_H_INCLUDED

#define ROOT_OF_SCHOOL 1

typedef enum ARRAYSIZE
{
    TABLE        = 1,
    CARD         = 2,
    NATIONALID   = 15,
    NAMESIZE     = 20,
    ADDRESSSIZE  = 20,
    PHONESIZE    = 15,
    IDSIZE       = 15
}ARRAYSIZE;

typedef enum GREETING_MENU
{
    WELCOMEAPP    = 0,
    WELCOMESCHOOL = 1,
    WELCOMECLASS  = 2,
    GOODBYEAPP    = 3
}G_Menu;

typedef enum MAIN_MENU
{
    SCHOOL_MENU  =  0,
    CLASS_MENU   =  1,
    SUBJECT_MENU =  2,
    PRINT_MENU   =  3
}M_Menu;

typedef enum School_Menu
{
    NEW_CLASS          = 1,
    DELETE_CLASS       = 2,
    PRINT_CLASS        = 3,
    EDIT_CLASS_SCORE   = 4,
    CLASS_RANK         = 5,
    ENTER_CLASS        = 6,
    SCHOOL_RANK        = 7,
    EXIT_SCHOOL        = 8
}School_Menu;

typedef enum CLass_Menu
{
    NEW_STUDENT         = 1,
    DELETE_STUDENT      = 2,
    PRINT_DATA_STUDENT  = 3,
    EDIT_DATA_STUDENT   = 4,
    PRINT_SCORE_STUDENT = 5,
    EDIT_SCORE_STUDENT  = 6,
    EXIT_CLASS          = 7
}Class_Menu;

typedef enum Print_Menu
{
    ID             = 0,
    NAME           = 1,
    PRINT_ID       = 1,
    PRINT_NAME     = 2,
    PRINT_SCORE    = 3,
    PRINT_INDEX    = 4
}P_Menu;

typedef enum Subjects_Menu
{
    C_Programming  = 1,
    Data_Structure = 2,
    Algorithms     = 3,
    Embedded_C     = 4,
    NO_SUBJECT     = 4,
    SUM_SUBJECTS   = 5
}Sub_Menu;

typedef enum TOP
{
    TOP_3   = 3,
    TOP_5   = 5,
    FIRST   = 0,
    SECOND  = 1,
    THIRD   = 2,
    FOURTH  = 3,
    FIFTH   = 4,
    SIXTH   = 5,
    SEVENTH = 6,
    EIGHTH  = 7,
    NINETH  = 8
}Top;

#endif // ENUMS_H_INCLUDED
