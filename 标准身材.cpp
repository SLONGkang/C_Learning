#include<stdio.h>
int main()
{
	int a[20],b[20],N,i;
	double x,y,z;
	scanf("%d",&N);
	for(i=0;i<=N-1;i++)
	{
		scanf("%d %d",&a[i],&b[i]);
		y=a[i]/1;
		x=(y-100)*9.0/5.0;
		
	}
	for(i=0;i<=N-1;i++)
	{    z=b[i]/1;
		if(z>=x)
		{
			if(z-x<x/10.0)
			printf("You are wan mei!\n");
			else
			printf("You are tai pang le!\n");
		}
		else
		{
			if(x-z<x/10.0)
			printf("You are wan mei!\n");
			else
			printf("You are tai shou le!\n");
		}
	}
	
	return 0;
}
