#include "structure.h"


static void swap(SubBuffer* a, SubBuffer* b);
static void heapSort(SubBuffer* arr, s32 n);
static void heapify(SubBuffer* arr, s32 n, s32 i);


void SubjectSort(Buffer* arr,SubBuffer* A ,s32 subject ,s32 size)
{
    s32 i;
    for(i=0; i<size ;i++)
    {
        switch(subject)
        {
            case C_Programming  :{*A[i] = arr[i]->Entry->Subjects.c_programming;}
                break;
            case Data_Structure :{*A[i] = arr[i]->Entry->Subjects.data_structure;}
                break;
            case Algorithms     :{*A[i] = arr[i]->Entry->Subjects.algorithms;}
                break;
            case Embedded_C     :{*A[i] = arr[i]->Entry->Subjects.embedded_c;}
                break;
            case SUM_SUBJECTS   :{*A[i] = arr[i]->Entry->Subjects.subjects_Sum;}
                break;
        }
    }
    heapSort(A,size);
}

static void heapSort(SubBuffer* arr, s32 n)
{
    s32 i;
    for (i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    for (i = n - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

static void heapify(SubBuffer* arr, s32 n, s32 i)
{
    s32 largest = i;
    s32 l = (2 * i) + 1;
    s32 r = (2 * i) + 2;
    if (l < n && (*arr[l]) > (*arr[largest]))
    {
        largest = l;
    }
    if (r < n && (*arr[r]) > (*arr[largest]))
    {
        largest = r;
    }
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

static void swap(SubBuffer* a, SubBuffer* b)
{
    s32 t = *a;
    *a = *b;
    *b = t;
}
