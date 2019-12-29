#include<Stdio.h>
#include<string.h>
#include<time.h>

char str[2000],pat[100];
FILE *f1;

int string_match()
{
	int i,j,m,n;
	m=strlen(str);
	n=strlen(pat);
	
	for(i=0;i<m-n;i++)
	{
		j=0;
		while( j<n && pat[j]== str[i+j])
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
	struct timeval start,end;
	
	f1=fopen("stringMatch.txt","w");
	
	printf("Enter the string \n");
	gets(str);
	n=strlen(str);
	
	printf("Enter the pattern for best case\n");
	gets(pat);
	
	gettimeofday(&start,0);
	pos=string_match();
	gettimeofday(&end,0);
	
	t1=end.tv_usec-start.tv_usec;
	
	printf("Enter the pattern for worst case\n");
	gets(pat);
	
	gettimeofday(&start,0);
	pos=string_match();
	gettimeofday(&end,0);
	
	t2= end.tv_usec- start.tv_usec;
	
	printf("Time is %.2f and %.2f\n",t1,t2);
	fprintf(f1,"%d\t %.2f\t %.2f\n",n,t1,t2);
	fclose(f1);
}
