/* This program is to write a function undef that will remove a name and definition from the table 
maintained by lookup and install. 
* Author: rakesh
* Created: 29 Aug, 2024
* Modified:29 Aug, 2024
*/
/** REQUIRED HEADER FILES */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* MACRO DEFINITIONS */
#define HASHSIZE 101

struct nlist {
    struct nlist *next;
    /* next entry in chain */
    char *name; 
    /* defined name */
    char *defn; 
    /* replacement text */
};

static struct nlist *hashtab[HASHSIZE]; /* pointer table */

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

    if ((np = lookup(name)) == NULL) { /* not found */
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
/*main(): removing a name from table */
int main() {
    install("key1", "value1");
    install("key2", "value2");
    install("key3", "value3");

    printf("Before undef:\n");
    struct nlist *result = lookup("key2");
    if (result)
        printf("Found: %s -> %s\n", result->name, result->defn);
    else
        printf("Not found\n");

    undef("key2");

    printf("After undef:\n");
    result = lookup("key2");
    if (result)
        printf("Found: %s -> %s\n", result->name, result->defn);
    else
        printf("Not found\n");

    return 0;
}
/* End of main() */
