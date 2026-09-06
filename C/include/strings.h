#ifndef __STRINGS_H__
#define __STRINGS_H__
/********************************************************* Standard libraries */
#include <stddef.h> /*size_t*/

/********************************************************* POSIX's Extensions */

/********************************************************* Third party libraries */

/********************************************************* Private libraries / Headers */


/****************************************************************** Constants */
/******************************************************************* Typedefs */
/***************************************************************** Status enum */

/************************************************************** API functions */
/*
 * Description:     Function that calculates the length of the string pointed by
 *                  'str', excluding the terminated null byte ('\0').
 * Parameters:
 *	str:    pointer to array of chars (string) that is terminated with 
 *          terminated null byte ('\0'). If the array of chars is has no
 *          terminated null byte ('\0'), the function will result undefined behavior.
 *                             
 * Return value:
 *	    The number of bytes in the string pointed to by `str`, excluding the 
 *      terminated null byte ('\0').
 *
 * Complexity:  
 *	Time:   O(n)
 *	Space:  O(1)
 */
size_t StrLen(const char* str);

/*
 * Description:     Function that compares two strings (str1 and str2) to indicate
 *                  which of the strings has a greater value, in the first char
 *                  that is different (if there is any difference) between them. 
 *                  Both string has to have a null-terminator byte. 
 *                  If at least one of the strings doesn't have a null-terminator byte, 
 *                  the function will result undefined behavior.
 * 
 * Parameters:
 *	str1:   pointer to the first null-terminated string to compare.
 *  str2:   pointer to the second null-terminated string to compare.
 *                             
 * Return value:
 *	    0 - if the two strings are equal (identical).
 *      positive value - in case that there is difference between the two strings
 *                       and the first different char is greater in str1 than in str2.
 *      negative value - in case that there is difference between the two strings
 *                       and the first different char is greater in str2 than in str1.
 *
 * Complexity:  
 *	Time:   O(n)
 *	Space:  O(1)
 */
int StrCmp(const char* str1, const char* str2);

/*
 * Description:     Function that compares two strings (str1 and str2) to indicate
 *                  which of the strings has a greater value, in the first char
 *                  that is different (if there is any difference) between them. 
 *                  Both string has to have a null-terminator byte. 
 *                  If at least one of the strings doesn't have a null-terminator byte, 
 *                  the function will result undefined behavior.
 *                  The function compares, at most, the first 'size' bytes.
 * 
 * Parameters:
 *	str1:   pointer to the first null-terminated string to compare.
 *  str2:   pointer to the second null-terminated string to compare.
 *  size:   numbers of bytes to compare between `str1` to `str2`.
 *                             
 * Return value:
 *	    0 - if the two strings are equal (identical) in first 'size' bytes.
 *      positive value - in case that there is difference between the two strings
 *                       and the first different char is greater in str1 than in str2.
 *      negative value - in case that there is difference between the two strings
 *                       and the first different char is greater in str2 than in str1.
 *
 * Complexity:  
 *	Time:   O(n)
 *	Space:  O(1)
 */
int StrNCmp(const char* str1, const char* str2, size_t size);

/*
 * Description:     Function that compares two strings (str1 and str2) to indicate
 *                  which of the strings has a greater value, in the first char
 *                  that is different (if there is any difference) between them. 
 *                  The function ignores the case of the characters in the strings.
 *                  Both string has to have a null-terminator byte. 
 *                  If at least one of the strings doesn't have a null-terminator byte, 
 *                  the function will result undefined behavior.
 * 
 * Parameters:
 *	str1:   pointer to the first null-terminated string to compare.
 *  str2:   pointer to the second null-terminated string to compare.
 *                             
 * Return value:
 *	    0 - if the two strings are equal (identical).
 *      positive value - in case that there is difference between the two strings
 *                       and the first different char is greater in str1 than in str2.
 *      negative value - in case that there is difference between the two strings
 *                       and the first different char is greater in str2 than in str1.
 *
 * Complexity:  
 *	Time:   O(n)
 *	Space:  O(1)
 */
int StrCaseCmp(const char* str1, const char* str2);

