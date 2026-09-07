#ifndef __STRINGS_EXERCISES_H__
#define __STRINGS_EXERCISES_H__

/************************************************************** API functions */
/*
 * Description:     Function that checks if a string is a palindrome 
 *                  (could include all characters, not only letters).
 * 
 * Parameters:
 *	str:    pointer to array of chars (string) that is terminated with 
 *          terminated null byte ('\0'). If the array of chars is has no
 *          terminated null byte ('\0'), the function will result undefined behavior.
 *                             
 * Return value:
 *	    On success (found a palindrome) - returns 1.
 *      Otherwise - returns 0.
 *
 * Complexity:  
 *	Time:   O(n)
 *	Space:  O(1)
 */
int IsPalindrome(const char* str);

/*
 * Description:     Function that prints all the numbers in a certain range that
 *                  the user supply it, except from every number that contains the 
 *                  the digit `7` or that is divisible by 7 without remainder.
 *                  Instead of printing these numbers, the function will print 
 *                  the string "BOOM".
 *                  The user is responsible to supply values for `from` and 'to',
 *                  so `from` is smaller than `to`.
 * 
 * Parameters:
 *	from:   the first number in the range. 
 *  to:     the last number in the range (excluded).
 *                             
 * Return value:
 *          none.
 *
 * Complexity:  
 *	Time:   O(n)
 *	Space:  O(1)
 */
void SevenBoom(int from, int to);

/*
 * Description:     Function that receives a null terminated string and deletes 
 *                  white spaces (`tab` and `space`) from the beginning and the 
 *                  end of the string, and deletes duplicate white spaces within
 *                  the string (replace sequences of multiple whitespaces with 
 *                  the first whitespace in the sequence).
 * 
 * Parameters:
 *	str:    the string to parse.
 *                             
 * Return value:
 *          none.
 *
 * Complexity:  
 *	Time:   O(n)
 *	Space:  O(1)
 */
void CleanWhitespaces(char* str);
#endif /**************************************************** End of __STRINGS_EXERCISES_H__ */
