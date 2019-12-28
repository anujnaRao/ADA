#include<stdio.h>
#include<stdlib.h>

void main()
{
	int i,j,k,count=0, ar[10][10],ind[10],flag[10],n;
	
	printf("Enter the number of vertices:\n");
	scanf("%d",&n);
	
	printf("Enter the adjacency matrix:\n");
	for(i=0;i<n;i++)
	 for(j=0;j<n;j++)
	  scanf("%d",&ar[i][j]);
	  if(i==j)
	  {
	  	if(ar[i][j] != 0)
	  	 {
	  	  printf("Loop\n");
	  	  exit(0);
	     }
	  }
	
	for(i=0;i<n;i++)
	 for(j=0;j<n;j++)
	  if(ar[i][j]==ar[j][i] && i!=j && ar[i][j] == 1)
	   {
	   	printf("Loop\n");
	   	exit(0);
	   }
	   
    for(i=0;i<n;i++)
    {
    	ind[i]=0;
    	flag[i]=0;
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			ind[i]+=ar[j][i];
		}
	}
	
	printf("Topological Ordering is: \n");
	while(count<n)
	{
		for(k=0;k<n;k++)
		{
			if( ind[k] == 0  && flag[k] == 0)
			{
				printf("%d\t",(k+1));
				flag[k]=1;
			}
			for(i=0;i<n;i++)
			{
				if(ar[i][k] == 1)
				 ind[k]--;
			}
		}
		count++;
	}
}
