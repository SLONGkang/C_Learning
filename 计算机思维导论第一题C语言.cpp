#include<stdio.h>
int main()
{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	int T,B;
	T=a*b*c;
	B=a*b*2+b*c*2+a*c*2;
	printf("���:%d\n�����:%d",T,B);
	return 0; 
}
