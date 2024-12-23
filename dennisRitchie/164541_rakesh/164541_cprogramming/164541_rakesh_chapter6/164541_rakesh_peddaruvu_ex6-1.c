/*
 * This program is to handle getword, which does not properly handle underscores, string constants, comments, or preprocessor control lines. Write a better version.
*/
/*
 * Author: rakesh
 * Created: 31 July, 2024
 * Modified:31 July, 2024
 */
/** REQUIRED HEADER FILES */
#include <stdio.h>
#include <ctype.h> 
#include <string.h> 
#include"error_handling.h"
/** MACRO DEFINITIONS */
#define RANGE 500
#define MAXWORD 500
#define NKEYS  (sizeof keytab / sizeof(keytab[0]))
/* structure */
struct key
{
	char sword[RANGE];
	int icount;
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
char* get_Word(char *, char*); 
struct key *binSearch(char *, struct key *, int);
void skip_Comments(char *str);
void skip_String_constants(char *str);
/** MAIN PROGRAM */
/** main:get words from string and searches if it is keyword then it increments it count */

int main() 
{ 
	char sword[MAXWORD],sone_word[MAXWORD]; 
	struct key *pPtr; 
	char cCh,cvar;
	do{
	int iIndex=0;
       
	while((cCh=getchar())!=EOF)
		sword[iIndex++]=cCh;
	    sword[iIndex] = '\0'; /* Null-terminate the string*/
	    if(iIndex>MAXWORD-1){
		    handle_error(ERROR_OUT_OF_RANGE);
		    return 1;
	    }

    /* Process the input string */
    skip_Comments(sword);
    skip_String_constants(sword);

    /* Extract and print words */
    char *cptr = sword;
    while ((cptr = get_Word(cptr, sone_word)) != NULL) {
		if (isalpha(sone_word[0])){
			if ((pPtr=binSearch(sone_word, keytab, NKEYS)) != NULL){ 
				pPtr->icount++; 
			}
		}
    }
	for (pPtr = keytab; pPtr < keytab + NKEYS; pPtr++) {
		if (pPtr->icount > 0) {
			printf("%s %d\n", pPtr->sword, pPtr->icount); 

    
    }
}
printf("do you want to continue (y/n)\n");
scanf(" %c",&cvar);
while(getchar()!='\n');
}while(cvar=='y'||cvar=='Y');
}
/* End main() */

/* binsearch: find word in tab[0]...tab[n-1] */ 
/*
 * Author: rakesh
 * Created: 31 July, 2024
 * Modified:31 July, 2024
 */
struct key *binSearch(char *word, struct key *tab, int n) 
{ 
	
	int cond; 
	struct key *low = &tab[0]; 
	struct key *high = &tab[n]; 
	struct key *mid; 
	while (low < high) { 
		mid = low + (high-low) / 2; 
		if ((cond = strcmp(word, mid->sword)) < 0) 
			high = mid; 
		else if (cond > 0) 
			low = mid + 1; 
		else 
			return mid; 
	} 
	return NULL; 

}

 char *get_Word(char *str, char *word) {
    int index = 0;

    /* Skip leading spaces */
    while (isspace(*str)) {
        str++;
    }

    /* Check if we reached the end of the string */
    if (*str == '\0') {
        return NULL;
    }

    /* Extract the word */
    while (*str != '\0' && !isspace(*str)) {
        word[index++] = *str++;
    }

    word[index] = '\0'; /* Null-terminate the word */

    /* Check if the extracted word is "#define" */
    if (strcmp(word, "#define") == 0) {
        /* Skip to the end of the line */
        while (*str != '\n' && *str != '\0') {
            str++;
        }
        /* Move past the newline character if present */
        if (*str == '\n') {
            str++;
        }
        /* Skip any leading spaces on the new line */
        while (isspace(*str)) {
            str++;
        }
        /* Extract the next word */
        index = 0;
        while (*str != '\0' && !isspace(*str)) {
            word[index++] = *str++;
        }
        word[index] = '\0'; /* Null-terminate the word */
    }

    /* Return the next position in the string or NULL if end of string */
    return (*str == '\0') ? NULL : str;
}
/* Function to skip comments (both line and block comments)*/
/*
 * Author: rakesh
 * Created: 31 July, 2024
 * Modified:31 July, 2024
 */
void skip_Comments(char *str) {
    int i = 0, j;
    while (str[i] != '\0') {
        if (str[i] == '/' && str[i + 1] == '/') {
            /* Skip line comments */
            i += 2;
            while (str[i] != '\n' && str[i] != '\0') {
                i++;
            }
        } else if (str[i] == '/' && str[i + 1] == '*') {
            /* Skip block comments */
            i += 2;
            while (!(str[i] == '*' && str[i + 1] == '/') && str[i] != '\0') {
                i++;
            }
            if (str[i] != '\0') {
                i += 2; /* Skip past the closing */
            }
        } else {
            i++;
        }
    }
}

/* Function to skip string constants */
/*
 * Author: rakesh
 * Created: 31 July, 2024
 * Modified:31 July, 2024
 */
void skip_String_constants(char *str) {
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
        } 
	else if (str[i] == '\'') {
            i++;
            while (str[i] != '\'' && str[i] != '\0') {
                i++;
            }
            if (str[i] == '\'') {
                i++;
            }
        } else {
            i++;
        }
    }
}
/* End skip_string_constants */
