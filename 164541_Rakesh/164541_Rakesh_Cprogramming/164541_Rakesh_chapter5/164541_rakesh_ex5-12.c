/*This program is to extend entab and detab to accept the shorthand  entab -m +n
to mean tab stops every n columns, starting at column m. Choose convenient (for the user) default behavior.  
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
void en_tab(char*,int,int ,int);
void de_tab(char*,int,int,int);
/** MAIN PROGRAM */
/** main: Accepts input through command line arguments and performs entab and detab*/
int main(int argc,char **argv)
{
	int n,m,spaces;
	//checking number of arguments at command prompt
	if(argc<3)
	{
		printf("not enough arguments also include -m +n num\n");
		return 0;
	}
	
	if (argv[2][0] == '-') {
        m= atoi(&argv[2][1]);
	}
         if (argv[3][0] == '+') {
        n= atoi(&argv[3][1]);
        }
	 spaces=atoi(argv[4]);
	//printf("%d %d %d",m,n,spaces);
	   if ((strcmp(argv[1], "en") != 0) && (strcmp(argv[1], "de") != 0)) {
        printf("invalid entry\n");

	}
	char ch,str[WORDS];
	int cnt=0;
    

	//calling entab function
	if(strcmp(argv[1],"en")==0){
		while((ch=getchar())!=EOF)
			str[cnt++]=ch;
		str[cnt]='\0';
		en_tab(str,m,n,spaces);
	}
	//To call detab function

	else if(strcmp(argv[1],"de")==0){
                while((ch=getchar())!=EOF)
                        str[cnt++]=ch;
                str[cnt]='\0';

		de_tab(str,m,n,spaces);
	}
	else
		printf("error invalid call");

}
/** end of main */
//en_tab:include spaces with tabspace character
void en_tab(char *str,int m,int n,int spaces){

	int loop,count=0,len=0;
	for(loop=0;str[loop];loop++){
		/* To check first m */
		if(loop==m){
			printf("\t");
		}
		/* for every n value */
		if(len==n){
			printf("\t");
			len=0;
		}
		if(str[loop]==' '){

			//incrementing spaces count
			count++;
			//printing upto n spaces and removing etra spaces
			if(count<spaces+1){
				printf("%c",str[loop]);
			if(loop>=m)
				len++;
		if(len==n){
			printf("\t");
			len=0;
		}
			}

		}
		else{
			//if first character is space
			if(count!=0){
				if(count<spaces){
					for(;count<spaces;count++){
						printf("%c",' ');
			if(loop>=m)
				len++;
		if(len==n){
			printf("\t");
			len=0;
		}
					}
				}
			}
			printf("%c",str[loop]);

			if(loop>=m)
				len++;
			count=0;
		}

		if(str[loop]=='\n')
			count=0;
	}
}
/*End of en_tab*/
/*de_tab:replaces tab characters with the specified number of spaces.*/
void de_tab(char*str,int m,int n,int spaces){
int loop,j,len=0;
	for (loop = 0; str[loop]; loop++) {
		if(loop==m){
			printf("\t");
		}
		if(len==n){
			printf("\t");
			len=0;
		}
		if (str[loop] == '\\'&&str[loop+1]=='t') {
			loop++;
			for ( j = 0; j < spaces; j++) {
				printf(" ");
			if(loop>=m)
				len++;
		if(len==n){
			printf("\t");
			len=0;

			}
			}
			} else {
			printf("%c", str[loop]);

			if(loop>=m)
				len++;
	
		}
	}
}
/*End of de_tab*/

