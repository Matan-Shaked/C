/*************************
* Test File: STRINGS Module
* Author: Matan Shaked
* Last update: 30/08/26
**************************/
/************************************************************* POSIX Define's */
#define _POSIX_C_SOURCE (200809L)

/********************************************************* Standard libraries */
#include <string.h> /*strlen, strcmp, strncmp, strchr, strdup*/
#include <strings.h> /*strcasecmp*/
#include <stdio.h> /*printf, NULL*/
#include <stdlib.h> /*free*/

/********************************************************* Private libraries / Headers */
#include "strings.h" /*header*/
/******************************************************************* Define's */
#define COLOR_GREEN  "\033[0;32m"
#define COLOR_RED    "\033[0;31m"
#define COLOR_RESET  "\033[0m"

#define TEST_ASSERT(expr, test_name) \
    do { \
        if (expr) { \
            printf(COLOR_GREEN "[PASS]" COLOR_RESET " %s\n", test_name); \
        } else { \
            printf(COLOR_RED "[FAIL]" COLOR_RESET " %s (line %d)\n", test_name, __LINE__); \
        } \
    } while (0)
/********************************************************************* Enum's */
/********************************************** Helper functions declerations */
/************************************************************* Main functions */
int main(void)
{
    /* --- setup --- */
    char* str1 = "matan";
    char str2[10] = "matan";
    char str3[] = {'m', 'a', 't', 'a', 'n', '\0'};
    char str4[] = {'\0'};
    char str5[] = "";
    char str6[] = "";
    char str7[] = "a";
    char str8[] = "A";
    char str9[] = "matan";
    char str10[] = {'m', 'a', 't', 'a', 'n', '\0'};
    char str11[] = "matann";
    char str12[] = "MATAN";
    char str13[] = "MaTan";
    char str14[] = "A1a2B3b4";
    char str15[] = "a1a2b3b4";
    char str16[] = "MATAN";
    char str17[] = "a1a2b3b4";
    const char str18[] = "please make a duplicate from me";
    char* str18_dup_a = NULL;
    char* str18_dup_b = NULL;
    const char str19[] = "100000000000000000001";
    char* str19_dup_a = NULL;
    char* str19_dup_b = NULL;
    const char str20[] = "";
    char* str20_dup_a = NULL;
    char* str20_dup_b = NULL;
    size_t str1_len_a = strlen(str1);
    size_t str1_len_b = StrLen(str1);
    size_t str2_len_a = strlen(str2);
    size_t str2_len_b = StrLen(str2);
    size_t str3_len_a = strlen(str3);
    size_t str3_len_b = StrLen(str3);
    size_t str4_len_a = strlen(str4);
    size_t str4_len_b = StrLen(str4);
    size_t str5_len_a = strlen(str5);
    size_t str5_len_b = StrLen(str5);
    int str_5_6_cmp_a = strcmp(str5, str6);
    int str_5_6_cmp_b = StrCmp(str5, str6);
    int str_6_7_cmp_a = strcmp(str6, str7);
    int str_6_7_cmp_b = StrCmp(str6, str7);
    int str_7_8_cmp_a = strcmp(str7, str8);
    int str_7_8_cmp_b = StrCmp(str7, str8);
    int str_9_10_cmp_a = strcmp(str9, str10);
    int str_9_10_cmp_b = StrCmp(str9, str10);
    int str_5_6_n_cmp_a = strncmp(str5, str6, 1);
    int str_5_6_n_cmp_b = StrNCmp(str5, str6, 1);
    int str_6_7_n_cmp_a = strncmp(str6, str7, 1);
    int str_6_7_n_cmp_b = StrNCmp(str6, str7, 1);
    int str_7_8_n_cmp_a = strncmp(str7, str8, 1);
    int str_7_8_n_cmp_b = StrNCmp(str7, str8, 1);
    int str_9_10_n_cmp_a = strncmp(str9, str10, 5);
    int str_9_10_n_cmp_b = StrNCmp(str9, str10, 5);
    int str_10_11_n_cmp_a = strncmp(str10, str11, 6);
    int str_10_11_n_cmp_b = StrNCmp(str10, str11, 6);
    int str_12_13_cmp_a = strcasecmp(str12, str13);
    int str_12_13_cmp_b = StrCaseCmp(str12, str13);
    int str_14_15_cmp_a = strcasecmp(str14, str15);
    int str_14_15_cmp_b = StrCaseCmp(str14, str15);
    int str_16_17_cmp_a = strcasecmp(str16, str17);
    int str_16_17_cmp_b = StrCaseCmp(str16, str17);
    char str1_cpy_dest_buffer[100] = "100001";
    char* str1_cpy_a = "Wonderfull day";
    char* str2_cpy_a = "12345";
    char str3_cpy_a[6] = "54321";
    char* str4_cpy_a = "";
    char str1_n_cpy_long_dest_buffer[100] = "100001";
    char str1_n_cpy_short_dest_buffer[4] = "100";
    char* str1_n_cpy_a = "Wonderfull day";
    char* str2_n_cpy_a = "12345";
    char* str3_n_cpy_a = "";

    /* --- tests --- */
    printf("--- Tests on StrLen ---\n");
    TEST_ASSERT(str1_len_a == str1_len_b, "testing on a pointer to string literal");
    TEST_ASSERT(str2_len_a == str2_len_b, "testing on a string");
    TEST_ASSERT(str3_len_a == str3_len_b, "testing on a char array");
    TEST_ASSERT(str4_len_a == str4_len_b, "testing on an empty string");
    TEST_ASSERT(str5_len_a == str5_len_b, "testing on a string that has only null-terminated char");
    printf("\n");

    printf("--- Tests on StrCmp ---\n");
    TEST_ASSERT(str_5_6_cmp_a == str_5_6_cmp_b, 
        "testing on an empty string");
    TEST_ASSERT(str_6_7_cmp_a == str_6_7_cmp_b, 
        "testing on empty string and non-empty string");
    TEST_ASSERT(str_7_8_cmp_a == str_7_8_cmp_b, 
        "testing on string with uppercase letter and with lowercase letter");
    TEST_ASSERT(str_9_10_cmp_a == str_9_10_cmp_b, 
        "testing on identical strings");
    printf("\n");

    printf("--- Tests on StrNCmp ---\n");
    TEST_ASSERT(str_5_6_n_cmp_a == str_5_6_n_cmp_b, "testing on an empty string");
    TEST_ASSERT(str_6_7_n_cmp_a == str_6_7_n_cmp_b, "testing on empty string and non-empty string");
    TEST_ASSERT(str_7_8_n_cmp_a == str_7_8_n_cmp_b, "testing on string with uppercase letter and with lowercase letter");
    TEST_ASSERT(str_9_10_n_cmp_a == str_9_10_n_cmp_b, 
        "testing on identical strings up to 5 first chars, and different only in the sixth char");
    TEST_ASSERT(str_10_11_n_cmp_a == str_10_11_n_cmp_b, 
        "testing on identical strings up to 5 first chars, and different only in the sixth char");
    printf("\n");

    printf("--- Tests on StrCaseCmp ---\n");
    TEST_ASSERT(str_12_13_cmp_a == str_12_13_cmp_b, "testing on identical strings that differs only by case");
    TEST_ASSERT(str_14_15_cmp_a == str_14_15_cmp_b, "testing on identical strings that differs only by case");
    TEST_ASSERT(str_16_17_cmp_a == str_16_17_cmp_b, "testing on different strings");
    printf("\n");

    printf("--- Tests on StrCpy ---\n");
    TEST_ASSERT(0 == StrCmp(str1_cpy_dest_buffer, "100001"), "testing the initial value of the destination buffer");
    TEST_ASSERT((0 == StrCmp(StrCpy(str1_cpy_dest_buffer, str1_cpy_a), str1_cpy_a)), 
                "testing the copy of long string literal to the destination buffer");
    TEST_ASSERT((0 == StrCmp(StrCpy(str1_cpy_dest_buffer, str2_cpy_a), str2_cpy_a)), 
                "testing the copy of short string literal of numbers to the destination buffer");
    TEST_ASSERT((0 == StrCmp(StrCpy(str1_cpy_dest_buffer, str3_cpy_a), str3_cpy_a)), 
                "testing the copy of short local string of numbers to the destination buffer");
    TEST_ASSERT((0 == StrCmp(StrCpy(str1_cpy_dest_buffer, str4_cpy_a), str4_cpy_a)), 
                "testing the copy of an empty string literal (only null terminate char) to the destination buffer");
    printf("\n");

    printf("--- Tests on StrNCpy ---\n");
    TEST_ASSERT(0 == StrCmp(str1_n_cpy_long_dest_buffer, "100001"), "testing the initial value of the long destination buffer");
    TEST_ASSERT(0 == StrCmp(str1_n_cpy_short_dest_buffer, "100"), "testing the initial value of the short destination buffer");
    TEST_ASSERT((0 == StrCmp(StrNCpy(str1_n_cpy_long_dest_buffer, str1_n_cpy_a, strlen(str1_n_cpy_a) + 1), str1_n_cpy_a)), 
                "testing the copy a source of string literal to the a bigger destination buffer");
    StrNCpy(str1_n_cpy_short_dest_buffer, str1_n_cpy_a, sizeof(str1_n_cpy_short_dest_buffer));
    TEST_ASSERT(str1_n_cpy_short_dest_buffer[0] == 'W', "testing the copy of source to smaller destination - first char");
    TEST_ASSERT(str1_n_cpy_short_dest_buffer[1] == 'o', "testing the copy of source to smaller destination - second char");
    TEST_ASSERT(str1_n_cpy_short_dest_buffer[2] == 'n', "testing the copy of source to smaller destination - third char");
    TEST_ASSERT(str1_n_cpy_short_dest_buffer[3] == 'd', "testing the copy of source to smaller destination - fourth char");
    TEST_ASSERT((0 == StrCmp(StrNCpy(str1_n_cpy_long_dest_buffer, str2_n_cpy_a, strlen(str2_n_cpy_a) + 1), str2_n_cpy_a)), 
                "testing the copy a source of string literal of numbers to the a bigger destination buffer");
    StrNCpy(str1_n_cpy_short_dest_buffer, str2_n_cpy_a, sizeof(str1_n_cpy_short_dest_buffer));
    TEST_ASSERT(str1_n_cpy_short_dest_buffer[0] == '1', "testing the copy of source to smaller destination - first char");
    TEST_ASSERT(str1_n_cpy_short_dest_buffer[1] == '2', "testing the copy of source to smaller destination - second char");
    TEST_ASSERT(str1_n_cpy_short_dest_buffer[2] == '3', "testing the copy of source to smaller destination - third char");
    TEST_ASSERT(str1_n_cpy_short_dest_buffer[3] == '4', "testing the copy of source to smaller destination - fourth char");
    TEST_ASSERT((0 == StrCmp(StrNCpy(str1_n_cpy_long_dest_buffer, str3_n_cpy_a, strlen(str3_n_cpy_a) + 1), str3_n_cpy_a)), 
                "testing the copy of an empty string literal (only null terminate char) to the destination buffer");
    TEST_ASSERT((0 == StrCmp(StrNCpy(str1_n_cpy_short_dest_buffer, str3_n_cpy_a, strlen(str3_n_cpy_a) + 1), str3_n_cpy_a)), 
                "testing the copy of an empty string literal (only null terminate char) to the destination buffer");
    printf("\n");

    printf("--- Tests on StrChr ---\n");
    TEST_ASSERT(0 == StrCmp(StrChr(str17, 'a'), strchr(str17, 'a')), 
                "testing on character that occurs more than once in the string");
    TEST_ASSERT(0 == StrCmp(StrChr(str17, '2'), strchr(str17, '2')), 
                "testing on character that occurs only once in the string");
    TEST_ASSERT(StrChr(str17, '5') == strchr(str17, '5') && NULL == StrChr(str17, '5'), 
                "testing on character that not occurs in the string");
    printf("\n");

    printf("--- Tests on StrDup ---\n");
    str18_dup_a = StrDup(str18);
    str18_dup_b = strdup(str18);
    str19_dup_a = StrDup(str19);
    str19_dup_b = strdup(str19);
    str20_dup_a = StrDup(str20);
    str20_dup_b = strdup(str20);
    TEST_ASSERT(0 == StrCmp(str18, str18_dup_a), 
                "testing duplication of string made of letters and spaces only");
    TEST_ASSERT(0 == StrCmp(str18_dup_a, str18_dup_b), 
                "testing duplication of my implementation vs. glibc's");
    TEST_ASSERT(0 == StrCmp(str19, str19_dup_a), 
                "testing duplication of string made of digits only");
    TEST_ASSERT(0 == StrCmp(str19_dup_a, str19_dup_b), 
                "testing duplication of my implementation vs. glibc's");
    TEST_ASSERT(0 == StrCmp(str20, str20_dup_a), 
                "testing duplication of an empty string");
    TEST_ASSERT(0 == StrCmp(str20_dup_a, str20_dup_b), 
                "testing duplication of my implementation vs. glibc's");

    printf("\n");

    /* --- teardown / cleanup --- */

    return 0;
}
/*********************************** Helper functions definitions */
