/*************************
* Test File: POINTERS Module
* Author: Matan Shaked
* Last update: 29/08/26
**************************/
/********************************************************* Standard libraries */
#include <stdio.h> /*printf*/
#include <stddef.h> /*size_t*/
#include <stdlib.h> /*malloc, free*/

/********************************************************* Private libraries / Headers */
#include "pointers.h" /*pointers API*/

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
    } while (0)

/************************************************************* Main functions */
int main(void)
{
    /* --- setup --- */
    size_t i = 0;
    int a = 1;
    int b = 2;
    int c = -3;
    int d = -4;
    int e = 10000000;
    int f = 0;
    char* str1 = "matan";
    char str2[10] = {0};
    int str4[6] = {0};
    int str5[6] = {0};
    size_t a1 = 1;
    size_t a2 = 2;
    size_t a3 = 0;
    size_t a4 = 100000;
    size_t b1 = 1;
    size_t b2 = 2;
    size_t* b1_ptr = &b1;
    size_t* b2_ptr = &b2;

    {
        static int s_i = 17; 
        int* ptr = &s_i;
        int i = 117;
        int* ptr2 = &i;
        int** ptr3 = &ptr2;
        int* ptr4 = (int *)malloc(sizeof(int));

        printf("%p static variable's int s_i address\n", (void *)ptr);
        printf("%p auto local variable's i address\n", (void *)ptr2);
        printf("%p auto local pointer to variable's ptr2 address\n",(void *)ptr3);
        printf("%p heap variable's address\n", (void *)ptr4);

        free(ptr4);
    }

    for (i = 0; i < (sizeof(str4) / sizeof(str4[0])); ++i)
    {
        str4[i] = i + 1;
    }

    SwapInts(&a, &b);
    SwapInts(&c, &d);
    SwapInts(&e, &f);
    CopyArray(str1, sizeof(str1), &str2);
    CopyArray(&str4, sizeof(str4), &str5);
    SwapSizeT(&a1, &a2);
    SwapSizeT(&a3, &a4);
    SwapSizeTPointers(&b1_ptr, &b2_ptr);

    /* --- tests --- */
    TEST_ASSERT(a == 2, "swapping positive values - first check");
    TEST_ASSERT(b == 1, "swapping positive values - second check");
    TEST_ASSERT(c == -4, "swapping negative values - first check");
    TEST_ASSERT(d == -3, "swapping negative values - second check");
    TEST_ASSERT(e == 0, "swapping zero with big value - first check");
    TEST_ASSERT(f == 10000000, "swapping zero with big value - second check");
    TEST_ASSERT(str2[0] == 'm', "copying array of chars from src to big enough dest - checking first element");
    TEST_ASSERT(str2[9] == '\0', "copying array of chars from src to big enough dest - checking last element");
    TEST_ASSERT(str5[0] == 1, "copying array of ints from src to big enough dest - checking first element");
    TEST_ASSERT(str5[5] == 6, "copying array of ints from src to big enough dest - checking last element");
    TEST_ASSERT(a1 == 2, "swapping size_t small values - first check");
    TEST_ASSERT(a2 == 1, "swapping size_t small values - second check");
    TEST_ASSERT(a3 == 100000, "swapping size_t big and zero values - first check");
    TEST_ASSERT(a4 == 0, "swapping size_t big and zero values - second check");
    TEST_ASSERT(*b1_ptr == 2, "swapping size_t pointers - first check");
    TEST_ASSERT(*b2_ptr == 1, "swapping size_t pointers - second check");

    return 0;
}
