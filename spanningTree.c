#include<stdio.h>
#include<stdlib.h>

void main()
{
  int i,j,a,u,b,v,mincost=0,cost[10][10],vis[10]={0},min,ne=1,n;
  
  	printf("Enter the no of vertices:\n");
	scanf("%d",&n);
 
	printf("Enter the adjacency matrix:\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
		{
			scanf("%d",&cost[i][j]);
			// When minimum value is 0 convert it to 999
			if(cost[i][j]==0)
				cost[i][j]=999;
		}
	}
	//First index visited
	vis[1]=1;
	/*
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",cost[i][j]);
		}
		printf("\n");
	}
*/
	
	while(ne<n)
	{
		for(i=1,min=999;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(cost[i][j]<min)
				{
					if(vis[i]!=0)
					{
						min=cost[i][j];
						a=u=i;
						b=v=j;
					}
				}
			}
		}
		if(vis[u]==0 || vis[v]==0)
		{
			printf("Edges %d:(%d -> %d),cost %d\n",ne++,a,b,mincost);
			mincost+=min;
			vis[b]=1;
		}
		cost[a][b]=cost[b][a]=999;
	}
	printf("Minimum cost of the tree is %d\n",mincost);
}