/*
 * Description:     Function that copy a null-terminated string pointed to by `src`, 
 *                  into a string at the buffer pointed by `dest`.
 *                  If the `src` is pointing to array of chars without terminate
 *                  null byte, the function will result in undefined behavior.
 *                  The programmer is responsible for allocating a destination 
 *                  buffer large enough, that is strlen(src) + 1. Otherwise, 
 *                  the function will result in undefined behavior.
 * 
 * Parameters:
 *	src:  pointer to the string to copy. 
 *  dest: pointer to the string buffer to copy to. 
 *                             
 * Return value:
 *	    a pointer to dest.
 *
 * Complexity:  
 *	Time:   O(n)
 *	Space:  O(1)
 */
char* StrCpy(char* dest, const char* src);

/*
 * Description:     Function that copy a null-terminated string pointed to by `src`, 
 *                  into a string at the buffer pointed by `dest`. It copy the first
 *                  `size` bytes from `src` to `dest`.
 *                  If `src` is shorter the `dest`, the function pad the 
 *                  the `dest` with trailing null bytes.
 *                  If the `dest` is smaller then the `src`, the resulting char
 *                  sequence is truncated.
 * 
 * Parameters:
 *	src:  pointer to the string to copy. 
 *  dest: pointer to the string buffer to copy to. 
 *  size: number of bytes to copy from src to dest.
 *                             
 * Return value:
 *	    a pointer to dest.
 *
 * Complexity:  
 *	Time:   O(n)
 *	Space:  O(1)
 */
char* StrNCpy(char* dest, const char* src, size_t size);

/*
 * Description:     Function that returns a pointer to the first occurrence of 
 *                  the character 'c' in the null-terminated string that 
 *                  pointed by 'str'.
 *                  If the `str` is pointing to array of chars without terminate
 *                  null byte, the function will result in undefined behavior.
 * 
 * Parameters:
 *	str:  pointer to the null-terminated string string to search in for 'c'. 
 *  c:    The character to search for inside the string that pointed by `str`.
 *                             
 * Return value:
 *	    If character was found - a pointer to the matched character.
 *      Otherwise - NULL.
 *
 * Complexity:  
 *	Time:   O(n)
 *	Space:  O(1)
 */
char* StrChr(const char* str, int c);

/*
 * Description:     Function that returns a pointer to a new null-terminated string
 *                  that is dupicate of the string that is pointed by 'str'.
 *                  The new string is allocated dynamically and the user 
 *                  is responsible to free its memory after finish using it with
 *                  free() (from stdlib.h). 
 * 
 * Parameters:
 *	str:  pointer to the null-terminated string that is duplicated. 
 *                             
 * Return value:
 *	    On success - a pointer to the new duplicate string.
 *      Otherwise - NULL.
 *
 * Complexity:  
 *	Time:   O(n)
 *	Space:  O(1)
 */
char* StrDup(const char* str);

/*
 * Description:     Function that catenates the null-terminated string pointed by `src`,    
 *                  into a null-terminated string at the buffer pointed by `dest`, 
 *                  overwriting its terminating null byte).
 *                  If the `src` is pointing to array of chars without terminate
 *                  null byte, the function will result in undefined behavior.
 *                  The programmer is responsible for allocating a destination 
 *                  buffer large enough, that is strlen(src) + strlen(dest) + 1. 
 *                  Otherwise, the function will result in undefined behavior.
 * 
 * Parameters:
 *	src:  pointer to the string to copy from. 
 *  dest: pointer to the string destination buffer to catenate to. 
 *                             
 * Return value:
 *	    a pointer to dest.
 *
 * Complexity:  
 *	Time:   O(n)
 *	Space:  O(1)
 */
char* StrCat(char* dest, const char* src);

/*
 * Description:     Function that catenates the null-terminated string pointed by `src`,    
 *                  into a null-terminated string at the buffer pointed by `dest`, 
 *                  overwriting its terminating null byte).
 *                  It catenates the at most `size` non-null terminating bytes from `src` to `dest`,
 *                  followed by a null character to the end of the string pointed
 *                  by 'dest'.
 *                  If the `src` is pointing to array of chars without terminate
 *                  null byte, the function will result in undefined behavior.
 *                  The programmer is responsible for allocating a destination 
 *                  buffer large enough, that is strlen(src) + strlen(dest) + 1. 
 *                  Otherwise, the function will result in undefined behavior.
 * 
 * Parameters:
 *	src:  pointer to the string to copy from. 
 *  dest: pointer to the string destination buffer to catenate to. 
 *  size: number of bytes to concatenate from src to dest.
 *                             
 * Return value:
 *	    a pointer to dest.
 *
 * Complexity:  
 *	Time:   O(n)
 *	Space:  O(1)
 */
