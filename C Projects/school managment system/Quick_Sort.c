#include "structure.h"

static s32 partition (Buffer* arr, s32 low, s32 high);
static void swap(Buffer* a, Buffer* b);

void quickSort(Buffer* arr, s32 low, s32 high)
{
    if (low < high)
    {
        s32 pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

static s32 partition (Buffer* arr, s32 low, s32 high)
{
    Buffer pivot = arr[high];
    s32 j, i = (low - 1);
    u8 * S1,S2;
    for (j = low; j <= high - 1; j++)
    {
        S1 = arr[j]->Entry->Name.first_name;
        S2 = pivot->Entry->Name.first_name ;
        if( strcmp ((u8*) S1 ,(u8*) S2 ) < 0 )
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

static void swap(Buffer* a, Buffer* b)
{
    Buffer t = *a;
    *a = *b;
    *b = t;
}
