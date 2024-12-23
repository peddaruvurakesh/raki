/* This program is to implement a simple version of the #define processor (i.e., no arguments) 
suitable for use with C programs, based on the routines of this section. You may also find 
getch and ungetch helpful. 

* Author: rakesh
* Created: 29 Aug, 2024
* Modified:29 Aug, 2024
*/
/** REQUIRED HEADER FILES */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
#define HASHSIZE 101
#define MAXLINE 1000

struct nlist {
    struct nlist *next;
    /* next entry in chain */
    char *name; 
    /* defined name */
    char *defn;
    /* replacement text */
};

static struct nlist *hashtab[HASHSIZE];
/* pointer table */

/* hash: form hash value for string s */
unsigned hash(char *s) {
    unsigned hashval;
    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

/* lookup: look for s in hashtab */
struct nlist *lookup(char *s) {
    struct nlist *np;
    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np; /* found */
    return NULL; /* not found */
}

/* install: put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn) {
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL) { 
	    /* not found */
        np = (struct nlist *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else {
	    /* already there */
        free((void *) np->defn); 
	/* free previous defn */
    }
    if ((np->defn = strdup(defn)) == NULL)
        return NULL;
    return np;
}

/* undef: remove a name and definition from the table */
void undef(char *name) {
    struct nlist *np, *prev = NULL;
    unsigned hashval = hash(name);

    for (np = hashtab[hashval]; np != NULL; prev = np, np = np->next) {
        if (strcmp(name, np->name) == 0) { 
		/* found the entry */
            if (prev == NULL) { 
		    /* first in the list */
                hashtab[hashval] = np->next;
            } else {
                prev->next = np->next;
            }
            free((void *)np->name);
            free((void *)np->defn);
            free((void *)np);
            return;
        }
    }
}

/* get_line: read a line into s, return length */
int get_line(char *s, int lim) {
    int c;
    char *t = s;

    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        *s++ = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';
    return s - t;
}

/* process_define: handle #define directives */
void process_define(char *line) {
    char name[MAXLINE], defn[MAXLINE];
    if (sscanf(line, "#define %s %[^\n]", name, defn) == 2) {
        install(name, defn);
    }
}

/* process_undef: handle #undef directives */
void process_undef(char *line) {
    char name[MAXLINE];
    if (sscanf(line, "#undef %s", name) == 1) {
        undef(name);
    }
}

/* replace_macros: replace macros in a line */
void replace_macros(char *line) {
    char word[MAXLINE];
    char result[MAXLINE] = "";
    char *p = line;
    struct nlist *np;
    int len;

    while (*p) {
        if (sscanf(p, "%s", word) == 1) {
            len = strlen(word);
            if ((np = lookup(word)) != NULL) {
                strcat(result, np->defn);
            } else {
                strncat(result, p, len);
            }
            p += len;
        }
        /* Add non-word characters (e.g., spaces, punctuation) to result */
        while (*p && !isalnum(*p) && *p != '_') {
            strncat(result, p, 1);
            p++;
        }
    }
    printf("%s\n", result);
}
/* main():content of main write here */
int main() {
    char line[MAXLINE];
    while (get_line(line, MAXLINE) > 0) {
        if (strncmp(line, "#define", 7) == 0) {
            process_define(line);
        } else if (strncmp(line, "#undef", 6) == 0) {
            process_undef(line);
        } else {
            replace_macros(line);
        }
    }
    return 0;
}
/* End of main */
