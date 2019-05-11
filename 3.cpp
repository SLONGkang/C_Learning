#include<stdio.h>
# include <math.h>
# define U 0.04         //Y轴方向步进值
# define V 0.02         //X轴方向步进值
# define P 0.9          //P决定两颗心之间的间距
# define K 0.27         //箭轴向直线的斜率
# define R 0.14         //箭与（0，0）点相对应的距离
# define B 0.03         //B决定箭轴的宽度
# define M 1.05         //M改变内部心形X轴方向的大小
# define N 1.05         //N改变内部心形Y轴方向的大小
# define KW_UP -1       //箭尾上部直线斜率
# define KW_DOWM 3.73   //箭尾下部直线斜率 
# define KT_R 0.58      //箭头右边直线斜率
# define KT_L -3.7      //箭头左边直线斜率

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
if ( ( ( ( ( (x+P)*(x+P) + y*y - 1)*( (x+P)*(x+P) + y*y - 1)*( (x+P)*(x+P) + y*y - 1) - (x+P)*(x+P)*y*y*y ) <= 0 ) )          //左侧心形部分
&& ( ( ( (M*(x+P)*M*(x+P) + N*N*y*y - 1)*(M*(x+P)*M*(x+P) + N*N*y*y - 1)*(M*(x+P)*M*(x+P) + N*N*y*y - 1) - M*(x+P)*M*(x+P)*N*N*N*y*y*y ) >= 0 ) ) 
|| ( y >= (K*x + R - B) && y <= (K*x + R + B)) && ( x <= -1.2 ) && ( x >= -2.1 )                                    //左侧心形的箭轴部分
|| ( ( y < K*x + 0.14 + 0.1 ) && ( y < KW_UP*x - 2.24 )  && ( y > KW_UP*x - 3.008 ) && ( y > K*x + 0.14 ) )         //箭尾在箭轴以上的区间
|| ( ( y > K*x + 0.14 - 0.1 ) && ( y < K*x + 0.14 ) && ( y > KW_DOWM*x + 6.624 ) && ( y < KW_DOWM*x + 8.718 ) ) )   //箭尾在箭轴以下的区间
printf("*");
else
printf(" ");
}

for ( x = 0; x <= 3; x += V )
{ 
if ( ( ( ( ( (x-P)*(x-P) + y*y - 1)*((x-P)*(x-P) + y*y - 1)*((x-P)*(x-P) + y*y - 1) - (x-P)*(x-P)*y*y*y ) <= 0 ) )                               //右侧心形部分
&& ( ( ( (M*(x-P)*M*(x-P) + N*N*y*y - 1)*(M*(x-P)*M*(x-P) + N*N*y*y - 1)*(M*(x-P)*M*(x-P) + N*N*y*y - 1) - M*(x-P)*M*(x-P)*N*N*N*y*y*y ) >= 0 ) ) 
|| ( ( ( ((x+P)*(x+P) + y*y - 1)*((x+P)*(x+P) + y*y - 1)*((x+P)*(x+P) + y*y - 1) - (x+P)*(x+P)*y*y*y ) <= 0 ) )                              //左侧心形在右侧的部分
&& ( ( ( (M*(x+P)*M*(x+P) + N*N*y*y - 1)*(M*(x+P)*M*(x+P) + N*N*y*y - 1)*(M*(x+P)*M*(x+P) + N*N*y*y - 1) - M*(x+P)*M*(x+P)*N*N*N*y*y*y ) >= 0 ) ) 
|| ( y >= K*x + R - B ) && ( y <= K*x + R + B) && ( x >= 2 ) && ( x < 2.6 )    //右侧心形的箭轴部分
|| ( ( y > KT_R*x - 0.79 ) && ( y > KT_L*x + 10.5 ) && ( y < 0.95 ) ) )        //箭头区间
printf("*");
else
printf(" ");
}

printf("\n");
}


}




