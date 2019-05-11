#include <stdio.h>
#include <math.h>

int prime( int p );
void Goldbach( int n );

int main()
{
    int m, n, i, cnt;

    scanf("%d %d", &m, &n);
    if ( prime(m) != 0 ) printf("%d is a prime number\n", m);
    if ( m < 6 ) m = 6;
    if ( m%2 ) m++;
    cnt = 0;
    for( i=m; i<=n; i+=2 ) {
        Goldbach(i);
        cnt++;
        if ( cnt%5 ) printf(", ");
        else printf("\n");
    }

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
 
 void Goldbach( int n )
 {
 	int a[n],i,j=0,k=0,flag=0;
 	for(i=2;i<n;i++)
	   {
	 		if(prime(i)==1)
			{
			 	a[j++]=i;
			}
		}
	for(i=0;i<j;i++)
		{
     	for(k=0;k<j;k++)
			{
				if(a[i]+a[k]==n)
				   {
			    	printf("%d = %d + %d", n, a[i], a[k]);
			    	flag=1;
			    	break;	
				   }	
			}
    		if(flag)
			break;
		}
 }

