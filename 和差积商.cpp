#include<stdio.h>
int main()
{
	int a,b;
	float c,d,e;
    scanf("%d %d",&a,&b);
    if(b==0)
    return 0;
    d=a/1;
    e=b/1;
	c=d/e;
	do
	{
	printf("%d+%d=%d\n",a,b,a+b);
	printf("%d-%d=%d\n",a,b,a-b);
	printf("%d*%d=%d\n",a,b,a*b);
	printf("%d/%d=%d\n",a,b,a/b);
	return 0;
	}while(a%b==0);
	printf("%d+%d=%d\n",a,b,a+b);
	printf("%d-%d=%d\n",a,b,a-b);
	printf("%d*%d=%d\n",a,b,a*b);
	printf("%d/%d=%.2f\n",a,b,c);
	return 0;
}
