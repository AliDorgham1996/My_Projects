#include "structure.h"
#include <stdio.h>

static void genrate_id (Student *);

void School_init(School *S)
{
    S->Root =NULL;
    S->no_classes =0;
    S->S_no_students=0;
}



void Class_init(School *S, Class *C)
{
    C->pHead = NULL;
    C->pTail = NULL;
    C->pLeft = NULL;
    C->pRight= NULL;
    C->C_no_students = 0;
    C->class_ID = S->no_classes++; // the first node witch by the way is the root of school : ID=key=0;
}


void Student_init(School *S,Class *C,Student *ST)
{
    ST->pNext = NULL;
    ST->pPrev = NULL;
    ST->index = C->C_no_students ++;
    S->S_no_students ++;

    printf("\n");

    //done
    //The NAME : First , Middle , Last
    printf("Name :\n");
    printf("Enter First Name\n");
    scanf("%s",ST->Entry->Name.first_name);
    printf("Enter Middle Name\n");
    scanf("%s",ST->Entry->Name.middle_name);
    printf("Enter Last Name\n");
    scanf("%s",ST->Entry->Name.last_name);
    //done
    //The BIRTHDAY : DD , MM , YYYY
    printf("Birthday :\n");
    printf("Enter Day\n");
    scanf("%d",&ST->Entry->Birth_day.day);
    printf("Enter Month\n");
    scanf("%d",&ST->Entry->Birth_day.month);
    printf("Enter Year\n");
    scanf("%d",&ST->Entry->Birth_day.year);
    //done
    //The Address : Street , city , country
    printf("Address :\n");
    printf("Enter Street No\n");
    scanf("%d",&ST->Entry->Address.street_no);
    printf("Enter Street Name\n");
    scanf("%s",ST->Entry->Address.street_name);
    printf("Enter City Name\n");
    scanf("%s",ST->Entry->Address.city);
    printf("Enter Government\n");
    scanf("%s",ST->Entry->Address.government);
    //done
    //The Phone Number
    printf("Enter phone Number : +20 1234567890 \n");
    scanf("%[^\n]%*c",ST->Entry->phone_number);  // to take space in consideration !
    //ID
    genrate_id (ST);
    printf("The Generated ID : %s\n",ST->Entry->id);
}

static void genrate_id (Student * N)
{
    //IDSIZE = 15
    N->Entry->id[0] = '2';
    N->Entry->id[1] = '0';
    N->Entry->id[2] = '2';
    N->Entry->id[3] = '1';

    N->Entry->id[4] = N->Entry->Name.first_name[0];
    N->Entry->id[5] = N->Entry->Name.middle_name[0];
    N->Entry->id[6] = N->Entry->Name.last_name[0];

    N->Entry->id[7] = (N->Entry->Birth_day.day)<9?(N->Entry->Birth_day.day) : 'Z';
    N->Entry->id[8] = (N->Entry->Birth_day.month);
    N->Entry->id[9] = (N->Entry->Birth_day.year)>=2000? ((N->Entry->Birth_day.year)-2000) : 'z';

    N->Entry->id[10] = N->Entry->phone_number[0];
    N->Entry->id[11] = N->Entry->phone_number[1];
    N->Entry->id[12] = N->Entry->phone_number[2];
    N->Entry->id[13] = N->Entry->phone_number[3];
    N->Entry->id[14] = '\0';
}
