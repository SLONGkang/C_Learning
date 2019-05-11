#include<stdio.h>
int main()
{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	int T,B;
	T=a*b*c;
	B=a*b*2+b*c*2+a*c*2;
	printf("体积:%d\n表面积:%d",T,B);
	return 0; 
}
