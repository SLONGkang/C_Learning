#include<stdio.h>
int main()
{
	int m, n, p,z,i,x;
	z=0;
	x=0;
    scanf("%d %d", &m, &n);
    for( p=m; p<=n; p++ ) 
	{
       for(i=2;i<=p-1;i++)
    {
    	if(p%i==0)
    	{
    	x=1;
		break;	
		}
        
	}
	if(x==0)
	z=z+1;
    }
    printf("%d",z);
    return 0;
}
