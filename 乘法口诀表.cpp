#include<stdio.h>
int main()
{
	a:
	int i,j,s,x;
	scanf("%d",&x);
	for(i=1;i<=x;i++){
		for(j=1;j<=i;j++){
			s=i*j;
			printf("%dX%d=%d  ",j,i,s);
		}
		printf("\n");
	}
	goto a;
	return 0;
 } 
