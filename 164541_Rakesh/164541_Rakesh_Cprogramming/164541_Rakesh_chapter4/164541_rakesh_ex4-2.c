/*
* This program is to  extend atof to handle scientific notation of the form 123.45e-6  where a floating-point number may be followed by e or E and an optionally signed 
* exponent.
* Author: rakesh
* Created: 8 July, 2024
* Modified:16 July, 2024
*/
/** REQUIRED HEADER FILES */
#include <stdio.h>
#include<math.h>
#include<stdlib.h>
/** MACRO DEFINITIONS */
#define RANGE 100
/** FUNCTION PROTOTYPES */
 double my_atof( char *);

/** MAIN PROGRAM */
/* main():Accepts inputs at compile time and calls my_atof function*/ 
int main()
{
           double x;
           char s[RANGE],i=0,ch,c;
	   do{
		   i=0;
	   while((ch=getchar())!='\n')
		   s[i++]=ch;
	   s[i]='\0';
          x = my_atof(s);
          printf("x = %lf\n",x);
	  printf("do you want to check for another string? (y / n)\n");
	  scanf("%c",&ch);
	  while(getchar()!='\n');
	   }while(ch=='y'||ch=='Y');
 }
/*End of main()*/
/*my_atof():converts string to float with notation*/
 double my_atof( char *p)
  {
          int pos = 0,exp=0,sign=1;
          double sum2 = 0,sum1=0, f = 0.1;
          if((p[0] == '-')||(p[0] == '+'))
          pos = 1;
          //convert input into float upto decimal point
          for(;p[pos] != 'e' && p[pos] != 'E' && (p[pos] != '.') && p[pos] != '\0';pos++)
          {
                  if((p[pos]>='0')&&(p[pos]<='9'))
                  sum1 = sum1*10+(p[pos]-'0');
                  else
                 return 0;
         }
         //convert string after decimal point into float
	 if(p[pos]=='.'){
		 pos++;
          for(;p[pos] != 'e' && p[pos] != 'E' && p[pos] != '\0';pos++,f*=0.1)
          {
                  if((p[pos]>='0')&&(p[pos]<='9'))
                  sum2 = sum2+f*(p[pos]-'0');
                   else
			   return 0;
	  }
	 }
          double result =sum1+sum2;
         //if it is in exponential form
	     if (p[pos] == 'e' || p[pos] == 'E') {
        pos++;
        if (p[pos] == '-') {
            sign = -1;
            pos++;
        } else if (p[pos] == '+') {
            pos++;
        }

        for (; p[pos] != '\0'; pos++) {
            if ((p[pos] >= '0') && (p[pos] <= '9'))
                exp = exp * 10 + (p[pos] - '0');
            else
                return 0; 
        }

               if (sign == 1) {
            for (int i = 0; i < exp; i++) {
                result *= 10;
            }
        } else {
            for (int i = 0; i < exp; i++) {
                result /= 10;
            }
        }
	     }
	     //returns negative value
          if(p[0] == '-')
		  return -result;
	  else
		  //returns obtained result
		  return result;
 }
/*end of my_atof()*/
