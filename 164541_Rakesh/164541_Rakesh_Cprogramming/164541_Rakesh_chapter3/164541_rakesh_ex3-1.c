/*This program is to change binary search which makes two tests inside the loop, when one would suffice (at 
  the price of more tests outside.) Write a version with only one test inside the loop and measure the difference in run-time
 * Author: rakesh
 * Created: 4 July, 2024
 * Modified:16 July, 2024
 */

/** REQUIRED HEADER FILES */
#include <stdio.h>

/** Macro definitions */
//#define RANGE 4

/** FUNCTION PROTOTYPES */
int binsearch(int x, int v[], int n);
void bubblesort(int a[],int n);
/** MAIN PROGRAM */
/** main: calls escape function*/
int main(){
	int RANGE;
        printf("number of array elements");
	scanf("%d",&RANGE);
	int v[RANGE];
	int number;
	int index,value;
	/* enter array elements of given range */ 
	printf("Enter an array\n");
	for(index=0;index<RANGE;index++){
		scanf("%d",&v[index]);
	}
	printf("enter an number to search\n");
	scanf("%d",&number);
	value=binsearch(number,v,RANGE);
	if(value==-1)
	{
		printf("element %d not found in array\n",number);
	}
	else{
	printf("element %d found in array at index %d\n",number,value);
	}
}
/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
	int low, high, mid,i;
	low = 0;
	high = n;
	int index;
	for(index=0;index<n;index++)
	{
		if(v[index]>v[index+1]){
			printf("array is not sorted, sorting an array\n");
			bubblesort(v,n);
			for(i=0;i<n;i++)
				printf("%d ",v[i]);
			printf("\n");
		}
	}
		
	while (low <= high) {
		mid = (low+high)/2;
		if (x == v[mid])
			return mid;
		else if (x > v[mid])
			low = mid + 1;
		else 
			high = mid - 1;
	}
	return -1; /* no match */

}
/* End of binsearch */
/* bubble sort():to sort an array*/
void bubblesort(int a[],int n){
	int i,j,temp;
        for(i=0;i<n-1;i++)
        {
                for(j=0;j<n-1-i;j++)
                {
                        if(a[j]>a[j+1])
                        {
                                temp = a[j];
                                a[j] = a[j+1];
                                a[j+1] = temp;
                        }
                }
        }
}

