#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

char str[1000],sub[100];
FILE *f1;

int string_match()
{
	int i,j,m,n;
	
	m=strlen(str);
	n=strlen(sub);
	
	for(i=0;i<m-n;i++)
	{
		j=0;
		while(j<n && sub[j] == str[i+j])
		{
			j++;
			if(j == n)
			  return i;
		}
	}
	return -1;
}

void main()
{
	int pos,n,i;
	float t1,t2;
	
	/*
	time_t timel;
	struct tm *s, *e;*/
	
	struct timeval start,end;
	f1 = fopen("strinMatch.txt","w");
	
	for(i=0;i<5;i++)
	{
		printf("Enter the string pattern: \n");
		gets(str);
		
		n=strlen(str);
		
		printf("Enter the pattern for best case:\n");
		gets(sub);
		
		//s=localtime(&timel);
		gettimeofday(&start,0);
		pos=string_match();
		//e=localtime(&timel);
		gettimeofday(&end,0);
		
		
		//t1=e-s;
		t1=end.tv_usec -start.tv_usec;
		
		printf("Enter the pattern for worst case:\n");
		gets(sub);
		
		gettimeofday(&start,0);
		pos=string_match();
		gettimeofday(&end,0);
		
		t2= end.tv_usec - start.tv_usec;
		
		printf("Time for %d length string is %.2f and %.2f\n",n,t1,t1);
		
		fprintf(f1,"%d\t %.2f\t %.2f\n",n,t1,t2);
	}
	fclose(f1);
}

