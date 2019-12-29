#include<stdio.h>
#include<string.h>
#include<time.h>

int ar[100];

void quicksort(int low,int high)
{
	int i,j,temp,piv;
	if(low<high)
	{
		piv=ar[low];
		i=low;
		j=high;
		while(i<j)
		{
			while(ar[i]<=piv && i<=high)
			 i++;
			while(ar[j]> piv && j>=low)
			 j--;
			 
			 if(i<j)
			 {
			 	temp=ar[i];
			 	ar[i]=ar[j];
			 	ar[j]=temp;
			 }
		}
		temp=ar[low];
		ar[low]=ar[j];
		ar[j]=temp;
			 
	    quicksort(low,j-1);
	    quicksort(j+1,high);
	}
}

void main()
{
	int i,j,m,n;
	float t;
	
	FILE *f1;
	
	f1=fopen("quickSort.txt","w");
	struct timeval start,end;
	
	printf("Enter the number of iterations\n");
	scanf("%d",&m);
	
	for(j=0;j<m;j++)
	{
		printf("Enter the size of array\n");
		scanf("%d",&n);
		
		for(i=0;i<n;i++)
		 ar[i]= rand()%1000;
		 
		gettimeofday(&start,0);
		quicksort(0,n-1);
		gettimeofday(&end,0);
		
		printf("Sorted: \n");
		for(i=0;i<n;i++)
		 printf("%d\t", ar[i]);
		 
		printf("\n");
		
		printf("Time for %d is %.2f\n",n,t);
		
		fprintf(f1,"%d\t %.2f\n",n,t); 
	}
	fclose(f1);
}
