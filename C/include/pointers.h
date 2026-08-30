#ifndef __POINTERS_H__
#define __POINTERS_H__
/********************************************************* Standard libraries */
#include <stddef.h> /*size_t*/

/************************************************************** API functions */
/*
*   Description:    Function that swaps between the values of two int variables 
*                   (`a` as first and `b` as second).
*
*   Parameters:
*       a - pointer to the first int variable.
*       b - pointer to the second int variable.
*
*   Return value: 
*       none.
*   
*   Complexity:
*       Time: O(1).
*       Space: O(1).
*/
void SwapInts(int* a, int* b);

/*
*   Description: Copy elements from a source array into a destination buffer.
*
*   Parameters:
*       src -   pointer to a source array to copy from.
*       size -  the size in bytes of the source array.
*       dest -  pointer to dest array to copy to. 
*               The caller must to supply a buffer at least as large as the 
*               size in bytes of the source array. 
*               If the destination size is smaller then the source array, only
*               enough bytes to fill the destination buffer will be copied,
*               and the rest of the source bytes will not be copied to the 
*               destunation buffer.
*
*   Return value: 
*       none.
*   
*   Complexity:
*       Time: O(n).
*       Space: O(1).
*/
void CopyArray(const void* src, size_t size, void* dest);

/*
*   Description:    Function that swaps between the values of two size_t variables 
*                   (`a` as first and `b` as second).
*
*   Parameters:
*       a -     pointer to the first size_t variable.
*       b -     pointer to the second size_t variable.
*
*   Return value: 
*       none.
*   
*   Complexity:
*       Time: O(1).
*       Space: O(1).
*/
void SwapSizeT(size_t* a, size_t* b);

/*
*   Description:    Function that swaps between the values of two pointers to 
*                    size_t variables (`a` as first and `b` as second).
*                   
*
*   Parameters:
*       a -     pointer to the first size_t pointer variable.
*       b -     pointer to the second size_t pointer variable.
*
*   Return value: 
*       none.
*   
*   Complexity:
*       Time: O(1).
*       Space: O(1).
*/
void SwapSizeTPointers(size_t** a, size_t** b);


#endif /**************************************************** End of __POINTERS_H__ */
