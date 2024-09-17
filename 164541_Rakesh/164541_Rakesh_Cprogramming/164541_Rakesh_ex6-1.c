/*
 * This program is to handle getword, which does not properly handle underscores, string constants, comments, or preprocessor control lines. Write a better version.
 * Author: Gopisai
 * Created: 31 July, 2024
 * Modified:31 July, 2024
 */
/** REQUIRED HEADER FILES */
#include <stdio.h>
#include <ctype.h> 
#include <string.h> 

/** MACRO DEFINITIONS */
#define RANGE 500
#define MAXWORD 100 

#define BUFSIZE 100
#define NKEYS  (sizeof keytab / sizeof(keytab[0]))
struct key
{
	char word[RANGE];
	int count;
}keytab[]={
	{"auto", 0},
	{"break", 0},
	{"case", 0},
	{"char", 0},
	{"const", 0},
	{"continue", 0},
	{"default", 0},
	{"do", 0},
	{"double", 0},
	{"else", 0},
	{"enum", 0},
	{"extern", 0},
	{"float", 0},
	{"for", 0},
	{"goto", 0},
	{"if", 0},
	{"int", 0},
	{"long", 0},
	{"register", 0},
	{"return", 0},
	{"short", 0},
	{"signed", 0},
	{"size_t", 0},
	{"sizeof", 0},
	{"static", 0},
	{"struct", 0},
	{"switch", 0},
	{"typedef", 0},
	{"union", 0},
	{"unsigned", 0},
	{"void", 0},
	{"volatile", 0},
	{"while", 0},	
};


/** FUNCTION PROTOTYPES */
int getword(char *, int); 
struct key *binsearch(char *, struct key *, int);
void skip_comments(char *str);
/** MAIN PROGRAM */
/** main:get words from string and searches if it is keyword then it increments it count */
/* count C keywords; pointer version */ 
int main() 
{ 
	char word[MAXWORD]; 
	struct key *p; 
	while (getword(word, MAXWORD) != EOF) 
		if (isalpha(word[0]))
			if ((p=binsearch(word, keytab, NKEYS)) != NULL) 
				p->count++; 
	for (p = keytab; p < keytab + NKEYS; p++) 
		if (p->count > 0) 
			printf("%s %d\n", p->word, p->count); 
	return 0; 
} 
/* End main() */

/* binsearch: find word in tab[0]...tab[n-1] */ 
struct key *binsearch(char *word, struct key *tab, int n) 
{ 
	
	int cond; 
	struct key *low = &tab[0]; 
	struct key *high = &tab[n]; 
	struct key *mid; 
	while (low < high) { 
		mid = low + (high-low) / 2; 
		if ((cond = strcmp(word, mid->word)) < 0) 
			high = mid; 
		else if (cond > 0) 
			low = mid + 1; 
		else 
			return mid; 
	} 
	return NULL; 

}
void skip_comments(char *str)
{
	    int min= 0;
            int index=0,i=0;
  
    while (str[i] != '\0') {
        /* Check for line comments */
        if (str[i] == '/' && str[i + 1] == '/') {
            i += 2;
            // Skip characters until the end of the line or end of the string
            while (str[i] != '\n' && str[i] != '\0') {
                i++;
            }
        }
        /* Copy non-comment characters */
        if (str[i] != '\0') {
            str[index++] = str[i++];
        }
    }
    str[index] = '\0'; // Null-terminate the modified string
}
/* getword: get next word or character from input */ 
 int getword(char *word, int lim) 
 { 
 int c, getch(void); 
 void ungetch(int); 
 char *w = word; 
 while (isspace(c = getch())) 
 ; 
 if (c != EOF) 
 *w++ = c; 
 if (!isalpha(c)) { 
 *w = '\0'; 
 return c; 
 } 
 for ( ; --lim > 0; w++) 
 if (!isalnum(*w = getch())) { 
 ungetch(*w); 
 break; 
 } 
 *w = '\0'; 
 return word[0]; 
 } 
 char buf[BUFSIZE]; /* buffer for ungetch */
 int bufp = 0; /* next free position in buf */
 int getch(void) /* get a (possibly pushed-back) character */
 {
 return (bufp > 0) ? buf[--bufp] : getchar();
 }
 void ungetch(int c) /* push character back on input */
 {
 if (bufp >= BUFSIZE)
 printf("ungetch: too many characters\n");
 else
 buf[bufp++] = c;
 }

