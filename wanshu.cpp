#include<stdio.h>
int main()
{
	int j,s,i,x;
	x=0;
	int a[1000];
	int b[1000];
	  for(i=1;i<=1000;i++) {
		  for(j=1;j<=i;j++) {
			  for(s=1;s<=i;s++) {
				  if(b[s]*a[j]==i){
				  	
				  }
				  else{
				  	b[s]=0;
				  	a[j]=0;
				  }
				 
			  }
		  }
		  
	for(j=1;j<=i;j++) {
			  for(s=1;s<=i;s++) {
				 if(b[s]==a[j])
				 b[s]=0;
				 
			  }
		  }
 for(j=1;j<=i;j++) {
			  for(s=1;s<=i;s++) {
				  x=b[s]+a[j];
				  }
				   printf("%d",x);
			  }	 
 }
			
			  return 0;
		  }
		 


