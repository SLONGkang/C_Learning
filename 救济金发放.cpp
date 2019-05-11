#include<stdio.h>

int main()
{
	int n,k,m,i;//n是人数，k是A官员数的，m是B官员数的 ，i用于for循环； 
	int a,b,x,y;  //a是k；b是m； 
	int c[100000];
	i=0;
	scanf("%d %d %d",&n,&k,&m);
	for(i=0;i<n;i++)
	{
		c[i]=i+1;
	
	 } 

	k=k%n;
	m=m%n;
	a=k;
	b=n+1-m;
	if(n%2!=0)
	x=(n+1)/2;
	else
	x=n/2;
	for(y=0;y<=n;y++)
	{
	for(i=0;i<n;i++)
	{
	do
	{
		a=(a+n)%n +1;
	}while(c[i]==n+1);
	}
	printf("%d ",c[a]);
	c[a]=n+1;
	
	
	for(i=n-1;i>=0;i--)
	{
		do
		{
			b=(b+n-2)%n +1;
		}while(c[i]==n+1);
		}
		printf("%d\n",c[b]);
		c[b]=n+1;
	}
	return 0;
}



 
