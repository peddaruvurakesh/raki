/*
* This program is to write a cross-referencer that prints a list of all words in a document, and for each word, a list of the line numbers on which it occurs. Remove noise words like ``the,'' ``and,'' and so on.
* Author: rakesh
* Created: 2 sep, 2024
* Modified:2 sep, 2024
*/

/** REQUIRED HEADER FILES */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

/** MACRO DEFINITIONS */
#define MAXWORD 100

/* List of words to ignore */
const char *stopwords[] = {"i", "am", "from", "is", "the", "to", "and", "a", "an", NULL};

struct tnode { /* the tree node: */
    char *word; /* points to the text */
    int count; /* number of occurrences */
    int lines[MAXWORD]; /* store the line numbers */
    int linecount;
    struct tnode *left; /* left child */
    struct tnode *right; /* right child */
};

/** FUNCTION PROTOTYPES */
struct tnode *add_tree(struct tnode *, char *, int);
void treeprint(struct tnode *);
struct tnode *talloc(void);
char *str_dup(char *);
int getword(char *, int);
int is_stopword(const char *);
int line = 1;  // Track line number
/* main(): Removing noise words printing occurance in a line of a word */
int main() {
    struct tnode *root = NULL;
    char word[MAXWORD];

    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0]) && !is_stopword(word)) {
            root = add_tree(root, word, line);
        }
    }

    treeprint(root);
    return 0;
}
/* getword(): To get a word */
int getword(char *word, int lim) {
    int c, getch(void);
    void ungetch(int);
    char *w = word;

    while (isspace(c = getch())) {
        if (c == '\n') {
            line++;
        }
    }

    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }

    *w++ = c;
    for (; --lim > 0; w++) {
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
    }
    *w = '\0';
    return word[0];
}
/* is_stopword(): To skip noise words */
int is_stopword(const char *word) {
    for (int i = 0; stopwords[i] != NULL; i++) {
        if (strcmp(word, stopwords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

/* add_tree: add a node with w, at or below p */
struct tnode *add_tree(struct tnode *p, char *w, int line) {
    int cond;

    if (p == NULL) { 
	    /* a new word has arrived */
        p = talloc();
       	/* make a new node */
        p->word = str_dup(w);
        p->count = 1;
        p->lines[0] = line;
        p->linecount = 1;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0) {
        p->count++;
       	/* repeated word */
        p->lines[p->linecount++] = line;
    } else if (cond < 0) {
	    /* less than into left subtree */
        p->left = add_tree(p->left, w, line);
    } else {
	    /* greater than into right subtree */
        p->right = add_tree(p->right, w, line);
    }
    return p;
}

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p) {
    if (p != NULL) {
        treeprint(p->left);
        printf("%4d: %s", p->count, p->word);
        for (int i = 0; i < p->linecount; i++) {
            printf(" %d", p->lines[i]);
        }
        printf("\n");
        treeprint(p->right);
    }
}

struct tnode *talloc(void) {
    return (struct tnode *)malloc(sizeof(struct tnode));
}

char *str_dup(char *s) { 
	/* make a duplicate of s */
    char *p;
    p = (char *)malloc(strlen(s) + 1);
    /* +1 for '\0' */
    if (p != NULL)
        strcpy(p, s);
    return p;
}

#define BUFSIZE 100
char buf[BUFSIZE];
/* buffer for ungetch */
int bufp = 0; 
/* next free position in buf */

int getch(void) {
       	/* get a (possibly pushed-back) character */
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) { 
	/* push character back on input */
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

