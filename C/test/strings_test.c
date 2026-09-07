/*************************
* Test File: STRINGS Module
* Author: Matan Shaked
* Last update: 30/08/26
**************************/
/************************************************************* POSIX Define's */
#define _POSIX_C_SOURCE (200809L)

/********************************************************* Standard libraries */
#include <string.h> /*strlen, strcmp, strncmp, strchr, strdup, strcat, strncat, 
                        strstr, strspn, strtok*/
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
    char* str21_cat_src_a = " The king";
    char str21_cat_dest_a[100] = "Long live";
    char* str21_cat_src_b = " The king";
    char str21_cat_dest_b[100] = "Long live";
    char* str22_cat_src_a = "Day";
    char str22_cat_dest_a[100] = "What a beautiful ";
    char* str22_cat_src_b = "Day";
    char str22_cat_dest_b[100] = "What a beautiful ";
    char* str21_cat_n_src_a = " The king";
    char str21_cat_n_dest_a[100] = "Long live";
    char* str21_cat_n_src_b = " The king";
    char str21_cat_n_dest_b[100] = "Long live";
    char* str22_cat_n_src_a = "Day";
    char str22_cat_n_dest_a[100] = "What a beautiful ";
    char* str22_cat_n_src_b = "Day";
    char str22_cat_n_dest_b[100] = "What a beautiful ";
    char* str23_cat_n_src_a = "Day";
    char str23_cat_n_dest_a[100] = "What a rainy ";
    char* str23_cat_n_src_b = "Day";
    char str23_cat_n_dest_b[100] = "What a rainy ";
    char* str24_strstr_haystack_a = "matan has arrived";
    char* str24_strstr_needle_a = "";
    char* str24_strstr_needle_b = "p";
    char* str24_strstr_needle_c = "has";
    char* str24_strstr_needle_d = "hhas";
    char* str24_strstr_needle_e = "matan has arrivedddddd";
    char str25_spn[] = "matan is in the house";
    char str26_spn[] = "messi is in the house";
    char str27_spn[] = "marradona is in the house";
    char str28_spn[] = "";
    char str_spn_accept[] = "matsrd";
    char str_spn_accept_empty[] = "";
    char str_token[] = "Matan para Messi para matan and ke Gollllassssso!";
    size_t str25_spn_a = strspn(str25_spn, str_spn_accept);
    size_t str25_spn_b = StrSpn(str25_spn, str_spn_accept);
    size_t str26_spn_a = strspn(str26_spn, str_spn_accept);
    size_t str26_spn_b = StrSpn(str26_spn, str_spn_accept);
    size_t str27_spn_a = strspn(str27_spn, str_spn_accept);
    size_t str27_spn_b = StrSpn(str27_spn, str_spn_accept);  
    size_t str25_spn_a_e = strspn(str25_spn, str_spn_accept_empty);
    size_t str25_spn_b_e = StrSpn(str25_spn, str_spn_accept_empty);
    size_t str28_spn_a_e = strspn(str28_spn, str_spn_accept);  
    size_t str28_spn_b_e = StrSpn(str28_spn, str_spn_accept);  
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

    printf("--- Tests on StrCat ---\n");
    TEST_ASSERT(0 == StrCmp(StrCat(str21_cat_dest_a, str21_cat_src_a), "Long live The king"),
                "testing concatenating of two strings to have \"Long live The king\"");
    TEST_ASSERT(0 == StrCmp(str21_cat_dest_a, strcat(str21_cat_dest_b, str21_cat_src_b)),
                "testing concatenating of two strings of my implementation vs. glibc's");
    TEST_ASSERT(0 == StrCmp(StrCat(str22_cat_dest_a, str22_cat_src_a), "What a beautiful Day"),
                "testing concatenating of two strings to have \"What a beautiful Day\"");
    TEST_ASSERT(0 == StrCmp(str22_cat_dest_a, strcat(str22_cat_dest_b, str22_cat_src_b)),
                "testing concatenating of two strings of my implementation vs. glibc's");
    printf("\n");

    printf("--- Tests on StrNCat ---\n");
    TEST_ASSERT(0 == StrCmp(StrNCat(str21_cat_n_dest_a, str21_cat_n_src_a, 4), "Long live The"),
                "concatenating only part of src into dest to have \"Long live The\"");
    TEST_ASSERT(0 == StrCmp(str21_cat_n_dest_a, strncat(str21_cat_n_dest_b, str21_cat_n_src_b, 4)),
                "testing concatenating of two strings of my implementation vs. glibc's");
    TEST_ASSERT(0 == StrCmp(StrNCat(str22_cat_n_dest_a, str22_cat_n_src_a, 10), "What a beautiful Day"),
                "concatenating with size that is bigger of src into dest to have \"What a beautiful Day\"");
    TEST_ASSERT(0 == StrCmp(str22_cat_n_dest_a, strncat(str22_cat_n_dest_b, str22_cat_n_src_b, 10)),
                "testing concatenating of two strings of my implementation vs. glibc's");
    TEST_ASSERT(0 == StrCmp(StrNCat(str23_cat_n_dest_a, str23_cat_n_src_a, 0), "What a rainy "),
                "concatenating with size of 0 to have \"What a rainy \"");
    TEST_ASSERT(0 == StrCmp(str23_cat_n_dest_a, strncat(str23_cat_n_dest_b, str23_cat_n_src_b, 0)),
                "testing concatenating of two strings of my implementation vs. glibc's");
    printf("\n");

    printf("--- Tests on StrStr ---\n");
    TEST_ASSERT(
        0 == StrCmp(StrStr(str24_strstr_haystack_a, str24_strstr_needle_a), 
                    "matan has arrived"),
        "testing StrStr with an empty needle to return the full haystack: \"matan has arrived\""
    );
    TEST_ASSERT(
        NULL == StrStr(str24_strstr_haystack_a, str24_strstr_needle_b), 
        "testing StrStr with a needle that is not found in the haystack to return NULL"
    );
    TEST_ASSERT(
        0 == StrCmp(StrStr(str24_strstr_haystack_a, str24_strstr_needle_c), 
                    "has arrived"),
        "testing StrStr with a needle that is found in the haystack to return: \"has arrived\""
    );
    TEST_ASSERT(
        NULL == StrStr(str24_strstr_haystack_a, str24_strstr_needle_d),
        "testing StrStr with a misleading needle with two same opening chars "
        "(\"hhas\"), considered as not a fitting needle that resulting NULL"
    );
    TEST_ASSERT(
        StrStr(str24_strstr_haystack_a, str24_strstr_needle_e) == NULL, 
        "testing StrStr with a needle that is not found in the "
        "and that is longer than the haystack (\"matan has arrivedddddd\") to "
        "return NULL"
    );
     TEST_ASSERT(0 == StrCmp(
                        StrStr(str24_strstr_haystack_a, str24_strstr_needle_a),
                        strstr(str24_strstr_haystack_a, str24_strstr_needle_a)
                    ),
    "testing finding needle in haystack (strstr)of my implementation vs. glibc's");
    TEST_ASSERT(StrStr(str24_strstr_haystack_a, str24_strstr_needle_b) 
                ==  strstr(str24_strstr_haystack_a, str24_strstr_needle_b),
    "testing finding needle in haystack (strstr)of my implementation vs. glibc's");
    TEST_ASSERT(0 == StrCmp(
                        StrStr(str24_strstr_haystack_a, str24_strstr_needle_c),
                        strstr(str24_strstr_haystack_a, str24_strstr_needle_c)
                    ),
    "testing finding needle in haystack (strstr)of my implementation vs. glibc's");
    TEST_ASSERT(StrStr(str24_strstr_haystack_a, str24_strstr_needle_d) 
                ==  strstr(str24_strstr_haystack_a, str24_strstr_needle_d),
    "testing finding needle in haystack (strstr)of my implementation vs. glibc's");
    printf("\n");

    printf("--- Tests on StrSpn ---\n");
    printf("Accept is: matsrd\n"
            "Three strings:\n"
            "matan is in the house - expected result is 4, got: %lu\n"
            "messi is in the house - expected result is 1, got: %lu\n"
            "marradona is in the house - expected result is 6, got: %lu\n",
             str25_spn_b, str26_spn_b, str27_spn_b
        );
    TEST_ASSERT(str25_spn_a == str25_spn_b, "testing my implementation vs. glibc's");
    TEST_ASSERT(str26_spn_a == str26_spn_b, "testing my implementation vs. glibc's");
    TEST_ASSERT(str27_spn_a == str27_spn_b, "testing my implementation vs. glibc's");
    TEST_ASSERT(str25_spn_a_e == str25_spn_b_e, "testing empty accept - my implementation vs. glibc's");
    TEST_ASSERT(str28_spn_a_e == str28_spn_b_e, "testing empty string - my implementation vs. glibc's");
    printf("\n");

    printf("--- Tests on StrTok ---\n");
    {
        char* token = StrTok(str_token, " ");

        while (NULL != token)
        {
            printf("%s\n", token);
            token = StrTok(NULL, " ");
        }
    }
    printf("\n");
 
    /* --- cleanup --- */
    free(str18_dup_a);
    free(str18_dup_b);
    free(str19_dup_a);
    free(str19_dup_b);
    free(str20_dup_a);
    free(str20_dup_b);

    return 0;
}