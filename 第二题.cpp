#include<stdio.h>
int main()
{
	begin:
	int a;
	scanf("%d",&a);
	if(a<=50)
	printf("����\n");
	else if(a>50&&a<71)
	printf("���֣�������\n");
	else if(a>70&&a<91)
	printf("�ܳ�����ϸ�����ƻ�\n");
	else if(a>90&&a<101)
	printf("���ּӾ磬��������\n");
	else if(a>100&&a<121)
	printf("�������ܣ���һ������ʱ����\n");
	else if(a>120)
	printf("��������ȫ��\n");
	goto begin;
	return 0;
}
