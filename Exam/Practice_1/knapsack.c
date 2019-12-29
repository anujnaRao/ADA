#include<stdio.h>

int max(int a,int b){return (a>b)?a:b;}

int knapsack(int Weight,int obj[],int val[],int n)
{
	int i,j,x[n],k[n+1][Weight+1];
	
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=Weight;j++)
		{
			if( i==0 || j==0)
			 k[i][j]=0;
			else if( obj[i-1] <=j)
			 k[i][j]= max(k[i-1][j],k[i-1][j-obj[i-1]]+ val[i-1]);
			else
			 k[i][j]=k[i-1][j];
		}
	}
	
	printf("Prfoit Matrix\n");
	for(i=0;i<=n;i++)
	{
		if(i!=n)
		 x[i]=0;
		for(j=0;j<=Weight;j++)
			printf("%d\t",k[i][j]);
		printf("\n");
	}
	
	i=n;
	j=Weight;
	
	while(i!=0 && j!=0)
	{
		if( k[i][j] != k[i-1][j])
		{
			x[i]=1;
			j=j-obj[i-1];
		}
		i--;
	}
	
	printf("Selected Objects are:\n");
	for(i=0;i<n;i++)
	 printf("%d\t",obj[i]);
	printf("\n");
	
	for(i=1;i<=n;i++)
	  printf("%d\t",x[i]);
	printf("\n");
	
	return k[n][Weight];
}

void main()
{
	int i,n,val[10],obj[10],Weight;
	
	printf("Enter the number of objects:\n");
	scanf("%d",&n);
	
	printf("Enter the value and weight for the objects:\n");
	for(i=0;i<n;i++)
	 scanf("%d %d",&val[i],&obj[i]);
	 
	printf("Enter the size of KnapSack\n");
	scanf("%d",&Weight);
	
	printf("Total profit of Knapsack is : %d\n",knapsack(Weight,obj,val,n));
}
