/*This program is to print a histogram of the lengths of words in its input. It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging. 
 programming standards 
* Author: rakesh
* Created: 28 June, 2024
* Modified:28 June, 2024
*/
/** REQUIRED HEADER FILES */
#include <stdio.h>
/** MACRO DEFINITIONS */
#define MAX 50
/** FUNCTION PROTOTYPES */
void horizontal_hist(char[]);
void vertical_hist(char[]);
/** MAIN PROGRAM */
/** main: Accepts characters and to draw histogram calls both horizontal and vertcal functions */

int main()
{
char str[MAX];
char character;
int count=0;
//Store character in string str
while((character=getchar())!=EOF){
	str[count++]=character;
}
//NULL Terminate the string
str[count]='\0';
//calling horizontal histogam function
printf("horizontal histogram\n");
horizontal_hist(str);
//calling vertical histogram function
printf("vertical histogram\n");
vertical_hist(str);
}
/*End of main()*/

//To print vertical histogram
void horizontal_hist(char str[]) {
    int start;
    int count = 0;
    for (start = 0; str[start] != '\0'; start++) {
        if (str[start] == '\n' || str[start] == '\t' || str[start] == ' ') {
            if (count > 0) {
                printf("\n");
                count = 0;
            }
        } else {
            printf("*");
            count++;
        }
    }
    if (count > 0) {
        printf("\n");
    }
} 

void vertical_hist(char str[]) {
    int start;
    int count = 0;
    int word_lengths[100]; 
    int word_count = 0;
    
    // Loop through the input string
    for (start = 0; str[start] != '\0'; start++) {
        if (str[start] == '\n' || str[start] == '\t' || str[start] == ' ') {
            if (count > 0) {  
                word_lengths[word_count] = count;
                word_count++;
                count = 0;
            }
        } else {
            count++;
        }
    }
    
    if (count > 0) {
        word_lengths[word_count] = count;
        word_count++;
    }

    // Find the maximum word length
    int j, max_length = 0;
    for (j = 0; j < word_count; j++) {
        if (word_lengths[j] > max_length) {
            max_length = word_lengths[j];
        }
    }

    // Print the vertical histogram
    int k;
    for (j = max_length; j > 0; j--) {
        for (k = 0; k < word_count; k++) {
            if (word_lengths[k] >= j) {
                printf(" * ");
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }
}
/*End of vertcal_hist()*/
