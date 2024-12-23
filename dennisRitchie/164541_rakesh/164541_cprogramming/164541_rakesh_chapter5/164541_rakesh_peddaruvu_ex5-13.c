#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Program: Tail
 * Description: This program emulates the behavior of the Unix `tail` command.
 * It prints the last n lines of input, where n is specified as a command-line
 * argument. If no argument is provided, it defaults to printing the last 10 lines.
 *
 * Usage:
 *   ./a.out              -> Prints the last 10 lines of input.
 *   ./a.out -5           -> Prints the last 5 lines of input.
 *
 * Sample Input:
 *   Command: ./a.out -3
 *   Input from stdin:
 *       Line 1
 *       Line 2
 *       Line 3
 *       Line 4
 *       Line 5
 *
 *   Output:
 *       Line 3
 *       Line 4
 *       Line 5
 *
 *   Command: ./a.out
 *   Input from stdin:
 *       Line A
 *       Line B
 *       Line C
 *       Line D
 *       Line E
 *
 *   Output:
 *       Line B
 *       Line C
 *       Line D
 *       Line E
 */

/* Constants */
#define DEFLINES 10 /* Default number of lines to print */
#define LINES 100   /* Maximum number of lines to store */
#define MAXLEN 100  /* Maximum length of an input line */

/* Function Prototypes */
void error(const char *message);
int mgetline(char *s, int lim);

/* Main Function: Prints the last n lines of input */
int main(int argc, char *argv[]) {
    char *p;
    char *buf;       /* Pointer to the large buffer */
    char *bufend;    /* End of the large buffer */
    char line[MAXLEN];
    char *lineptr[LINES]; /* Array of pointers to lines read */

    int first, i, last, len, n, nlines;

    /* Determine the number of lines to print */
    if (argc == 1) {
        n = DEFLINES; /* Default to 10 lines */
    } else if (argc == 2 && argv[1][0] == '-') {
        n = atoi(argv[1] + 1); /* Parse the number after '-' */
        if (n <= 0) {
            error("Usage: tail [-n], where n is a positive integer");
        }
    } else {
        error("Usage: tail [-n]");
    }

    /* Limit n to the maximum allowed lines */
    if (n > LINES) {
        n = LINES;
    }

    /* Initialize line pointers */
    for (i = 0; i < LINES; i++) {
        lineptr[i] = NULL;
    }

    /* Allocate memory for the circular buffer */
    if ((p = buf = malloc(LINES * MAXLEN)) == NULL) {
        error("tail: cannot allocate buffer");
    }
    bufend = buf + LINES * MAXLEN;

    last = 0;   /* Points to the last line in the buffer */
    nlines = 0; /* Total number of lines read */

    /* Read input lines */
    while ((len = mgetline(line, MAXLEN)) > 0) {
        if (p + len + 1 >= bufend) {
            p = buf; /* Wrap around when buffer is full */
        }
        lineptr[last] = p; /* Store pointer to the current line */

        strcpy(lineptr[last], line); /* Copy line into the buffer */
        if (++last >= LINES) {
            last = 0; /* Wrap around in circular buffer */
        }

        p += len + 1; /* Move buffer pointer */
        nlines++;
    }

    /* Adjust n if the total number of lines is less than n */
    if (n > nlines) {
        n = nlines;
    }

    /* Calculate the starting position of the lines to print */
    first = last - n;
    if (first < 0) {
        first += LINES; /* Wrap around if negative */
    }

    /* Print the last n lines */
    for (i = first; n-- > 0; i = (i + 1) % LINES) {
        printf("%s", lineptr[i]);
    }

    /* Free allocated memory */
    free(buf);
    return 0;
}

/* error: Print an error message and exit */
void error(const char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

/* mgetline: Read a line into s and return its length */
int mgetline(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i++] = c;
    }
    s[i] = '\0'; /* Null-terminate the string */
    return i;
}

