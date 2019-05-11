#include<stdio.h>
int main()
{
	int s=0,a,i=0,n,x=1,m;
	scanf("%d %d",&a,&n);
	m=a;
	for(;i<n;i++)
	{
		s=s+a;
		a=a+m*10;
		
			m=m*10;	
		
	
	}
	printf("%d",s);
	return 0;
 } 
