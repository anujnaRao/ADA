#include<Stdio.h>

int x[30],count=0;

int place(int pos)
{
	int i;
	for(i=1;i<pos;i++)
	{
		if(  (x[i] == x[pos]) || (  abs(x[i]-x[pos]) == abs(i-pos) ) )
		 return 0;
	}
	return 1;
}

void printsolution(int n)
{
	int i,j;
	count++;
	
	printf("\nSoultion %d :\n",count);
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(x[i]==j)
			 printf("1\t");
			else
			 printf("0\t");
		}
		printf("\n");
	}
}

void queen(int n)
{
	int k=1;
	x[k]=0;
	
	while(k!= 0)
	{
		x[k]++;
		while(x[k]<=n && !place(k))
		 x[k]++;
		if(x[k]<=n)
		{
			if(k==n)
			 printsolution(n);
			else
			{
				k++;
				x[k]=0;
			}
		}
		else
		 k--;
	}
}

void main()
{
	int i,m,n;
	
	printf("Enter number of tests: \n");
	scanf("%d",&m);
	
	for(i=0;i<m;i++)
	{
		printf("Enter the number of queens:\n");
		scanf("%d",&n);
		
		if(n==1)
		{
		 printf("Trivial Solution\n");
	    } 
		else
		 {
	    	queen(n);
			printf("Total number of solutions found: %d\n",count);
			count = 0;
	   	 }
	}
}
