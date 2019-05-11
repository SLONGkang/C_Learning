#include<stdio.h>
int main()
{
	int i,N,a,b,c;
	
	c=0;
	scanf("%d",&N);
	for(i=1;i<=N;i++)
    {
    	b=1;
		for(a=1;a<=i;a++)
    	{
    		
			b=b*a;
		}
		c=c+b;
	}
	printf("%d",c);
	return 0;
}
