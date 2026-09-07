/*************************
* Source File: STRINGS EXERCISES Module
* Author: Matan Shaked
* Last update: 07/09/26
**************************/
/********************************************************* Standard libraries */
#include <string.h> /*strlen*/
#include <stddef.h> /*size_t*/
#include <stdio.h> /*printf*/
#include <assert.h> /*assert*/

/******************************************************************* Header's */
#include "strings_exercises.h" /*header*/

/******************************************************************* Define's */
#define BOOM_INTEGER (7)
#define SPACE (32)
#define TAB (9)

/****************************************************************** Typedef's */
typedef enum 
{
    NOT_PALINDROME,
    PALINDROME
} palindrom_t;

typedef enum 
{
    NOT_CONTAIN_SEVEN,
    CONTAIN_SEVEN
} seven_boom_t;

typedef enum 
{
    NOT_WHITESPACE,
    WHITESPACE
} white_space_t;

/*********************************** Forward declarations of helper functions */
static int IsContainSeven(int num);
static int IsWhiteSpace(char c);
static void CleanTrailingWhiteSpaces(char* str);
static void CleanStartingWhiteSpaces(char* str);
static void CleanSequencedWhiteSpaces(char* str);

/************************************************************* Main functions */
int IsPalindrome(const char* str)
{
    size_t len = 0;
    size_t end = 0;
    size_t start = 0;

    assert(NULL != str);

    len = strlen(str);

    if (0 == len)
    {
        return PALINDROME;
    }

    end = len - 1;

    while (start < end)
    {
        if (*(str + start) != *(str + end))
        {
            return NOT_PALINDROME;
        }

        --end;
        ++start;
    }

    return PALINDROME;
}

void SevenBoom(int from, int to)
{
    int i = 0;

    for (i = from; i < to; ++i)
    {
        if (0 == i % BOOM_INTEGER)
        {
            printf("BOOM ");
            continue;
        }
        else if (0 != IsContainSeven(i))
        {
            printf("BOOM ");
            continue;
        }

        printf("%d ", i);
    }

    printf("\nFinished 7-BOOM session\n\n");
}

void CleanWhitespaces(char* str)
{
    CleanStartingWhiteSpaces(str);
    CleanTrailingWhiteSpaces(str);
    CleanSequencedWhiteSpaces(str);
}



/*********************************** Helper functions *************************/
static int IsContainSeven(int num)
{
    if(num < 0)
    {
        num *= -1;
    }
    
    while (num > 0)
    {
        if (BOOM_INTEGER == num % 10)
        {
            return CONTAIN_SEVEN;
        }

        num /= 10;
    }

    return NOT_CONTAIN_SEVEN;
}

static int IsWhiteSpace(char c)
{
    return (SPACE == c || TAB == c) ? WHITESPACE : NOT_WHITESPACE;
}

static void CleanTrailingWhiteSpaces(char* str)
{
    char* read = NULL;
    char* write = NULL;
    size_t len = strlen(str);
    size_t i = 0;
    
    assert(NULL != str);

    if (0 == len)
    {
        return;
    } 

    read = str + len - 1;
    i = len - 1;
    while (0 != IsWhiteSpace(*read) && i > 0)
    {
        --read;
        --i;
    }

    write = read + 1;
    *write = '\0';
}

static void CleanStartingWhiteSpaces(char* str)
{
    char* read = NULL;
    char* write = NULL;

    assert(NULL != str);

    read = str;
    while (0 != IsWhiteSpace(*read))
    {
        ++read;
    }

    write = str;
    while ('\0' != *read)
    {
        *write = *read;
        ++write;
        ++read;
    }

    *write = '\0';
}

static void CleanSequencedWhiteSpaces(char* str)
{
    char* read = NULL;
    char* write = NULL;

    assert(NULL != str);

    read = str;
    write = str; 
    
    while ('\0' != *read)
    {
        while ((NOT_WHITESPACE == IsWhiteSpace(*read) 
                    && '\0' != *read)
                || (WHITESPACE == IsWhiteSpace(*read) 
                    && NOT_WHITESPACE == IsWhiteSpace(*(read + 1))))
        {
            *write = *read;
            ++write;
            ++read;
        }

        while (WHITESPACE == IsWhiteSpace(*read) 
                && WHITESPACE == IsWhiteSpace(*(read + 1)))
        {
            ++read;
        }

        if('\0' != *read)
        {
            ++read;
            ++write;
        }
    }

    *write = '\0';
}