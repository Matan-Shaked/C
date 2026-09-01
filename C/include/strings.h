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


#endif /**************************************************** End of __STRINGS_H__ */
