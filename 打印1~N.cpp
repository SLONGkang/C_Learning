#include <stdio.h>

void PrintN ( int N );

int main ()
{
    int N;

    scanf("%d", &N);
    PrintN( N );

    return 0;
}

void PrintN (int N)

{
	int a,b;
	a=N;
    for(b=1;b<a+1;b++)
    {
    	printf("%d\n",b);
	}
}
