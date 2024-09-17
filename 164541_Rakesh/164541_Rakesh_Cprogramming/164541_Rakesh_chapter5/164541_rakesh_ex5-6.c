/* This program is to rewrite appropriate programs from earlier chapters and exercises with pointers 
instead of array indexing. Good possibilities include atoi.
* Author: rakesh
* Created: 17 July, 2024
* Modified:17 July, 2024
*/
/** REQUIRED HEADER FILES */
#include <stdio.h>
/** MACRO DEFINITIONS */

/** FUNCTION PROTOTYPES */
   int my_atoi(const char *p);
/** MAIN PROGRAM */
/** main: Using pointers */

   int main(int argc,char **argv)
   {
           int x;
           if(argc != 2) {
           printf("Usage : ./a.out int\n");
          return 0;
          }
          x = my_atoi(argv[1]);
         printf("x = %d\n",x);
  }


/* End main() */
//my_atoi():converts string to integer
 int my_atoi(const char *p)
  {
          int sign=1,sum = 0;
          
           //if there is negative symbol 
          if(*p == '-'){
		  p++;
		  sign=-1;
	  }
          for(;*p!='\0';p++)
          {
                  if((*p>='0')&&(*p<='9'))
                  sum=sum*10+(*p-48);
                  else
                  break;
          }
          return sign*sum;
  }
/*End of my_atoi*/
