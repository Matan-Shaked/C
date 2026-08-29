/*************************
* Source File: POINTERS Module
* Author: Matan Shaked
* Last update: 29/08/26
**************************/
/********************************************************* Standard libraries */

/******************************************************************* Header's */
#include "pointers.h" /*header*/
/********************************************************************* Structs*/
/********************************************************************* Enum's */
/****************************************************************** Typedef's */
/*********************************** Forward declarations of helper functions */
/************************************************************* Main functions */
void SwapInts(int* a, int* b)
{
    int temp = 0;

    temp = *a;
    *a = *b;
    *b = temp;
}

void CopyArray(const void* src, size_t size, void* dest)
{
    size_t i = 0;
    char* byte_to_read = (char*)src;
    char* byte_to_write = (char*)dest;

    for (i = 0; i < size; ++i)
    {
        *byte_to_write++ = *byte_to_read++;
    }
}

void SwapSizeT(size_t* a, size_t *b)
{
    size_t temp = 0;

    temp = *a;
    *a = *b;
    *b = temp;
}

void SwapSizeTPointers(size_t** a, size_t** b)
{
    SwapSizeT(*a, *b);
}


/*********************************** Helper functions *************************/
