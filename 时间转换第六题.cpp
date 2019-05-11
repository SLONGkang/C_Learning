#include<stdio.h>
int main()
{
	int CLK_TCK;
	long long int C1,C2;
	int a,b,c,d,x;
	CLK_TCK=100;
	scanf("%d %d",&C1,&C2);
    a=(C2-C1)/CLK_TCK;
    x=(C2-C1)%CLK_TCK;
    if(x!=0)
    a=a+1;
	b=a/3600;
	c=(a-b*3600)/60;
	d=a-b*3600-c*60;
	printf("%02d:%02d:%02d",b,c,d);
	return 0;
 } 
