#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0

int inc[50],set[50],n,sum,flag=0,total;

int promising(int i,int val,int total)
{
	return( (val+total>=sum) && ( val==sum || val+set[i+1]<=sum ) );
}

void sumset(int i,int val,int total)
{
	int j;
	if(promising(i,val,total))
	{
		if( val==sum )
		{
			printf("\n{");
			flag=1;
			for(j=0;j<=i;j++)
			 if(inc[j])
			  printf("\t%d",set[j]);
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
	int i,j,total=0,temp=-1;
	printf("How many numbers?\n");
	scanf("%d",&n);
	
	printf("Enter the set of numbers\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&set[i]);
		if(set[i] != temp)
		 temp=set[i];
		else
		{
			printf("Enter unique value\n");
			exit(0);
		}
		total+=set[i];
	}
	printf("Enter the sum\n");
	scanf("%d",&sum);
	
	if(total<sum)
	 printf("Subset sum is less than sum\n");
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

