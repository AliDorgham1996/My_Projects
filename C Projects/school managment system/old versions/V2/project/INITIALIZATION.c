#include "structure.h"
#include <stdio.h>

static void genrate_id (Student *ST , s32 index);

void School_init(School *S)
{
    S->Root =NULL;
    S->no_classes =0;
    S->S_no_students=0;
}



void Class_init(Class *C, s32 ID)
{
    C->pHead = NULL;
    C->pTail = NULL;
    C->pLeft = NULL;
    C->pRight= NULL;
    C->class_ID = ID;
    C->C_no_students = 0;
}


void Student_init(Student *ST , s32 index)
{
    ST->pNext = NULL;
    ST->pPrev = NULL;
    printf("\n");
    //done
    //The NAME : First , Middle , Last
    printf("\n\t\tName\n\n\a");
    printf("Enter First Name\n\a");
    scanf("%s",ST->Entry->Name.first_name);
    printf("Enter Middle Name\n\a");
    scanf("%s",ST->Entry->Name.middle_name);
    printf("Enter Last Name\n\a");
    scanf("%s",ST->Entry->Name.last_name);
    //done
    //The BIRTHDAY : DD , MM , YYYY
    printf("\n\t\tBirthday\n\n\a");
    printf("Enter Day\n\a");
    scanf("%d",&ST->Entry->Birth_day.day);
    printf("Enter Month\n\a");
    scanf("%d",&ST->Entry->Birth_day.month);
    printf("Enter Year\n\a");
    scanf("%d",&ST->Entry->Birth_day.year);
    //done
    //The Address : Street , city , country
    printf("\n\t\tAddress\n\n\a");
    printf("Enter Street No\n\a");
    scanf("%d",&ST->Entry->Address.street_no);
    printf("Enter Street Name\n\a");
    scanf("%s",ST->Entry->Address.street_name);
    printf("Enter City Name\n\a");
    scanf("%s",ST->Entry->Address.city);
    printf("Enter Government\n\a");
    scanf("%s",ST->Entry->Address.government);
    //done
    //The Phone Number
    printf("\nEnter phone Number like : +201234567890 \n\a");
    scanf("%s",ST->Entry->phone_number);  // to take space in consideration !
    //ID
    genrate_id (ST , index);
    printf("\n=======================================\n\a");
    printf("\n\tThe Generated ID : %s\n",ST->Entry->id);
}

static void genrate_id (Student * ST , s32 index)
{
    //IDSIZE = 15
    s8 i;
    i = '0' + ((index%10000)/1000) ;
    ST->Entry->id[0] = i;
    i = '0' + ((index%1000)/100) ;
    ST->Entry->id[1] = i;
    i = '0' + ((index%100)/10) ;
    ST->Entry->id[2] = i;
    i = '0' + ((index%10)/1) ;
    ST->Entry->id[3] = i;

    ST->Entry->id[4] = ST->Entry->Name.first_name[0];
    ST->Entry->id[5] = ST->Entry->Name.middle_name[0];
    ST->Entry->id[6] = ST->Entry->Name.last_name[0];

    ST->Entry->id[7] = ((ST->Entry->Birth_day.day) < 27) ? (((ST->Entry->Birth_day.day)-1)+'A' ) : (((ST->Entry->Birth_day.day)-26) + '0');
    ST->Entry->id[8] = ((ST->Entry->Birth_day.month) < 10) ? ((ST->Entry->Birth_day.month)+'0' ) : (((ST->Entry->Birth_day.month)-10) + 'a');
    i = '0' + (((ST->Entry->Birth_day.year)%100)/10) ;
    ST->Entry->id[9] = i;
    i = '0' + (((ST->Entry->Birth_day.year)%10)/1) ;
    ST->Entry->id[10]= i;

    ST->Entry->id[11] = ST->Entry->phone_number[4];
    ST->Entry->id[12] = ST->Entry->phone_number[11];
    ST->Entry->id[13] = ST->Entry->phone_number[12];
    ST->Entry->id[14] = '\0';
}