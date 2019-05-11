#include<stdio.h>
int main()
{
	begin:
	int a;
	scanf("%d",&a);
	if(a<=50)
	printf("安静\n");
	else if(a>50&&a<71)
	printf("吵闹，有损神经\n");
	else if(a>70&&a<91)
	printf("很吵，神经细胞受破坏\n");
	else if(a>90&&a<101)
	printf("吵闹加剧，听力受损\n");
	else if(a>100&&a<121)
	printf("难以忍受，呆一分钟暂时致聋\n");
	else if(a>120)
	printf("极度聋或全聋\n");
	goto begin;
	return 0;
}
