#include<stdio.h>
int main()
{
	int n,a,i,x,b,n1,n2;
	a=2;
	x=1;
	b=0;
	scanf("%d",&n);
	if(n==1||n==2)
	{
		printf("%d",x);
	}
	else
	{
		n1=1;
	   n2=1;
		
		for(i=3;i<=n;i++)
	{  
	   
	   x=n1+n2;;
	   n2=n1;
	   n1=x;
	}
	printf("%d",x);
	}
	return 0;
 } 
 //用循环写数列 
