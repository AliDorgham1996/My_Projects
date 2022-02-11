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
    for (j = low; j <= high - 1; j++)
    {
        if( strcmp ( arr[j]->Entry->Name.first_name , pivot->Entry->Name.first_name ) > 0 )
        {
           continue;
        }
        else if( strcmp ( arr[j]->Entry->Name.first_name , pivot->Entry->Name.first_name ) == 0 )
        {
            if( strcmp ( arr[j]->Entry->Name.middle_name , pivot->Entry->Name.middle_name ) > 0 )
            {
                continue;
            }
            else if( strcmp ( arr[j]->Entry->Name.middle_name , pivot->Entry->Name.middle_name ) == 0 )
            {
                if( strcmp ( arr[j]->Entry->Name.last_name , pivot->Entry->Name.last_name ) > 0 )
                {
                    continue;
                }
                else if( strcmp ( arr[j]->Entry->Name.last_name , pivot->Entry->Name.last_name ) == 0 )
                {
                    if( strcmp ( arr[j]->Entry->id , pivot->Entry->id ) > 0 )
                    {
                        continue;
                    }
                }
            }
        }
        i++;
        swap(&arr[i], &arr[j]);
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
