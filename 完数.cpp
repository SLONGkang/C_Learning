#include<stdio.h>
int main()
{
    int i, j, s, n;  /*����i����ѡ������Χ��j���Ƴ�����Χ��s��¼�ۼ�����֮��*/
    printf("��������ѡ��Χ���ޣ�");
    scanf("%d", &n);  /* n��ֵ�ɼ�������*/
    for( i=2; i<=n; i++ )
    {
        s=0;  /*��֤ÿ��ѭ��ʱs�ĳ�ֵΪ0*/
        for( j=1; j<i; j++ )
        {
            if(i%j == 0)  /*�ж�j�Ƿ�Ϊi������*/
                s += j;
        }
        if(s == i)  /*�ж���������Ƿ��ԭ�����*/
            printf("It's a perfect number:%d\n", i);
    }
    return 0;
} 
