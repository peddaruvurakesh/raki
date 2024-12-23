#include <sys/types.h>
#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/wait.h>
#include<string.h>
void reverse(char str[], int length) {
	int start = 0;
	int end = length - 1;
	while (start < end) {
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}
char* itoa(int num, char* str, int base) {
	int i = 0;
	int isNegative = 0;

	// Handle 0 explicitly
	if (num == 0) {
		str[i++] = '0';
		str[i] = '\0';
		return str;
	}

	// Handle negative numbers for base 10
	if (num < 0 && base == 10) {
		isNegative = 1;
		num = -num;
	}

	// Process individual digits
	while (num != 0) {
		int rem = num % base;
		str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		num = num / base;
	}

	// Append '-' for negative numbers
	if (isNegative) {
		str[i++] = '-';
	}

	str[i] = '\0'; // Append null terminator

	// Reverse the string
	reverse(str, i);

	return str;
}
int main()
{
	int A[2],B[2],C[2];
	char buff[15]="1",value[15];
	if(pipe(A)<0)
	{
		printf("pipe A creation failed\n");
		return 0;
	}
	if(pipe(B)<0)
	{
		printf("pipe B creation failed\n");
		return 0;
	}
	if(pipe(C)<0)
	{
		printf("pipe C creation failed\n");
		return 0;
	}


	int child=fork();
	if(child==-1)
	{
		printf("the first fork failed.");
		exit(-1);
	}
	if(child==0)
	{

		int grand_child=fork();
		if(grand_child==-1)
		{
			printf("the second fork failed.");
			exit(-1);
		}
		if(grand_child==0)
		{
			long M;
			printf("grand child is ready to proceed\n");
			//pipe C read end pipe B write end
			while(1)
			{
				bzero(buff,sizeof(buff));
				bzero(value,sizeof(value));

				read(C[0],value,15);
				M=atoi(value);
				M=30-4*M;
				printf("grand child value:%ld\n",M);
				itoa(M,buff,10);

				write(B[1],buff,strlen(buff));
				 if(M<-999999999 || M>999999999)
                                break;
			}
			exit(0);

		}
		else
		{
			long M;
			printf("Child process is ready to proceed\n");
			//pipe A write end pipe B read end
			while(1) 
			{
				bzero(buff,sizeof(buff));
				bzero(value,sizeof(value));
				read(B[0],value,15);
				M=atoi(value);
				M=7*M-6;
				printf("Child value:%ld\n",M);
				itoa(M,buff,10);

				write(A[1],buff,strlen(buff));
				 if(M>999999999 || M<-999999999)
                                        break;

			}
			wait(0);
			exit(0);
		}
	}
	else
	{
		long M=1;
		printf("parent process is ready to proceed\n");
		 printf("Parent value:%ld\n",M);
		write(C[1],buff,strlen(buff));
		while(1)
		{
			bzero(buff,sizeof(buff));
			bzero(value,sizeof(value));
			read(A[0],value,15);
			M=atoi(value);
			M=200-3*M;
			printf("Parent value:%ld\n",M);
			itoa(M,buff,10);

			write(C[1],buff,strlen(buff));
			 if(M<-999999999 || M>999999999)
                                break;



		}
		wait(0);
		exit(0);
		
	}


}

