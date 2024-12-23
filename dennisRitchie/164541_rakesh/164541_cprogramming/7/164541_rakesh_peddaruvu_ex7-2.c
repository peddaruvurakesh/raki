/* This program is to Write a program that will print arbitrary input in a sensible way. As a minimum, it should print non-graphic characters in octal or hexadecimal according to local custom and break long text lines.
 *Author: rakesh
* Created: 16, sep 2024
* Modified:16, sep 2024
*/
/** REQUIRED HEADER FILES */
#include <stdio.h>
#include <ctype.h>
/** MACRO DEFINITIONS*/
#define LENGTH 100 
/** MAIN PROGRAM */
/* main(): prints non-graphic characters in octal or hexadecimal */
int main() {
    int ich, ivar = 0;
    char sStr[LENGTH];

    while ((ich = getchar()) != EOF && ivar < sizeof(sStr) - 1) {
        sStr[ivar++] = ich;
    }
    sStr[ivar] = '\0'; 
    /* Null-terminate the string */

    for (ivar = 0; sStr[ivar]; ivar++) {
        if (isprint(sStr[ivar])) {
            printf("%c", sStr[ivar]);
      } else if (sStr[ivar] == '\t') {
            /* Print the tab as its hex equivalent (0x9) */
            printf("0x9 ");
	    
        } else if (sStr[ivar] == '\n') {
            /* Print newline as its hex equivalent (0xA) */
            printf("0xA\n");
        } else {
            /* Handle other non-printable characters if needed */
            printf("0x%X", sStr[ivar]);
    return 0;
}
}
}
/* End main() */
