/*
* This program is to do  that prints the distinct words in its input sorted into decreasing 
order of frequency of occurrence. Precede each word by its count. 
* Author: rakesh
* Created: 28 Aug, 2024
* Modified:28 Aug, 2024
*/
/** REQUIRED HEADER FILES */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

/* MACRO DEFINITION */
#define MAXWORD 100

struct tnode {
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
struct tnode *add_tree(struct tnode *, char *);
void store_nodes(struct tnode *, struct tnode **, int *);
void sort_nodes(struct tnode **, int);
void treeprint(struct tnode **, int);
struct tnode *talloc(void);
char *str_dup(char *);
int getword(char *, int);
/* main(): Adding words and counting its occurance and sorts it */
int main() {
    struct tnode *root = NULL;
    char word[MAXWORD];
    /*calling functions to add words in tree */
    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0])) {
            root = add_tree(root, word);
        }
    }

    int node_count = 0;
    struct tnode *nodes[MAXWORD];
    store_nodes(root, nodes, &node_count); 
    /* Store nodes in array */
    sort_nodes(nodes, node_count);
    /* Sort nodes by frequency */
    treeprint(nodes, node_count);   
    /* Print nodes in sorted order */

    return 0;
}
/* getword(): To get a word from input */
int getword(char *word, int lim) {
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

    for (; --lim > 0; w++) {
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
    }

    *w = '\0';
    return word[0];
}
/* add_tree():To add words in a tree */
struct tnode *add_tree(struct tnode *p, char *w) {
    int cond;

    if (p == NULL) {
        p = talloc();  /*  make a new node */
        p->word = str_dup(w);
        p->count = 1;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0) {
        p->count++;  /* repeated word */
    } else if (cond < 0) {
        p->left = add_tree(p->left, w);
    } else {
        p->right = add_tree(p->right, w);
    }

    return p;
}

void store_nodes(struct tnode *p, struct tnode **nodes, int *index) {
    if (p != NULL) {
        store_nodes(p->left, nodes, index);
        nodes[(*index)++] = p;
        store_nodes(p->right, nodes, index);
    }
}
/* sort_nodes: sorting nodes in descending order */
void sort_nodes(struct tnode **nodes, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
		/* swapping nodes */
            if (nodes[i]->count < nodes[j]->count) {
                struct tnode *temp = nodes[i];
                nodes[i] = nodes[j];
                nodes[j] = temp;
            }
        }

    }
}
/*treeprint(): To print data(words) in tree */
void treeprint(struct tnode **nodes, int n) {
    for (int i = 0; i < n; i++) {
        printf("%4d : %s\n", nodes[i]->count, nodes[i]->word);
    }
}
/* talloc(): Allocates memory dynamically */
struct tnode *talloc(void) {
    return (struct tnode *)malloc(sizeof(struct tnode));
}

char *str_dup(char *s) {
    char *p = (char *)malloc(strlen(s) + 1);
    if (p != NULL)
        strcpy(p, s);
    return p;
}
/* getch and ungetch */
#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
/* End of ungetch */
