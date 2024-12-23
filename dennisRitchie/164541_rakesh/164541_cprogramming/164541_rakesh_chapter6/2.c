/*This program reads a C program and prints in alphabetical order each 
  group of variable names that are identical in the first 6 characters, but different somewhere 
  thereafter. Don't count words within strings and comments. Make 6 a parameter that can be 
  set from the command line.

 * Author: rakesh
 * Created: 2 sep, 2024
 * Modified:2 sep, 2024
 */

/** REQUIRED HEADER FILES */
#include <stdio.h>
#include <stdio.h> 
#include <ctype.h> 
#include <stdlib.h> 
#include <string.h>
/* MACRO DEFINITIONS */
#define MAXWORD 100 

/* STRUCTURE */
struct tnode { 
	/* the tree node: */ 
	char *word;
       	/* points to the text */ 
	int count;
       	/* number of occurrences */ 
	struct tnode *left;
       	/* left child */ 
	struct tnode *right; 
	/* right child */ 
}; 
/* FUNCTION PROTOTYPES */
struct tnode *add_tree(struct tnode *, char *,int); 
void treeprint(struct tnode *); 
struct tnode *talloc(void);
char *str_dup(char *);
int getword(char *, int); 
/* word frequency count */ 
int main(int argc ,char*argv[]) 
{ 
	if(argc<2)
	{
		printf("usage ./a.out num\n");
		return 1;
	}
	int num=atoi(argv[1]);
	struct tnode *root; 
	char word[MAXWORD]; 
	root = NULL; 
	while (getword(word, MAXWORD) != EOF) 
		if (isalpha(word[0])) 
			root = add_tree(root, word,num); 
	treeprint(root); 
	return 0; 
}
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
/* addtree: add a node with w, at or below p */
struct tnode *add_tree(struct tnode *p, char *w,int num)
{
	int cond;
	if (p == NULL) { 
		/* a new word has arrived */
		p = talloc();
	       	/* make a new node */
		p->word = str_dup(w);
		p->count = 1;
		p->left = p->right = NULL;
	} else if ((cond = strncmp(w, p->word,num)) == 0)
		p->count++; 
	/* repeated word */
	else if (cond < 0)
	       	/* less than into left subtree */
		p->left = add_tree(p->left, w,num);
	else 
		/* greater than into right subtree */
		p->right = add_tree(p->right, w,num);
	return p;
}
/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p)
{
	if (p != NULL) {
		treeprint(p->left);
		//printf("%4d %s\n", p->count, p->word);
		printf("%s\n", p->word);
		treeprint(p->right);
	}
}
struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}
char *str_dup(char *s)
       	/* make a duplicate of s */
{
	char *p;
	p = (char *) malloc(strlen(s)+1); /* +1 for '\0' */
	if (p != NULL)
		strcpy(p, s);
	return p;
}
#define BUFSIZE 100
char buf[BUFSIZE]; 
/* buffer for ungetch */
int bufp = 0;
/* next free position in buf */
int getch(void) 
	/* get a (possibly pushed-back) character */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c) 
	/* push character back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
/* End ungetch() */
