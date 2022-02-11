#include "structure.h"


static void merge(Buffer* arr, s32 l, s32 m, s32 r);


void mergeSort(Buffer* arr, s32 l, s32 r)
{
    if (l < r)
    {
        s32 m = (l+(r-l))/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

static void merge(Buffer* arr, s32 l, s32 m, s32 r)
{
    s32 i, j,k=1;
    s32 n1 = m - l + 1;
    s32 n2 = r - m;
    Buffer* L = (Buffer*)malloc(sizeof(Buffer)*n1);
    Buffer* R = (Buffer*)malloc(sizeof(Buffer)*n2);
    for (i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
    }
    i = j = 0;
    u8 * S1,S2;
    S1 = L[i]->Entry->id;
    S2 = R[j]->Entry->id;
    while (i < n1 && j < n2)
    {
        if(strcmp( S1 , S2 ) <= 0 )
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
    free(L);
    free(R);
}
