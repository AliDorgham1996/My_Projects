#include <stdio.h>  // NULL , printf();
#include "structure.h"  // School
#include "ENUMS.h"  // greeting function

//Extern variable
extern void (*greeting_arr[])(void);
//Extern functions
extern void Greeting (void(*)(void));
extern void School_Fun(School*);        //SCHOOL.c
extern void school_destroy(School *);   //DESTROY.c
extern void School_init(School *);  //INITIALIZATION.c

//precaution : there exists a School , no need to be inititialized
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
        school_destroy(S);
    }
    Greeting(greeting_arr[GOODBYEAPP]); //Good bye
}

