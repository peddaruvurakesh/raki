#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main (int argc,char *argv[]){
if (argc !=4)
printf("enter only 3 arguements ");

double result;
	if(!strcmp(argv[1],"add"))
	{
	result = atof(argv[2])+atof(argv[3]);
	}
 else if(!strcmp(argv[1],"sub")){
	 result = atof(argv[2])- atof(argv[3]);
 }
	 else if(!strcmp(argv[1],"multiplication"))
	 {
		 result = atof(argv[2])*atof(argv[3]);
	 }

	 printf("result : %f ",result);
	 return 0;
}
