#include "Conio.h"
#define closegr closegraph

void initgr(void) /* BGI初始化 */
{
int gd = DETECT, gm = 0; /* 和gd = VGA,gm = VGAHI是同样效果 */
registerbgidriver(EGAVGA_driver);/* 注册BGI驱动后可以不需要.BGI文件的支持运行 */
initgraph(&gd, &gm, "");
}

int main(void)
{
initgr(); /* BGI初始化 */

line(25, 25, 220, 220);
circle(100, 100, 50);

getch(); /* 暂停一下，看看前面绘图代码的运行结果 */
closegr(); /* 恢复TEXT屏幕模式 */
return 0;
} 
