#include "structure.h"
#include <stdlib.h>
#include <stdio.h>


static SchoolRootPtr minValueNode(SchoolRootPtr C);

extern void class_destroy(Class *);


// Precautions : School exists
// Post : return new node replacing the deleted one
SchoolRootPtr Delete_Class(SchoolRootPtr root, s32 index) // SchoolRootPtr = Class *
{
    if (root == NULL){return root;} //0- if the school is empty ,
    if (index < root->class_ID) //1- first reach to the least leaf on the left
    {
        root->pLeft = Delete_Class(root->pLeft, index);
    }
    else if (index > root->class_ID) //5- reach to the lest right back from the other left child
    {
        root->pRight = Delete_Class(root->pRight, index);
    }
    else
    {
        SchoolRootPtr temp = NULL; // avoid wild pointer
        if (root->pLeft == NULL) //2- reach left leaf node ,6- the return form last right
        {
            temp = root->pRight;
            class_destroy(root); // first, free(all Student)
            free(root); //3- delete the least left leaf
            return temp; //4- return with the right child to start delete again
        }
        else if (root->pRight == NULL) // 7- reach right leaf node
        {
            temp = root->pLeft;
            class_destroy(root); // first, free(all Students)
            free(root); //8- delete the least right leaf
            return temp; //9- return to the root
        }
        temp = minValueNode(root->pRight); //return with least left leaf of parent
        root->class_ID = temp->class_ID ;//save data
        root->pHead    = temp->pHead ;  //connect new list with old list (swapping with ref)
        root->pTail    = temp->pTail ;  //connect new list with old list (swapping with ref)
        root->C_no_students = temp->C_no_students; //save data
        root->pRight   = Delete_Class(root->pRight, temp->class_ID); //repeat the whole operation to re-organize childrens under parent to assign new parent of two childs
    }
    return root; //replacing the old node
}



static SchoolRootPtr minValueNode(SchoolRootPtr C)
{
    SchoolRootPtr current = C;
    while (current && current->pLeft != NULL)
    {
        current = current->pLeft;
    }
    return current; //return with least left leaf
}
