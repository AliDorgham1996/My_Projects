#include "structure.h"


extern void School_Fun(School*);        //SCHOOL.c
extern void school_destroy(SchoolRootPtr);   //DESTROY.c
extern void School_init(School *);  //INITIALIZATION.c

void App(School* S)
{
    School_init(S);     // initiate the only school : in the main !
    Greeting(greeting_arr[WELCOMEAPP]); //welcome
    School_Fun(S);
}

void DestroyApp(School *S)
{
    if(S->Root==NULL)
    {
        printf("School was empty\n");
    }
    else
    {
        school_destroy(S->Root);
        printf("School has been destroyed\n");
    }
    Greeting(greeting_arr[GOODBYEAPP]); //Good bye
}
