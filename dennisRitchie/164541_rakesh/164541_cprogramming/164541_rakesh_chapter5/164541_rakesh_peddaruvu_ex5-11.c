#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 100 /* Maximum line size */
#define TABINC 8    /* Default tab increment size */
#define YES 1
#define NO 0

void esettab(int argc, char *argv[], char *tab);
void detab(char *tab);
int tabpos(int pos, char *tab);

/* Replace tabs with blanks */
int main(int argc, char *argv[]) {
    char tab[MAXLINE + 1];

    if (argc == 1) {  // No arguments provided
        printf("Not enough arguments\n");
        return 1;
    }

    if (argc == 2 && (*argv[1] != '-' && *argv[1] != '+')) {
        printf("Invalid Entry!!!\n");
        return 1;
    }

    esettab(argc, argv, tab);
    detab(tab);

    return 0;
}

/* esettab: set tab stops */
void esettab(int argc, char *argv[], char *tab) {
    int i, inc, pos;

    if (argc <= 1) { /* Default tab stops */
        for (i = 1; i <= MAXLINE; i++) {
            if (i % TABINC == 0) {
                tab[i] = YES;
            } else {
                tab[i] = NO;
            }
        }
    } else if (argc == 3 && *argv[1] == '-' && *argv[2] == '+') { /* User-provided range */
        pos = atoi(&(*++argv)[1]);
        inc = atoi(&(*++argv)[1]);

        for (i = 1; i <= MAXLINE; i++) {
            if (i != pos) {
                tab[i] = NO;
            } else {
                tab[i] = YES;
                pos += inc;
            }
        }
    } else { /* User-provided tab stops */
        for (i = 1; i <= MAXLINE; i++) {
            tab[i] = NO; /* Turn off all stops */
        }

        while (--argc > 0) { /* Walk through argument list */
            pos = atoi(*++argv);
            if (pos > 0 && pos <= MAXLINE) {
                tab[pos] = YES;
            }
        }
    }
}

/* detab: replace tabs with blanks */
void detab(char *tab) {
    int c, pos = 1;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            do {
                putchar(' ');
            } while (tabpos(pos++, tab) != YES);
        } else if (c == '\n') {
            putchar(c);
            pos = 1;
        } else {
            putchar(c);
            ++pos;
        }
    }
}

/* tabpos: determine if pos is a tab stop */
int tabpos(int pos, char *tab) {
    if (pos > MAXLINE) {
        return YES;
    } else {
        return tab[pos];
    }
}

