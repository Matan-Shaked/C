/*************************
* Test File: STRINGS EXERCISES Module
* Author: Matan Shaked
* Last update: 07/09/26
**************************/
/********************************************************* Standard libraries */
#include <stdio.h> /*printf*/

/********************************************************* Private libraries / Headers */
#include "strings_exercises.h" /*header*/

/******************************************************************* Define's */
#define COLOR_GREEN  "\033[0;32m"
#define COLOR_RED    "\033[0;31m"
#define COLOR_RESET  "\033[0m"

#define TEST_ASSERT(expr, test_name) \
    do { \
        if (expr) \
        { \
            printf(COLOR_GREEN "[PASS]" COLOR_RESET " %s\n", test_name); \
        } \
        else \
        { \
            printf(COLOR_RED "[FAIL]" COLOR_RESET " %s (line %d)\n", test_name, __LINE__); \
        } \
    } \
    while (0)

/************************************************************* Main functions */
int main(void)
{
    /* --- setup --- */
    char* str1 = "Matan";
    char* str2 = "MataM";
    char* str3 = "Matam";
    char* str4 = "A1B1C1B1A";
    char* str5 = "";
    char* str6 = "-9-";
    char str7[200] = "     Matan          is          in    the house     today";

    /* --- tests --- */
    printf("--- Tests on Palindrome ---\n");
    TEST_ASSERT(0 == IsPalindrome(str1), "test on NOT palindrome");
    TEST_ASSERT(1 == IsPalindrome(str2), "test on palindrome");
    TEST_ASSERT(0 == IsPalindrome(str3), "test on NOT palindrome because of case "
                                        "sensitive");
    TEST_ASSERT(1 == IsPalindrome(str4), "test on palindrome of mix between "
                                        "leters and digits");
    TEST_ASSERT(1 == IsPalindrome(str5), "test on palindrome for an empty string");
    TEST_ASSERT(1 == IsPalindrome(str6), "test on palindrome of mix between "
                                        "signs and digits");
    printf("\n");

    printf("--- Tests on SevenBoom ---\n");
    printf("--- Tests on SevenBoom from -10 to 10 ---\n");
    SevenBoom(-10, 10);
    printf("--- Tests on SevenBoom from -10 to 0 ---\n");
    SevenBoom(-10, 0);
    printf("--- Tests on SevenBoom from 0 to 10 ---\n");
    SevenBoom(0, 10);
    printf("--- Tests on SevenBoom from -10 to 20 ---\n");
    SevenBoom(-10, 20);
    printf("--- Tests on SevenBoom from 0 to 0 ---\n");
    SevenBoom(0, 1);
        printf("--- Tests on SevenBoom from -20 to 20 ---\n");
    SevenBoom(-20, 20);

    printf("\n");

    printf("--- Tests on Clean whitespaces from string ---\n");
    printf("Before parsing the string: %s\n", str7);
    CleanWhitespaces(str7);
    printf("After parsing the string: %s\n", str7);
    printf("\n");

    return 0;
}

