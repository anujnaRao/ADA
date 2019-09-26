#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int ar[150],i,j,low,high;
void quickSort(int [],int ,int);

void main()
{
 int n,m;
 float t;
 struct timeval start,end;
 printf("Enter the number of iterations\n");
 scanf("%d",&m);
 for(j=0;j<m;j++)
 {
  printf("Enter the size of the array\n");
  scanf("%d",&n);
  printf("Enter the array elements\n");
  for(i=0;i<n;i++)
   ar[i]=rand()%1000;
  printf("Entered array is\n");
  for(i=0;i<n;i++)
    printf("%d\t",ar[i]);
  printf("\n");
  gettimeofday(&start,NULL);
  quickSort(ar,0,n-1);
  gettimeofday(&end,NULL);
  printf("Sorted array is: \n");
  for(i=0;i<n;i++)
  {
   printf("%d\t",ar[i]);
  }
  printf("\n");
  t=start.tv_usec-end.tv_usec;
  printf("Time %f msec",t);
 }
}

void quickSort(int ar[],int low,int high)
{
 int piv,temp;
 if(low<high)
 {
   piv=ar[low];
   i=low;
   j=high;
   while(i<j)
   {
     while(ar[i]<piv && i<=high)
	i++;
     while(ar[j]>piv && j>=low)
	j--;
     if(i<j)
     {
        temp=ar[i];
	ar[i]=ar[j];
	ar[j]=temp;
     }
   }
   temp=ar[j];
   ar[j]=piv;
   piv=temp;
   quickSort(ar,low,j-1);
   quickSort(ar,j+1,high);
 }
}