char* StrNCat(char* dest, const char* src, size_t size);

/*
 * Description:     Function that finds the first occurrence of the substring 
 *                  'needle' in the string 'haystack'.
 *                  The terminating null bytes are not compared.
 *                  Both 'haystack' and `needle` are have to be null-terminated
 *                  strings, otherwise the function will result in undefined behavior. 
 * 
 * Parameters:
 *	haystack:   pointer to the null terminated string to seach in the `needle`. 
 *  needle:     pointer to the substring string to search in the `haystack`.
 *                             
 * Return value:
 *	    On sucess:  if the `needle` is found - a pointer to the beginning of 
 *                  the located substring that pointed by `needle`.
 *      Otherwise:  if the `needle` is not found - NULL.
 *      If the `needle` is pointing to an empty string, the return value is the 
 *      `haystack` itself.
 *
 * Complexity:  
 *	Time:   O(n *m), where 'n' is the length of haystack and 'm' is the length of 'needle.
 *	Space:  O(1)
 */
char* StrStr(const char* haystack, const char* needle);

/*
 * Description:     Function that calculates the length in bytes of the initial
 *                  segment of 'str' in null terminated string  
 *                  which consists entierly of bytes that are specified in 'accept'. 
 * 
 * Parameters:
 *	str:        pointer to initial segment in a null terminated string that
 *              consist only from chararcters that are specified in the `accept`.
 *  accept:     array of acceptable chars to be in the 'str'.
 *                             
 * Return value:
 *	    The number of bytes in the initial segment of 'str' which consist only
 *      of bytes from `accept`.
 *
 * Complexity:  
 *	Time:   O(n *m), where 'n' is the length of 'str' and 'm' 
 *          is the length of 'accept`.
 *	Space:  O(1)
 */
size_t StrSpn(const char* str, const char* accept);

/*
 * Description:     Function that breaks a string into a sequence of zero or more
 *                  non-empty tokens (substrings).
 *                  
 *                  On first call to the function, the string to be parsed should be 
 *                  specified in `str`.
 *                  On each subsequent call that should parse the same string,
 *                  `str` must be NULL.
 * 
 *                  The `delim` argument specifies a set of bytes that delimit
 *                  the tokens in the parsed string. 
 *                  The caller may specify different strings in `delim` in successive
 *                  calls that parse the same string.
 *                  Each call to the function returns a pointer to a null-terminated
 *                  string containing the next token (the string does not include)
 *                  the delemiting byte.
 * 
 *                  A sequence of calls to the function that operate on the same 
 *                  string maintains a pointer that determinces the point from 
 *                  which to start searching for the next token.
 *                  The first call to the function sets this pointer to point
 *                  to the first byte of the string. 
 *                  The start of the next token is determined by scanning forward
 *                  for the next non-delimeter byte in `str`.
 *                  If such a byte is found, it is taken as the start of the next
 *                  token and the delimiter the comes before it is overwritten with
 *                  a null byte to terminate the current token, and the function
 *                  will return a pointer to the next token.
 *                  If such byte is not found, then there are no more tokens,
 *                  and the function returns NULL.
 * 
 *                  Sequence of two or more contiguous delimiter bytes in the parsed
 *                  string is cosidered to be a single delimiter.
 *                  Delimiter bytes at the start or the end of the parsed string
 *                  are ignored.
 * 
 * Parameters:
 *	str:        pointer the null terminated string that will parsed so each function
 *              call will return a token from it. 
 *              On each subsequent call that should parse the same string,
*               `str` must be NULL.
 *  delim:      set of bytes that delimit the tokens in the parsed string.
 *                             
 * Return value:
 *          Pointer to the next token.
 *          NULL - if there are no more tokens.
 *
 * Complexity:  
 *	Time:   O(n *m), where 'n' is the length of 'str' and 'm' 
 *          is the length of 'delim`.
 *	Space:  O(1)
 */
char* StrTok(char* str, const char* delim);
#endif /**************************************************** End of __STRINGS_H__ */
