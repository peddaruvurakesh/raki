/*
 * This program demonstrates a modified version of the binary search algorithm.
 * The modified binary search has only one test inside the loop instead of two.
 * The purpose of this approach is to measure any difference in runtime performance.
 * 
 * Steps:
 * 1. Prompt the user to enter an integer array.
 * 2. Check if the array is sorted.
 * 3. If sorted, perform a binary search on the array to find a target number.
 * 4. Display whether the number is found or not, and its index if found.
 * 
 * Sample Input:
 * Enter the number of elements in the array:
 * 5
 * Enter the array elements:
 * 1 3 5 7 9
 * Enter a number to search:
 * 7
 * 
 * Sample Output:
 * Element 7 found in array at index 3
 * 
 * Author   : Rakesh Peddaruvu
 * Created  : 4 July, 2024
 * Modified : 4 July, 2024
 */

/** REQUIRED HEADER FILES */
#include <stdio.h>

/* MACRO DEFINITIONS */
#define RANGE 100  // Maximum size of the array

/** FUNCTION PROTOTYPES */
int binarySearch(int x, int v[], int n);
int is_Sorted(int a[], int n);

/** MAIN PROGRAM */
int main() {
    int iarr_v[RANGE];  // Array to hold user-entered values
    int iNumber, iEle, iIndex, iValue;

    /* Enter the size of the array */
    printf("Enter the number of elements in the array (<= %d):\n", RANGE);
    scanf("%d", &iEle);  // Input number of elements

    /* Enter array elements */
    printf("Enter the array elements:\n");
    for (iIndex = 0; iIndex < iEle; iIndex++) {
        scanf("%d", &iarr_v[iIndex]);  // Input each element
    }

    /* Enter a number to search */
    printf("Enter a number to search:\n");
    scanf("%d", &iNumber);  // Input the number to search

    /* Check if array is sorted */
    if (!is_Sorted(iarr_v, iEle)) {
        printf("Array not sorted.\n");
        return 0;  // Exit if the array is not sorted
    }

    /* Perform binary search */
    iValue = binarySearch(iNumber, iarr_v, iEle);
    if (iValue == -1) {
        printf("Element %d not found in array\n", iNumber);  // Element not found
    } else {
        printf("Element %d found in array at index %d\n", iNumber, iValue);  // Element found
    }

    return 0;
}
/* End main */

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binarySearch(int ivar_x, int iarr_v[], int inum) {
    int i_low, i_high, i_mid;
    i_low = 0;
    i_high = inum - 1;

    /* While the search space is valid */
    while (i_low <= i_high) {
        i_mid = (i_low + i_high) / 2;  // Find the middle index

        if (ivar_x == iarr_v[i_mid]) {
            return i_mid;  // If element is found at mid, return index
        } else if (ivar_x > iarr_v[i_mid]) {
            i_low = i_mid + 1;  // Search in the upper half
        } else {
            i_high = i_mid - 1;  // Search in the lower half
        }
    }
    return -1;  // If element not found, return -1
}
/* End binarySearch */

/* is_sorted: check if the array is sorted */
int is_Sorted(int a[], int inum) {
    int istart_1;
    
    /* Check if each element is less than or equal to the next element */
    for (istart_1 = 0; istart_1 < inum - 1; istart_1++) {
        if (a[istart_1] > a[istart_1 + 1]) {
            return 0;  // If any element is greater than the next, array is not sorted
        }
    }
    return 1;  // If no issues, array is sorted
}
/* End is_Sorted */

/*
 * Explanation:
 * - The `main()` function gathers user input for the array, checks if it is sorted, and searches for a specified element.
 * - The `is_Sorted()` function determines whether the array is sorted.
 * - The `binarySearch()` function performs a binary search and returns the index of the target if found.
 */

