#include <stdio.h>

int max( int a, int b );

int main()
{    
    int a, b;

    scanf("%d %d", &a, &b);
    printf("max = %d\n", max(a, b));

    return 0;
}
int max(int a,int b)
{
	int i;
	if(a=b)
	printf("两数相等");
	else
	  if(a>b)
	    i=a;
	  else
	    i=b;
	return i;
}
