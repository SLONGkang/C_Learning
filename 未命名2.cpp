#include<stdio.h>
int main()
{
	int a,b,c,d,s;
	scanf("%d %d %d %d",&a,&b,&c,&d);
	s=a+b+c+d;
	printf("Sum=%d",s);
	printf(";Average=%.1lf\n",s/4.0);
	return 0;
}
