#include<stdio.h>
# include <math.h>
# define U 0.04         //Y�᷽�򲽽�ֵ
# define V 0.02         //X�᷽�򲽽�ֵ
# define P 0.9          //P����������֮��ļ��
# define K 0.27         //������ֱ�ߵ�б��
# define R 0.14         //���루0��0�������Ӧ�ľ���
# define B 0.03         //B��������Ŀ��
# define M 1.05         //M�ı��ڲ�����X�᷽��Ĵ�С
# define N 1.05         //N�ı��ڲ�����Y�᷽��Ĵ�С
# define KW_UP -1       //��β�ϲ�ֱ��б��
# define KW_DOWM 3.73   //��β�²�ֱ��б�� 
# define KT_R 0.58      //��ͷ�ұ�ֱ��б��
# define KT_L -3.7      //��ͷ���ֱ��б��

//void gotoxy(int x,int y);
void print_heart_arrow();

int main(void)
{
print_heart_arrow();
getchar();

return 0;
}
void print_heart_arrow()
{
float x, y;

for ( y = 1.8; y >= -1.8; y -= U )
{ 
for ( x = -2.8; x <= 0; x += V )
{ 
if ( ( ( ( ( (x+P)*(x+P) + y*y - 1)*( (x+P)*(x+P) + y*y - 1)*( (x+P)*(x+P) + y*y - 1) - (x+P)*(x+P)*y*y*y ) <= 0 ) )          //������β���
&& ( ( ( (M*(x+P)*M*(x+P) + N*N*y*y - 1)*(M*(x+P)*M*(x+P) + N*N*y*y - 1)*(M*(x+P)*M*(x+P) + N*N*y*y - 1) - M*(x+P)*M*(x+P)*N*N*N*y*y*y ) >= 0 ) ) 
|| ( y >= (K*x + R - B) && y <= (K*x + R + B)) && ( x <= -1.2 ) && ( x >= -2.1 )                                    //������εļ��Ჿ��
|| ( ( y < K*x + 0.14 + 0.1 ) && ( y < KW_UP*x - 2.24 )  && ( y > KW_UP*x - 3.008 ) && ( y > K*x + 0.14 ) )         //��β�ڼ������ϵ�����
|| ( ( y > K*x + 0.14 - 0.1 ) && ( y < K*x + 0.14 ) && ( y > KW_DOWM*x + 6.624 ) && ( y < KW_DOWM*x + 8.718 ) ) )   //��β�ڼ������µ�����
printf("*");
else
printf(" ");
}

for ( x = 0; x <= 3; x += V )
{ 
if ( ( ( ( ( (x-P)*(x-P) + y*y - 1)*((x-P)*(x-P) + y*y - 1)*((x-P)*(x-P) + y*y - 1) - (x-P)*(x-P)*y*y*y ) <= 0 ) )                               //�Ҳ����β���
&& ( ( ( (M*(x-P)*M*(x-P) + N*N*y*y - 1)*(M*(x-P)*M*(x-P) + N*N*y*y - 1)*(M*(x-P)*M*(x-P) + N*N*y*y - 1) - M*(x-P)*M*(x-P)*N*N*N*y*y*y ) >= 0 ) ) 
|| ( ( ( ((x+P)*(x+P) + y*y - 1)*((x+P)*(x+P) + y*y - 1)*((x+P)*(x+P) + y*y - 1) - (x+P)*(x+P)*y*y*y ) <= 0 ) )                              //����������Ҳ�Ĳ���
&& ( ( ( (M*(x+P)*M*(x+P) + N*N*y*y - 1)*(M*(x+P)*M*(x+P) + N*N*y*y - 1)*(M*(x+P)*M*(x+P) + N*N*y*y - 1) - M*(x+P)*M*(x+P)*N*N*N*y*y*y ) >= 0 ) ) 
|| ( y >= K*x + R - B ) && ( y <= K*x + R + B) && ( x >= 2 ) && ( x < 2.6 )    //�Ҳ����εļ��Ჿ��
|| ( ( y > KT_R*x - 0.79 ) && ( y > KT_L*x + 10.5 ) && ( y < 0.95 ) ) )        //��ͷ����
printf("*");
else
printf(" ");
}

printf("\n");
}


}




