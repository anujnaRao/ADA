#include<stdio.h>
#include<stdlib.h>

int fibonacci_recursive(int value)
{
	if(value == 0)
	 return 0;
	else if(value ==1)
	  return 1;
	else 
	  return (fibonacci_recursive(value-1)+fibonacci_recursive(value-2));
}

void main()
{
	int n,i;
	printf("Enter the value to calculate the Fibonacci Series: \n");
	scanf("%d",&n);
	printf("Fibonacci Series for %d\n: ",n);
	for(i=0;i<n;i++)
	{
		printf("%d\t",fibonacci_recursive(i));
	}
}

