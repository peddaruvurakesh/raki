/*
 * This program is to write a function htoi(s), which converts a string of hexadecimal digits (including an optional 0x or 0X) into 
 * its equivalent integer value. The allowable digits are 0 through 9, a through f, and A through F.  
* Author: rakesh
* Created: 3 July, 2024
* Modified:3 July, 2024
*/
/** REQUIRED HEADER FILES */
#include <stdio.h>

/**MACRO DEFINITIONS **/
#define RANGE 100
/** FUNCTION PROTOTYPES */
int my_htoi(const char p[]);
/** MAIN PROGRAM */
/** main: writes a equivalent loop for above for loop */
int main()
{
           int output;
	   char str[RANGE],ch;
	   /* do while:This loop is to ask usr to repeat process based on condition*/
	   do{
	   printf("Enter input \n");
           scanf(" %[^\n]",str);
	   /* FUNCTION CALL */
          output= my_htoi(str);
	  /* Return integer value */
	  if(output==-1)
	  {
		  printf("Enter valid hex number\n");
	  }
	  else{
          printf("output = %d\n",output);
	  }
	  printf("do you want to give input again?(y/n)\n");
	  scanf(" %c",&ch);
	   }while(ch=='y' || ch=='Y');
}

/* End main() */

/*converts hexadecimal to integer */
  int my_htoi(const char p[])
  {
          int i = 0,sum = 0;
          if((p[0] == '0')&&((p[1]=='x')||(p[1] == 'X'))){
          i = 2;
	  }
	  else{
		  return -1;
	  }
 /*The allowable digits are 0 through 9, a through f, and A through F.*/
          for(;p[i];i++)
          {
                        int value;

        if (p[i] >= '0' && p[i] <= '9') {
            value = p[i] - '0';
        } else if (p[i] >= 'a' && p[i] <= 'f') {
            value = p[i] - 'a' + 10;
        } else if (p[i] >= 'A' && p[i] <= 'F') {
            value = p[i] - 'A' + 10;
        } else {
            break;
        }

        sum = sum * 16 + value;
    }
    
    return sum;
 }
/** End of my_atoi*/
