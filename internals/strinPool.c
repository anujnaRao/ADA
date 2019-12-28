#include<stdio.h>
#include<string.h>
#include<time.h>

int table[127];
FILE *f1;

void shift_table(char pat[])
{
	int i,j,m;
	m=strlen(pat);
	
	for(i=0;i<127;i++)
	 table[i]=m;
	for(j=0;j<m-1;j++)
	 table[pat[j]]=m-1-j;
}

int horspool_algo(char str[] ,char pat[])
{
	int i,j,k,n,m;
	
	n = strlen(str);
	m = strlen(pat);
	
	i=m-1;
	
	while(i<n)
	{
		k=0;
		while( (k<m) && (pat[m-1-k] == str[i-k]) )
		  k++;
		if(k == m)
		  return (i-m+1);
		else
		  i+= table[str[i]];
	}
	return -1;
}

void main()
{
	int pos,n,i;
	float t1,t2;
	char str[2000],pat[100];
	
	struct timeval start,end;
	
	f1 = fopen("strinPool.txt","w");
	
	for(i=0;i<5;i++)
	{
		printf("Enter the string pattern: \n");
		gets(str);
		
		n=strlen(str);
		
		printf("Enter the pattern for best case:\n");
		gets(pat);
		
		gettimeofday(&start,0);
		shift_table(pat);
		pos=horspool_algo(str, pat);
		gettimeofday(&end,0);
		
		t1=end.tv_usec -start.tv_usec;
		
		printf("Enter the pattern for worst case:\n");
		gets(pat);
		
		gettimeofday(&start,0);
		shift_table(pat);
		pos=horspool_algo(str, pat);
		gettimeofday(&end,0);
		
		t2= end.tv_usec - start.tv_usec;
		
		printf("Time for %d length string is %.2f and %.2f\n",n,t1,t1);
		
		fprintf(f1,"%d\t %.2f\t %.2f\n",n,t1,t2);
	}
	fclose(f1);
}


