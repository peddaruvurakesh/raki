/*This program is to entab that replaces strings of blanks by the minimum number of tabs and blanks to achieve the same 
 * spacing. Use the same tab stops as for detab.When either a tab or a single blank would suffice to reach a tab stop, which should 
 * be given preference?
 * if spaces are more than tabspaces then it replace spaces with tabspace 
Name    : rakesh
created :1 July,2024
Modified:1 July,2024 */
/** REQUIRED HEADER FILES **/
#include<stdio.h>
/** MACROS DEFINITIONS **/
#define TAB 4
/** FUNCTION PROTOTYPES**/
/* MAIN PROGRAM */
/*
 * main:(content of main)
 */
int main(){
	int count=0,i=0,ch;
	int spaces =TAB;
	char str[80];
	while((ch=getchar())!=EOF){
		str[i++]=ch;
	}
	str[i]='\0';
	for(i=0;str[i];i++){
		if(str[i]==' '){
			//incrementing spaces count
			++count;
			if(count>=spaces){

				printf("\\t");
				count=0;
			}
		}
		else
			printf("%c",str[i]);
		if(str[i]=='\n')
			count=0;
	}
}
/* End  main() */
