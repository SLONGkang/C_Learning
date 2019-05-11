#include<stdio.h>

int main()
{
    int hermite(int x,int n);
    int x;
    int n;
    int y;
    printf("请输入多项式的x,n:\n");
    scanf("%d,%d",&x,&n);
    y=hermite(x,n);
    printf("厄密多项式结果为：%d",y);
    return 0;
 }
int hermite(int x,int n)
{
   int f;
   if(n<=0)
     f=1;
   else 
     if(n==1)
        f=x*2;
     else
        f=2*x*hermite(x,n-1)-2*(n-1)*hermite(x,n-2);
    return f;
 }

