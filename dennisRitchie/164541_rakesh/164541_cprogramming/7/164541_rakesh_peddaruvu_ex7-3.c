/*This program is to revise minprintf to handle more of the other facilities of printf.*/
/* Author: rakesh
*  Created: 29 Aug, 2024
*  Modified:29 Aug, 2024
*/
/** REQUIRED HEADER FILES */
#include<stdio.h>
#include<stdarg.h>
/** FUNCTION PROTOTYPES */
void my_printf(const char *, ...);
/** MAIN PROGRAM */
/** main: own printf function */
int main() {
    int iNum;
    float fDnum;
    double dDoub;
    unsigned int uUnint;
    char cCharacter;
    char sStr[50];
    void *pPointer;

    /* Input Section */
    printf("Enter integer number: ");
    scanf("%d", &iNum);

    printf("Enter float number: ");
    scanf("%f", &fDnum);

    printf("Enter double number: ");
    scanf("%lf", &dDoub);

    printf("Enter unsigned integer number: ");
    scanf("%u", &uUnint);

    printf("Enter character: ");
    scanf(" %c", &cCharacter);

    printf("Enter string: ");
    scanf(" %[^\n]", sStr);

    pPointer = &iNum; /* Example of a pointer (address of iNum) */

    /* Output Section */
    my_printf(
        "You have entered:\n"
        "Integer iNum: %d\n"
        "Float fDnum: %f\n"
        "Double dDoub: %lf\n"
        "Unsigned integer uUnint: %u\n"
        "Character cCharacter: %c\n"
        "String sStr: %s\n"
        "Octal representation of iNum: %o\n"
        "Hexadecimal representation of iNum: %x\n"
        "Pointer pPointer: %p\n",
        iNum, fDnum, dDoub, uUnint, cCharacter, sStr, iNum, iNum, pPointer
    );

    return 0;
}
/* my_printf function */
/* Author: rakesh
*  Created: 29 Aug, 2024
*  Modified:29 Aug, 2024
*/
void my_printf(const char *pPtr, ...) {
    va_list vaPtr;
    va_start(vaPtr, pPtr);
    while (*pPtr) {
        if (*pPtr == '%') {
            pPtr++;
            switch (*pPtr) {
		    /* For Integer */
                case 'd': {
                    int iVar = va_arg(vaPtr, int);
                    printf("%d", iVar);
                    break;
                }
			  /* For float */
                case 'f': {
                    double dFloat = va_arg(vaPtr, double);
                    printf("%f", dFloat);
                    break;
                }
			  /* For double */
                case 'l': {
                    if (*(pPtr + 1) == 'f') {
                        double d_lf = va_arg(vaPtr, double);
                        printf("%lf", d_lf);
                        pPtr++; 
			/* Skip 'f' after 'l' */
                    }
                    break;
                }
			  /* Unsigned int */
                case 'u': {
                    unsigned int uVar = va_arg(vaPtr, unsigned int);
                    printf("%u", uVar);
                    break;
                }
			  /* char */
                case 'c': {
                    int ichar = va_arg(vaPtr, int); /* char is promoted to int in va_arg */
                    printf("%c", ichar);
                    break;
                }
			  /* string */
                case 's': {
                    char *sStr = va_arg(vaPtr, char*);
                    printf("%s", sStr);
                    break;
                }
			  /* octal */
                case 'o': {
                    int oOctal = va_arg(vaPtr, int);
                    printf("%o", oOctal);
                    break;
                }
			  /* hexadecimal */
                case 'x': {
                    int xhex = va_arg(vaPtr, int);
                    printf("%x", xhex);
                    break;
                }
			  /* pointer */
                case 'p': {
                    void *ptr = va_arg(vaPtr, void*);
                    printf("%p", ptr);
                    break;
                }
                default:
                    putchar(*pPtr);
                    break;
            }
        } else {
            putchar(*pPtr);
        }
        pPtr++;
    }
    va_end(vaPtr);
}
/* End of my_printf */
/*#include<stdarg.h>
void my_printf(const char *,...);
int main()
{
	int x ;
	printf("enter a integer :");
	scanf("%d",&x);
	char ch ;
	printf("Enter a character: ");
	scanf(" %c",&ch);
  	float f;
	getchar();
	printf("Enter float value: ");
	scanf(" %f",&f);
	int dDoub;
	    printf("Enter double number: ");
    scanf("%lf", &dDoub);
int uUnint;
    printf("Enter unsigned integer number: ");
    scanf("%u", &uUnint);
	char a[20];
	printf("Enter a string: ");
	scanf(" %[^\n]",a);
	int *ptr=&x;
	my_printf("x = %d, ch = %c, f = %f  a = %s\n",x,ch,f,a);
}
void my_printf(const char *p,...)
{
  int i;
  char a[20];
  va_list ap;
  va_start(ap,p);
  while(*p)
  {
	if(*p == '%')
	{
		p++;
		if(*p == 'c')
		{
			char c = va_arg(ap,int);
			putchar(c);
		}
		if(*p == 'd')
		{
			int x = va_arg(ap,int);
			sprintf(a,"%d",x);
			for(i=0;a[i];i++)
			putchar(a[i]);		
		}	
		if(*p == 'f')
		{
			float f = va_arg(ap,double);
			sprintf(a,"%f",f);
			for(i=0;a[i];i++)
			putchar(a[i]);		
		}	
		if(*p == 's')
		{
			char *s = va_arg(ap,char*);
			for(i=0;s[i];i++)
			putchar(s[i]);		
		}	
	}
	else 
	putchar(*p);

	p++;
  }

}*/
