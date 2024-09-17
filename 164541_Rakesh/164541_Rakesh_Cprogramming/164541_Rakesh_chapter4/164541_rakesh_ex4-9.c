/*
 *  This program is to do  getch and ungetch do not handle a pushed-back EOF correctly. Decide 
what their properties ought to be if an EOF is pushed back, then implement your design.
 * Author: Rakesh Peddaruvu
 * Created: 10 July, 2024
 * Modified:23 July, 2024
 */

/** REQUIRED HEADER FILES */
#include <stdio.h>



/** FUNCTION PROTOTYPES */
int getch(void);
void ungetch(int c);

/** MAIN PROGRAM */
/** main: Accepts full string*/
int main()
{
	    int c,i=0;
	    char s[50];
    int new_line = 1;  
    /* Flag to indicate if we're at the start of a new line */

    while ((c = getch()) != EOF)
    {
        if (new_line)
        {
            /*Print the first character of the line*/
            s[i++]=c;
	    s[i]='\n';
	    i++;
            new_line = 0;  /* Reset flag after printing the first character*/
        }

        /* Skip the rest of the line until the next newline */
        while ((c = getch()) != '\n' && c != EOF)
            ;

        if (c == '\n')
        {
            /* If we encountered a newline, set the flag for the next iteration*/
            new_line = 1;
        }
    }
    s[i]='\0';
    printf("%s\n",s);
printf("EOF encountered.\n");
    return 0;
}
/*End main() */



/*Index for the next free position in the buffer.*/
int buf = -1;


/*getch: Function to get a character from the buffer or standard input*/
/*Includes the string*/
int getch(void)

  {
  char temp;

  if (buf != -1)
  {
    temp = buf;
    buf = -1;

    return temp;
  }

  return getchar();
}
/*ungetch: Function to push a character back into the buffer*/
void ungetch(int c)
{
  if (buf != -1)
  {
    printf("ungetch: buffer full\n");
  }
  else
  {
    buf = c;
  }
}
/** End of ungetch */

