#include<stdio.h>
int main()
{
	int V;
	scanf("%d",&V);
	if(V<=60)
	printf("Speed: %d - OK",V);
	else
	printf("Speed: %d - Speeding",V);
	return 0;
}
