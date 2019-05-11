#include <stdio.h>
#include <math.h>

int prime( int p );
int PrimeSum( int m, int n );

int main()
{
    int m, n, p;

    scanf("%d %d", &m, &n);
    printf("Sum of ( ");
    for( p=m; p<=n; p++ ) {
        if( prime(p) != 0 )
            printf("%d ", p);
    }
    printf(") = %d\n", PrimeSum(m, n));

    return 0;
}


int prime( int p )
{
    int i;
    if(p>1)
    {
	
	for(i=2;i<=p-1;i++)
    {
    	if(p%i==0)
    	return 0;;
	}
	}
	if(p>1)
	return 1;
   
    else
    
    return 0;
 }
 
int PrimeSum( int m, int n )
 {
 	int z,p;
 	z=0;
 	if(m<=n)
 	{
	
 	for(p=m;p<=n;p++) 
	  {
        if( prime(p) != 0 )
            z=z+p;
      }
    }
    return z;
 }
