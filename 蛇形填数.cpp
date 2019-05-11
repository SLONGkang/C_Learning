# include <stdio.h>
int main()
{
	int n;
	int i=1;
	int a[100][100]={0};
	int x, y;
	printf("«Î ‰»Înµƒ÷µ\n");
	scanf("%d",&n);
	for (y=0;y+1<=n;y=y+1)
	{
		if (y%2==0)
		{
			for (x= 0;x+1<=n;x=x+1)
			{
				a[x][y]=i;
				i=i+1;
			}
		}
		else
		{
			for(x=n-1;x>=0;x=x-1)
			{
				
				a[x][y]=i;
				i=i+1;
			}
		}
	}
	for(x=0;x+1<=n;x=x+1)
	{
		for(y=0;y+1<=n;y=y+1)
		{
			printf("%-2d ",a[x][y]);
		}
		printf("\n");
	}
	return 0;
} 

