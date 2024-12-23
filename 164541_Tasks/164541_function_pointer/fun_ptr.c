#include<stdio.h>

int add(int,int);

int main()
{
	
	int a=10;
	int b=20;
	int(*fp)(int,int);
	fp=&add;
	int sum=fp(a,b);
	printf("%d\n",sum);

}
int add(int a ,int b)
{
int c=a+b;
return c;
}
