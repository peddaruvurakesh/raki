#include <stdio.h>
#include <string.h>

/* Function prototypes */
int get_line(char *s, int lim);
int atoi(char *s);
void itoa(int n, char *s);
void reverse(char *s);
int strindex(char *s, char *t);

int main() {
    /* Test getline */
    char line[100];
    printf("Enter a line: ");
    int len = get_line(line, 100);
    printf("You entered: %s (length: %d)\n", line, len);

    /* Test atoi */
    char numStr[20];
    printf("Enter a number as a string: ");
    get_line(numStr, 20);
    int number = atoi(numStr);
    printf("String to integer conversion of '%s': %d\n", numStr, number);

    /* Test itoa */
    int num;
    printf("Enter an integer to convert to string: ");
    scanf("%d", &num);
    char numBuffer[20];
    itoa(num, numBuffer);
    printf("Integer to string conversion of %d: %s\n", num, numBuffer);

    /* Clear input buffer for next input */
    getchar();

    /* Test reverse */
    char toReverse[100];
    printf("Enter a string to reverse: ");
    get_line(toReverse, 100);
    reverse(toReverse);
    printf("Reversed string: %s\n", toReverse);

    /* Test strindex */
    char text[200], pattern[50];
    printf("Enter a text: ");
    get_line(text, 200);
    printf("Enter a pattern to find: ");
    get_line(pattern, 50);
    int index = strindex(text, pattern);
    if (index != -1)
        printf("Last occurrence of '%s' in text: %d\n", pattern, index);
    else
        printf("Pattern '%s' not found in text.\n", pattern);

    return 0;
}

/* getline: reads a line from input into a string using pointers */
int get_line(char *s, int lim) {
    char *start = s;
    int c;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        *s++ = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';
    return s - start;
}

/* atoi: converts a string to an integer using pointers */
int atoi(char *s) {
    int n = 0;
    while (*s >= '0' && *s <= '9') {
        n = 10 * n + (*s - '0');
        s++;
    }
    return n;
}

/* itoa: converts an integer to a string using pointers */
void itoa(int n, char *s) {
    char *start = s;
    int sign;
    if ((sign = n) < 0)
        n = -n;
    do {
        *s++ = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
        *s++ = '-';
    *s = '\0';
    reverse(start);
}

/* reverse: reverses a string in place using pointers */
void reverse(char *s) {
    char *end = s + strlen(s) - 1;
    char temp;
    while (s < end) {
        temp = *s;
        *s = *end;
        *end = temp;
        s++;
        end--;
    }
}

/* strindex: finds the index of the last occurrence of t in s using pointers */
int strindex(char *s, char *t) {
    char *s_start = s, *t_start = t;
    for (; *s != '\0'; s++) {
        char *s_temp = s, *t_temp = t_start;
        while (*t_temp != '\0' && *s_temp == *t_temp) {
            s_temp++;
            t_temp++;
        }
        if (*t_temp == '\0')
            return s - s_start;
    }
    return -1;
}

