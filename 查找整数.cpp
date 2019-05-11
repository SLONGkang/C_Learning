#include<stdio.h>
int main()
{
	int b,i,N,X;
	int a[20];
	b=0;
	scanf("%d %d",&N,&X);
	for(i=0;i<N;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<N;i++)
	{
		if(a[i]==X)
		{
			printf("%d",i);
	      b=1;
		}
	     
	}
	   if(b==0)
	   printf("Not Found");
	
	
	   
	return 0;
 } 
