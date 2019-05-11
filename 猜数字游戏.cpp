#include<stdio.h>
#include <stdlib.h>
#include <time.h> 
int main()
{ int i,a,b,N;
srand((unsigned) time(NULL)); 
a= rand() % 101; 
printf("%d",a);
scanf("%d",&N);
i=0;


	do
	{
		scanf("%d",&b);
		if(b>a)
		printf("Too big");
		else
		printf("Too small");
		i++;
		
		
	}while(b!=a);
	if(i==1)
	{
		printf("Bingo!");
	}
	else
	{
		if(i<=3)
		{
			printf("Lucky You!");
			
		}
		else
		{
			
		}
	}   
		
	



return 0;
} 
