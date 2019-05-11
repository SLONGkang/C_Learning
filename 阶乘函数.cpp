#include <stdio.h>

int Factorial( const int N );

int main()
{
    int N, NF;
	
    scanf("%d", &N);
    NF = Factorial(N);
    if (NF)  printf("%d! = %d\n", N, NF);
    else printf("Invalid input\n");

    return 0;
}
int Factorial( const int N )
{
	int a,b;
	a=1;
	b=1;
	do
	{
		a=a*b;
		b=b+1;
	}while(b<=N);
	return a;
 } 
