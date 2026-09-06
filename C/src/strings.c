/*************************
* Source File: STRINGS Module
* Author: Matan Shaked
* Last update: 30/08/26
**************************/
/********************************************************* Standard libraries */
#include <assert.h> /*assert*/
#include <ctype.h> /*tolower*/
#include <stdlib.h> /*malloc*/
#include <string.h> /*strlen.h*/

/******************************************************************* Header's */
#include "strings.h" /*header*/

/******************************************************************* Define's */
/********************************************************************* Structs*/
/********************************************************************* Enum's */
/****************************************************************** Typedef's */
typedef enum 
{
    NOT_DELIMITER,
    DELIMITER
} delim_t;
/*********************************** Forward declarations of helper functions */
static int IsDelimiter(char c, const char* delim);

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
        --size;
        if (0 == size)
        {
            return *str1 - *str2;        
        }

        ++str1;
        ++str2;

    }

    return *str1 - *str2;
}

int StrCaseCmp(const char* str1, const char* str2)
{
    assert(NULL != str1);
    assert(NULL != str2);

    while (tolower(*str1) == tolower(*str2) && '\0' != *str1)
    {
        ++str1;
        ++str2;
    }

    return tolower(*str1) - tolower(*str2);
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
    size_t src_len = strlen(src); 

    assert(NULL != dest);
    assert(NULL != src);

    for (i = 0; i < size && i < src_len; ++i)
    {
        *dest++ = *src++;
    }

    while (i < size)
    {
        *dest++ = '\0';
        ++i;
    }

    return original_dest;
}

char* StrChr(const char* str, int c)
{
    assert(NULL != str);

    while ('\0' != *str && c != *str)
    {
        ++str;
    }

    return (*str == c) ? (char*)str : NULL;
}

char* StrDup(const char* str)
{
    char* str_dup = NULL;
    char* str_dup_runner = NULL; 
    assert(NULL != str);
    
    str_dup = (char*)malloc(strlen(str) + 1);
    str_dup_runner = str_dup;
    if (NULL == str_dup)
    {
        return NULL;
    }

    while ('\0' != *str)
    {
        *str_dup_runner++ = *str++;
    }

    *str_dup_runner = '\0';

    return str_dup;
}

char* StrCat(char* dest, const char* src)
{
    char* dest_runner = dest;

    assert(NULL != dest);
    assert(NULL != src);

    while ('\0' != *dest_runner)
    {
        ++dest_runner;
    }

    while('\0' != *src)
    {
        *dest_runner++ = *src++; 
    }

     *dest_runner = '\0';

    return dest;
}

char* StrNCat(char* dest, const char* src, size_t size)
{
    char* dest_runner = dest;

    assert(NULL != dest);
    assert(NULL != src);

    while ('\0' != *dest_runner)
    {
        ++dest_runner;
    }

    while('\0' != *src && size > 0)
    {
        *dest_runner++ = *src++; 
        --size;
    }

    *dest_runner = '\0';

    return dest;
}

char* StrStr(const char* haystack, const char* needle)
{
    
    char* needle_runner = (char*)needle;
    char* haystack_runner = (char*)haystack;
    char* substring_potenial = NULL;
    
    if('\0' == *needle)
    {
        return (char*)haystack;
    }

    while (*needle_runner != *haystack_runner && '\0' != *haystack_runner)
    {
        ++haystack_runner;
    }
    
    substring_potenial = haystack_runner;

    while ('\0' != *haystack_runner)
    {
        haystack_runner = substring_potenial;
        while(*needle_runner == *haystack_runner && '\0' != *needle_runner)
        {
            ++needle_runner;
            ++haystack_runner;

            if('\0' == *needle_runner)
            {
                return substring_potenial;
            }
        }

        needle_runner = (char*)needle;
        ++substring_potenial;
    }

    return NULL;
}

size_t StrSpn(const char* str, const char* accept)
{
    size_t counter = 0;
    const char* accept_start = accept;

    assert(NULL != str);
    assert(NULL != accept);

    if ('\0' == *accept)
    {
        return counter;
    }
    
    while ('\0' != *str)
    {
        accept = accept_start;
        
        while ('\0' != *accept)
        {
            if (*str == *accept)
            {
                ++counter;
                ++str;
                break;
            }

            ++accept;

            if ('\0' == *accept)
            {
                return counter;
            }
        }
        
    }


    return counter;
}

char* StrTok(char* str, const char* delim)
{
    static char* token_start = NULL;
    static char* token_runner = NULL;

    if (NULL != str)
    {
        token_start = str;
        token_runner = str;
    }

    token_start = token_runner; 

    if ('\0' != *token_runner)
    {
        while (DELIMITER == IsDelimiter(*token_runner, delim))
        {
            ++token_start;
            ++token_runner;
        }

        while (NOT_DELIMITER == IsDelimiter(*token_runner, delim))
        {
            ++token_runner;
            if ('\0' == *token_runner)
            {
                break;
            } 
        }

        if (DELIMITER == IsDelimiter(*token_runner, delim))
        {
            *token_runner = '\0';
            ++token_runner;
        }
        
        return token_start;
    }

    return NULL;
}
/*********************************** Helper functions *************************/
static int IsDelimiter(char c, const char* delim)
{
    while ('\0' != *delim)
    {
        if (*delim == c)
        {
            return DELIMITER;
        }

        ++delim;
    }

    return NOT_DELIMITER;
}