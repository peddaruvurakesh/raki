/*
* This program is to 
* Author: rakesh
* Created: 1 Aug , 2024
* Modified:1 Aug, 2024
*/
/** REQUIRED HEADER FILES */
#include <stdio.h>
 #include <string.h>
/** MACRO DEFINITIONS */
#define MAXLEN 1000
 #define MAXLINES 5000 /* max #lines to be sorted */
/** FUNCTION PROTOTYPES */
/** MAIN PROGRAM */
/** main: Accepts */
 char *lineptr[MAXLINES]; /* pointers to text lines */
 int readlines(char *lineptr[], int nlines);
 void writelines(char *lineptr[], int nlines);
 void q_sort(void *lineptr[], int left, int right,
 int (*comp)(void *, void *));
 int numcmp(char *, char *);
 /* sort input lines */
int  main(int argc, char *argv[])
 {
 int nlines; /* number of input lines read */
 int numeric = 0; /* 1 if numeric sort */
 if (argc > 1 && strcmp(argv[1], "-n") == 0)
 numeric = 1;
 if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
 q_sort((void**) lineptr, 0, nlines-1,
 (int (*)(void*,void*))(numeric ? numcmp : strcmp));
 writelines(lineptr, nlines);
 return 0;
 } else {
 printf("input too big to sort\n");
 return 1;
 }
 }
/* End main() */
 /* qsort: sort v[left]...v[right] into increasing order */
 void q_sort(void *v[], int left, int right,
 int (*comp)(void *, void *))
 {
 int i, last;
 void swap(void *v[], int, int);
 if (left >= right) /* do nothing if array contains */
 return; /* fewer than two elements */
 swap(v, left, (left + right)/2);
 last = left;
 for (i = left+1; i <= right; i++)
 if ((*comp)(v[i], v[left]) < 0)
 swap(v, ++last, i);
 swap(v, left, last);
 q_sort(v, left, last-1, comp);
 q_sort(v, last+1, right, comp);
 }
/* numcmp: compare s1 and s2 numerically */ 
#include<stdlib.h>
 int numcmp(char *s1, char *s2) 
 { 
 double v1, v2; 
 v1 = atof(s1); 
 v2 = atof(s2); 
 if (v1 < v2) 
 return -1; 
 else if (v1 > v2) 
 return 1; 
 else 
 return 0; 
 } 
void swap(void *v[], int i, int j) 
 { 
 void *temp; 
 temp = v[i]; 
 v[i] = v[j]; 
 v[j] = temp; 
 } 
 int getline(char *, int); 
 char *alloc(int); 
 /* readlines: read input lines */ 
 int readlines(char *lineptr[], int maxlines) 
 { 
 int len, nlines; 
 char *p, line[MAXLEN]; 
 nlines = 0; 
 while ((len = getline(line, MAXLEN)) > 0) 
 if (nlines >= maxlines || p == alloc(len) = NULL) 
 return -1; 
 else {  
 line[len-1] = '\0'; /* delete newline */ 
 strcpy(p, line); 
 lineptr[nlines++] = p; 
 } 
 return nlines; 
 } 
 /* writelines: write output lines */ 
 void writelines(char *lineptr[], int nlines) 
 { 
 int i; 
 for (i = 0; i < nlines; i++) 
 printf("%s\n", lineptr[i]); 
 } 
 /* getline: get line into s, return length */
 int getline(char *s, int lim)
 {
 int c, i;
 i = 0;
 while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
 *s++ = c;
 if (c == '\n')
 *s++ = c;
 *s= '\0';
 return i;
 }
