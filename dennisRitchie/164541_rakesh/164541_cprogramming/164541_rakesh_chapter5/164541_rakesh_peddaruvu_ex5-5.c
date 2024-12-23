#include <stdio.h>
#include <string.h>

void my_strncpy(char *s, const char *t, size_t n) {
    size_t i;
    // Copy up to n characters from t to s
    for (i = 0; i < n && t[i] != '\0'; i++) {
        s[i] = t[i];
    }
    
    // If t is shorter than n, fill the rest with '\0'
    for (; i < n; i++) {
        s[i] = '\0';
    }
}

void my_strncat(char *s, const char *t, size_t n) {
    size_t i = 0, j = 0;

    // Find the end of s
    while (s[i] != '\0') {
        i++;
    }

    // Append up to n characters from t to s
    while (t[j] != '\0' && j < n) {
        s[i++] = t[j++];
    }
    
    // Null-terminate the resulting string
    s[i] = '\0';
}

int my_strncmp(const char *s1, const char *s2, size_t n) {
    size_t i = 0;
    while (i < n && s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) {
            return (unsigned char)s1[i] - (unsigned char)s2[i];
        }
        i++;
    }

    // If one string is shorter than the other, consider the null character
    if (i < n) {
        return (unsigned char)s1[i] - (unsigned char)s2[i];
    }

    return 0;  // Strings are equal up to n characters
}

int main() {
    char s1[100], s2[100], s3[100];
    const char *t;
    size_t n;

    // Input for first string
    printf("Enter the first string: ");
    fgets(s1, sizeof(s1), stdin);
    s1[strcspn(s1, "\n")] = '\0'; // Remove the newline character

    // Input for second string
    printf("Enter the second string: ");
    fgets(s2, sizeof(s2), stdin);
    s2[strcspn(s2, "\n")] = '\0'; // Remove the newline character

    // Input for n
    printf("Enter the value of n: ");
    scanf("%zu", &n);

    // Clear the buffer after reading the integer
    getchar();

    // Test my_strncpy
    printf("\nTesting my_strncpy:\n");
    my_strncpy(s3, s2, n);  // Copy up to n characters from s2 to s3
    printf("Result of my_strncpy: %s\n", s3);

    // Test my_strncat
    printf("\nTesting my_strncat:\n");
    my_strncat(s1, s2, n);  // Append up to n characters from s2 to s1
    printf("Result of my_strncat: %s\n", s1);

    // Test my_strncmp
    printf("\nTesting my_strncmp:\n");
    int result = my_strncmp(s1, s2, n);  // Compare the first n characters of s1 and s2
    if (result == 0) {
        printf("Result of my_strncmp: Strings are equal for the first %zu characters.\n", n);
    } else if (result < 0) {
        printf("Result of my_strncmp: The first string is lexicographically less than the second string.\n");
    } else {
        printf("Result of my_strncmp: The first string is lexicographically greater than the second string.\n");
    }

    return 0;
}

