#include<stdio.h>

void path(int graph[10][10], int n,int sn)
{
	int cost[10][10],dist[10],vis[10],prv[10],i,j,count,nn,minDist;
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(graph[i][j]==0)
			 cost[i][j]=999;
			else
			 cost[i][j]=graph[i][j];
		}
	}
	
	for(i=0;i<n;i++)
	{
		dist[i]=cost[sn][i];
		prv[i]=sn;
		vis[i]=0;
	}
	dist[sn]=0;
	vis[sn]=1;
	count=1;
	
	while(count<n-1)
	{
		minDist=999;
		for(i=0;i<n;i++)
		 if( dist[i] <minDist && !vis[i])
		 {
		  minDist=dist[i];
		  nn=i;
		 }
		 vis[nn]=1;
		 for(i=0;i<n;i++)
		  if( !vis[i])
		   if(minDist+cost[nn][i]<dist[i])
		   {
		   	dist[i]=minDist+cost[nn][i];
		   	prv[i]=nn;
		   }
		count++;
	}
	
	for(i=0;i<n;i++)
	 if(i != sn)
	 {
	 	printf("\nDistance of node %d is %d\n",i,dist[i]);
	 	printf("\nPath: %d",i);
	 	
	 	j=i;
	 	do
	 	{
	 		j=prv[j];
			printf("<-%d",j);
		 }while(j!=sn);
	 }
}

void main()
{
	int graph[10][10], n,u,i,j;
	
	printf("Enter the number of vertices: \n");
	scanf("%d",&n);
	
	printf("Enter the adjacency matix:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&graph[i][j]);
		}
	}
	 printf("Enter the startnode\n");
	 scanf("%d",&u);
	 
	 path(graph,n,u);
}


