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
/*********************************** Helper functions *************************/
