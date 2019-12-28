#include<stdio.h>

int n,p[10][10];

int min(int a,int b){ return (a<b)? a:b;}

void path()
{
	int i,j,k;
	
	for(k=0;k<n;k++)
	 for(i=0;i<n;i++)
	  for(j=0;j<n;j++)
	   if(i == j)
	    p[i][j]=0;
	   else
		p[i][j]= min(p[i][j],p[i][k]+p[k][j]);	  
}

void main()
{
	int i,j;
	
	printf("Enter the number of nodes:\n");
	scanf("%d", &n);
	
	printf("Enter the adjacecy matrix:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&p[i][j]);
			if(p[i][j] ==0 && i!=0)
			  p[i][j] = 999;
		}
	}
	
	path();
	
	printf("Path Matrix:\n ");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",p[i][j]);
		}
		printf("\n");
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i!=j)
			{
				if(p[i][j] == 999)
				 printf("\n Distance from %d -> %d is  infinte\n",i+1,j+1);
				else
				 printf("\n Distance from %d -> %d is %d\n", i+1,j+1,p[i][j]);
			}
		}
	}
}
