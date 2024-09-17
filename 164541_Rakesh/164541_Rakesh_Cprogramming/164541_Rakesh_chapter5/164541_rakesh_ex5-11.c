/*This program is to modify the program entab and detab (written as exercises in Chapter 1) to accept a list of tab stops as arguments. Use the default tab settings if there are no arguments
 * Author: rakesh
 * Created: 18 July, 2024
 * Modified:18 July, 2024
 */
/** REQUIRED HEADER FILES */
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
/** MACRO DEFINITIONS */
#define WORDS 100
/** FUNCTION PROTOTYPES */
void en_tab(char*,int);
void de_tab(char*,int);
/** MAIN PROGRAM */
/** main: Accepts input through command line arguments and performs entab and detab*/
int main(int argc,char **argv)
{
	int x,n;
	//checking number of arguments at command prompt
	if(argc==1)
	{
		printf("not enough arguments\n");
		return 0;
	}
	if(argc==2){
		n=8;

	}
	else{
	 n=atoi(argv[2]);
	}
	   if ((strcmp(argv[1], "en") != 0) && (strcmp(argv[1], "de") != 0)) {
        printf("invalid entry\n");
        return 0;
	   }
	if(argc > 3) {
		printf("Usage : ./a.out en/de int \n");
		return 0;
	}
	char ch,str[WORDS];
	int cnt=0;
    

	//calling entab function
	if(strcmp(argv[1],"en")==0){
		while((ch=getchar())!=EOF)
			str[cnt++]=ch;
		str[cnt]='\0';
		en_tab(str,n);
	}
	//To call detab function

	else if(strcmp(argv[1],"de")==0){
                while((ch=getchar())!=EOF)
                        str[cnt++]=ch;
                str[cnt]='\0';

		de_tab(str,n);
	}
	else
		printf("error invalid call");

}
/** end of main */
//en_tab:include spaces with tabspace character
void en_tab(char *str,int spaces){
	int loop,count=0;
	for(loop=0;str[loop];loop++){
		if(str[loop]==' '){

			//incrementing spaces count
			count++;
			//printing upto n spaces and removing etra spaces
			if(count<spaces+1)
				printf("%c",str[loop]);
		}
		else{
			//if first character is space
			if(count!=0){
				if(count<spaces){
					for(;count<spaces;count++)
						printf("%c",' ');
				}
			}
			printf("%c",str[loop]);
			count=0;
		}

		if(str[loop]=='\n')
			count=0;
	}
}
/*End of en_tab*/
/*de_tab:replaces tab characters with the specified number of spaces.*/
void de_tab(char*str,int spaces){
int i,j;
	for (i = 0; str[i]; i++) {
		if (str[i] == '\\'&&str[i+1]=='t') {
			i++;
			for ( j = 0; j < spaces; j++) {
				printf(" ");
			}
		} else {
			printf("%c", str[i]);
		}
	}
}
/*End of de_tab*/

