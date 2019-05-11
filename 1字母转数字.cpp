#include<stdio.h>
int main()
{
	int y;
	char x;
	scanf("%c",&x);
	switch(x)
		{
			case 'S':y=0;break;
			case 'R':y=1;break;
			case 'P':y=2;break;
		}
	printf("%d",y);
	return 0;
 } 
