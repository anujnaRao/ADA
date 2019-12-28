#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0

int inc[50], set[50],sum,n,flag=0;

int promising(int i,int val,int total)
{
	return(  (val+total>= sum) && (  val==sum || val+set[i+1] <=sum ) );
}

void sumset(int i,int val,int total)
{
	int j;
	if(promising(i,val,total))
	{
		if( val == sum)
		{
			printf("\n{");
			flag=1;
			for(j=0;j<=i;j++)
			 if(inc)
			  printf("%d\t",set[j]);
			printf("}\n");
		}
		else
		{
			inc[i+1]=TRUE;
			sumset(i+1,val+set[i+1],total-set[i+1]);
			inc[i+1]=FALSE;
			sumset(i+1,val,total-set[i+1]);
		}
	}
}

void main()
{
	int i,j,temp[50],val,total=0;
	
	printf("How many numbers to enter?\n");
	scanf("%d",&n);
	
	printf("Enter the numbers:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&set[i]);
		temp[i]=set[i];
	}
	 
	for(j=0;j<=n;j++)
	{
		if(temp[j]==set[j+1])
		{
			printf("Please enter unique numbers\n");
			exit(0);
		}
		total+=set[j];
	}
	printf("Enter the sum :\n");
	scanf("%d",&sum);
	
	if(total<sum)
	 printf("Subset sum can not be calculated\n");
	else
	{
		for(i=0;i<n;i++)
		 inc[i]=0;
		 printf("\nSolution ");
	}
	sumset(-1,0,total);
	if(!flag)
	 printf("not found\n");
}

