/*************************
* Source File: STRINGS Module
* Author: Matan Shaked
* Last update: 30/08/26
**************************/
/********************************************************* Standard libraries */
#include <assert.h> /*assert*/
/******************************************************************* Header's */
#include "strings.h"
/********************************************************************* Structs*/
/********************************************************************* Enum's */
/****************************************************************** Typedef's */
/*********************************** Forward declarations of helper functions */
/************************************************************* Main functions */
size_t StrLen(const char* str)
{
    size_t len = 0;
    
    assert(NULL != str);

    for (len = 0; '\0' != *str; ++len)
    {
        ++str;
    }

    return len;
}

int StrCmp(const char* str1, const char* str2)
{   
    assert(NULL != str1);
    assert(NULL != str2);

    while (*str1 == *str2 && '\0' != *str1)
    {
        ++str1;
        ++str2;
    }

    return *str1 - *str2;
}

int StrNCmp(const char* str1, const char* str2, size_t size)
{
    assert(NULL != str1);
    assert(NULL != str2);

    if (0 == size)
    {
        return 0;
    }
    
    while (*str1 == *str2 && '\0' != *str1 && size > 0)
    {
        ++str1;
        ++str2;
        --size;
    }

    return *str1 - *str2;
}


char* StrCpy(char* dest, const char* src)
{
    char* original_dest = dest;

    assert(NULL != dest);
    assert(NULL != src);

    while ('\0' != *src)
    {
        *dest++ = *src++;
    }

    *dest = '\0';

    return original_dest;
}

char* StrNCpy(char* dest, const char* src, size_t size)
{
    char* original_dest = dest;
    size_t i = 0;

    assert(NULL != dest);
    assert(NULL != src);

    for (i = 0; i < size; ++i)
    {
        *dest++ = *src++;
    }

    return original_dest;
}



/*********************************** Helper functions *************************/
