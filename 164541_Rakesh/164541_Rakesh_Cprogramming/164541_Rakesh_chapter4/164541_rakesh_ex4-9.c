/* Our getch and ungetch do not handle a pushed-back EOF correctly. Decide
what their properties ought to be if an EOF is pushed back, then implement your design*/
#include <stdio.h>

#define BUFFSIZE 100

int getch(void);
void ungetch(int c);

int main(void)
{
  int c;

  c = getch();
  putchar(c);

  ungetch(EOF);

  c = getch();
  

  return 0;
}

int bufp = 0;
int buf[BUFFSIZE];

int getch(void)
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
  if (bufp >= BUFFSIZE)
  {
    printf("ungetch: too many characters\n");
  }
  else
   {
    buf[bufp++] = c;
  }
}
