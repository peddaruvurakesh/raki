

/*Write the function strend(s,t), which returns 1 if the string t occurs at the end of the string s, and zero otherwise*/


#include <stdio.h>

/* strend: return 1 if string t occurs at the end of string s, 0 otherwise */
int strend(char s[], char t[]) {
    int i, j;

    // Find the lengths of s and t
    for (i = 0; s[i] != '\0'; i++);
    for (j = 0; t[j] != '\0'; j++);

    // If t is longer than s, it cannot occur at the end of s
    if (j > i) {
        return 0; // t is longer than s, so return 0
    }

    // Compare t with the end of s
    while (j > 0) {
        if (s[i - 1] != t[j - 1]) {
            return 0; // Mismatch, return 0
        }
        i--;
        j--;
    }

    return 1; // Match found, return 1
}

int main() {
    char s[100], t[100];

    // Input the first string
    printf("Enter the first string (s): ");
    fgets(s, sizeof(s), stdin);

    // Remove the newline character, if present
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '\n') {
            s[i] = '\0';
            break;
        }
    }

    // Input the second string
    printf("Enter the second string (t): ");
    fgets(t, sizeof(t), stdin);

    // Remove the newline character, if present
    for (int i = 0; t[i] != '\0'; i++) {
        if (t[i] == '\n') {
            t[i] = '\0';
            break;
        }
    }

    // Check if t occurs at the end of s
    if (strend(s, t)) {
        printf("1\n");  // Return 1 if t is found at the end of s
    } else {
        printf("0\n");  // Return 0 if t is not found at the end of s
    }

    return 0;
}

