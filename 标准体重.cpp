#include<stdio.h>
int main()
{
	int a,b,c,d,sum;
	float e,Average;
	scanf("%d,%d,%d,%d",&a,&b,&c,&d);
	sum=a+d+c+b;
	e=sum;
	Average=e/4;
	printf("sum=%d;Average=%.1f",sum,Average);
	return 0;
}
