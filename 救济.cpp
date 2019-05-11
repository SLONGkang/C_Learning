#include<stdio.h>
#include<stdlib.h>
#define max 100
int n , k ,m ,a[max];
int go(int p,int d,int t)
{  
while(t--)  
    {       
	 do{
	  p = (p+d+n-1)%n +1;
	   } while(a[p] == 0);//遇到零的时候就退出循环 跳出去了  
	}
return p;
}
int main()
{    
int i ,p1 ,p2 ,left ;   
 while(scanf("%d %d %d",&n,&k,&m)==3&&n)   
  {       
   for(i = 1;i<=n;i++)           
    a[i] = i;        
	left = n;//剩下多少人        
	p1 = n ;        
	p2 = 1;        
	while(left)        
	{            
	p1 = go(p1,1,k);//顺时针            
	p2 = go(p2,-1,m);//逆时针            
	printf("%3d",p1);           
	 left--;            
	 if(p1!=p2)           
	  {                
	 printf("%3d",p2);                
	 left--;            
	 }           
	  a[p1] = a[p2] = 0;//领到救济金的人归为零           
	   if(left)               
	    printf(",");       
		 }        
	printf("\n");    
	}    
	return 0;
}

