#include<stdio.h>
#include<math.h>
int Prime(int n)
{int i,a=1;
if(n<2)	a=0; 
for(i=2;i<=n-1;i++)
{if(n%i==0)
{    
a=0;
}
} 
return a;
} 
int main()
{	
int sum=0,M,N,i,z=0;	
scanf("%d%d",&M,&N);	
for(i=M;i<=N;i++)
{		
if(Prime(i)==1)
{			
sum=sum+i;			
z++;		
}			
}	
printf("%d %d",z,sum);	
return 0;
}

