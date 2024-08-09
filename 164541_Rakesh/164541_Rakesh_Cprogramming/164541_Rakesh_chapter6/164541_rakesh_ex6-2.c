/*
 * This program is to handle getword, which does not properly handle underscores, string constants, comments, or preprocessor control lines. Write a better version.
 * Author: rakesh
 * Created: 31 July, 2024
 * Modified:31 July, 2024
 */
/** REQUIRED HEADER FILES */
#include <stdio.h>
#include <ctype.h> 
#include <string.h> 

/** MACRO DEFINITIONS */
#define RANGE 500
#define MAXWORD 500
#define NKEYS  (sizeof keytab / sizeof(keytab[0]))
struct key
{
	char word[RANGE];
	int count;
}keytab[]={
	{"auto", 0},
	{"break", 0},
	{"case", 0},
	{"char", 0},
	{"const", 0},
	{"continue", 0},
	{"default", 0},
	{"do", 0},
	{"double", 0},
	{"else", 0},
	{"enum", 0},
	{"extern", 0},
	{"float", 0},
	{"for", 0},
	{"goto", 0},
	{"if", 0},
	{"int", 0},
	{"long", 0},
	{"register", 0},
	{"return", 0},
	{"short", 0},
	{"signed", 0},
	{"size_t", 0},
	{"sizeof", 0},
	{"static", 0},
	{"struct", 0},
	{"switch", 0},
	{"typedef", 0},
	{"union", 0},
	{"unsigned", 0},
	{"void", 0},
	{"volatile", 0},
	{"while", 0},	
};


/** FUNCTION PROTOTYPES */
char* get_word(char *, char*); 
struct key *binsearch(char *, struct key *, int);
void skip_comments(char *str);
void skip_string_constants(char *str);
/** MAIN PROGRAM */
/** main:get words from string and searches if it is keyword then it increments it count */

int main() 
{ 
	char word[MAXWORD],one_word[MAXWORD]; 
	struct key *p; 
	char ch;
	int index=0;
	while((ch=getchar())!=EOF)
		word[index++]=ch;
	    word[index] = '\0'; // Null-terminate the string

    // Process the input string
    skip_comments(word);
    skip_string_constants(word);

    // Extract and print words
    char *ptr = word;
    while ((ptr = get_word(ptr, one_word)) != NULL) {
		if (isalpha(one_word[0])){
			if ((p=binsearch(one_word, keytab, NKEYS)) != NULL){ 
				p->count++; 
			}
		}
    }
	for (p = keytab; p < keytab + NKEYS; p++) {
		if (p->count > 0) {
			printf("%s %d\n", p->word, p->count); 

    
    }
}
}
/* End main() */

/* binsearch: find word in tab[0]...tab[n-1] */ 
struct key *binsearch(char *word, struct key *tab, int n) 
{ 
	
	int cond; 
	struct key *low = &tab[0]; 
	struct key *high = &tab[n]; 
	struct key *mid; 
	while (low < high) { 
		mid = low + (high-low) / 2; 
		if ((cond = strcmp(word, mid->word)) < 0) 
			high = mid; 
		else if (cond > 0) 
			low = mid + 1; 
		else 
			return mid; 
	} 
	return NULL; 

}

 char *get_word(char *str, char *word) {
    int index = 0;

    // Skip leading spaces
    while (isspace(*str)) {
        str++;
    }

    // Check if we reached the end of the string
    if (*str == '\0') {
        return NULL;
    }

    // Extract the word
    while (*str != '\0' && !isspace(*str)) {
        word[index++] = *str++;
    }

    word[index] = '\0'; // Null-terminate the word

    // Check if the extracted word is "#define"
    if (strcmp(word, "#define") == 0) {
        // Skip to the end of the line
        while (*str != '\n' && *str != '\0') {
            str++;
        }
        // Move past the newline character if present
        if (*str == '\n') {
            str++;
        }
        // Skip any leading spaces on the new line
        while (isspace(*str)) {
            str++;
        }
        // Extract the next word
        index = 0;
        while (*str != '\0' && !isspace(*str)) {
            word[index++] = *str++;
        }
        word[index] = '\0'; // Null-terminate the word
    }

    // Return the next position in the string or NULL if end of string
    return (*str == '\0') ? NULL : str;
}
// Function to skip comments (both line and block comments)
void skip_comments(char *str) {
    int i = 0, j;
    while (str[i] != '\0') {
        if (str[i] == '/' && str[i + 1] == '/') {
            // Skip line comments
            i += 2;
            while (str[i] != '\n' && str[i] != '\0') {
                i++;
            }
        } else if (str[i] == '/' && str[i + 1] == '*') {
            // Skip block comments
            i += 2;
            while (!(str[i] == '*' && str[i + 1] == '/') && str[i] != '\0') {
                i++;
            }
            if (str[i] != '\0') {
                i += 2; // Skip past the closing 
            }
        } else {
            i++;
        }
    }
}

// Function to skip string constants
void skip_string_constants(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '\"') {
            i++;
            while (str[i] != '\"' && str[i] != '\0') {
                i++;
            }
            if (str[i] == '\"') {
                i++;
            }
        } else {
            i++;
        }
    }
}
