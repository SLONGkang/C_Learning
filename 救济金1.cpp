#include<stdio.h>
int main()
{
	int n,k,m;
	int a[10000];
	int b,c,d,e,i;
	while(scanf("%d %d %d",&n,&k,&m)==3&&n)
	{
		for(i=1;i<=n;i++)
		{
			a[i]=i;
		}
		k=k%n;
		m=m%n;
		m=n+1-m;
		if(a[k]!=a[m])
		printf("%d %d\n",a[k],a[m]);
		else
		printf("%d",a[k]);
		
	}
	return 0;
}
