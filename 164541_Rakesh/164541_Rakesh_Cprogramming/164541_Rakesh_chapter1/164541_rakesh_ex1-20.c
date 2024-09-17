/*This program detab that replaces tabs in the input with the proper number of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns. Should n be a variable or a symbolic parameter?
input is this\tis\ta\ttest
Name : rakesh
created :1 July,2024
Modified:1 July,2024
*/
/** REQUIRED HEADER FILES **/
#include<stdio.h>
/** MACROS DEFINITIONS **/
#define TAB 4

/* MAIN PROGRAM */
/*
 * main:(content of main write here)
 */
int main(){
char ch;
int count,i=0,index=0;
char str[100];
while((ch=getchar())!=EOF){
	str[i++]=ch;
}
str[i]='\0';
for(index=0;str[index]!='\0';index++){
if(str[index]=='\\'&&str[index+1]=='t'){
            int spaces= TAB - (count % TAB);
	while(spaces>0){
	putchar(' ');
		--spaces;
		count++;
	}
	index++;
}
else{
//writes the character
printf("%c",str[index]);
count++;
if(str[index]=='\n')
	count=0;
}
}
}
/* End  main() */
