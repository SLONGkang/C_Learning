#include "Conio.h"
#define closegr closegraph

void initgr(void) /* BGI��ʼ�� */
{
int gd = DETECT, gm = 0; /* ��gd = VGA,gm = VGAHI��ͬ��Ч�� */
registerbgidriver(EGAVGA_driver);/* ע��BGI��������Բ���Ҫ.BGI�ļ���֧������ */
initgraph(&gd, &gm, "");
}

int main(void)
{
initgr(); /* BGI��ʼ�� */

line(25, 25, 220, 220);
circle(100, 100, 50);

getch(); /* ��ͣһ�£�����ǰ���ͼ��������н�� */
closegr(); /* �ָ�TEXT��Ļģʽ */
return 0;
} 
