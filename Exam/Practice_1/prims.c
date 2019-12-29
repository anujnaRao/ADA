#include<stdio.h>

void main()
{
	int cost[10][10],i,j,a,b,u,v,n,minCost=0,min,flag=1,vis[10]={0};
	
	printf("Enter the number of vertices\n");
	scanf("%d",&n);
	
	printf("Enter the adjacency matrix:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&cost[i][j]);
			if(cost[i][j] ==0)
			 cost[i][j]=999;
		}
	}
	
	vis[1]=1;
	
	while(flag<n)
	{
		for(i=1,min=999;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(cost[i][j]<min && vis[i] !=0)
				{
					min=cost[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
		if(vis[u]==0 || vis[v]==0)
		{
			printf("Edge %d from %d to %d cost is : %d\n",flag++,a,b,min);
			minCost+=min;
			vis[b]=1;
		}
		cost[a][b]=cost[b][a]=999;
	}
	printf("Total cost is %d\n",minCost);
}
