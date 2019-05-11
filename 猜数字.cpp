#include<stdio.h>
#include <stdlib.h>  
#include <time.h> 
int main(){
	int N,x,m,n;
	n=0;
	scanf("%d %d",&x,&N);
	srand((int)time(NULL));
    do{
	    m=1+(rand()%100);
	    printf("%d\n",m);
	    n=n+1;
	    if(m<x&&m>0)
	    printf("Too small\n");
	    if(m>x)
	    printf("Too big\n");
	    if(m<0)
	    {
	    	printf("Game Over!\n");
	    	goto A;
		}
	    if(n==N){
	    	printf("Game Over\n");
	    break;
		}
	    
	}while(m!=x);
    if(n==1)
    printf("Bingo!\n");
    else{
    	if(n<=3)
        printf("Lucky You!\n");
        else if(n<N)
        printf("Good Guess!\n");
	}
    A:
   	return 0;
} 
