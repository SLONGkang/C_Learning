include<stdio.h>
int main()

if(c=='-') 
{ 
if(strcmp(str2,"")==0) /*如果str2为空，说明是负号，而不是减号*/ 
flag=-1; /*设置负数标志*/ 
else 
{ 
num1=atof(str2); /*将第二个操作数转换为浮点数*/ 
strcpy(str2,""); /*将str2清空*/ 
act=2; /*做计算减法标志值*/ 
setfillstyle(SOLID_FILL,color+3); 
bar(2*width+width/2,height/2,15*width/2,3*height/2); /*画矩形*/ 
outtextxy(5*width,height,"0."); /*显示字符串*/ 
} 
} 
if(c=='*') 
{ 
num1=atof(str2); /*将第二个操作数转换为浮点数*/ 
strcpy(str2,""); /*将str2清空*/ 
act=3; /*做计算乘法标志值*/ 
setfillstyle(SOLID_FILL,color+3); bar(2*width+width/2,height/2,15*width/2,3*height/2); 
outtextxy(5*width,height,"0."); /*显示字符串*/ 
} 
if(c=='/') 
{ 
num1=atof(str2); /*将第二个操作数转换为浮点数*/ 
strcpy(str2,""); /*将str2清空*/ 
act=4; /*做计算除法标志值*/ 
setfillstyle(SOLID_FILL,color+3); 
bar(2*width+width/2,height/2,15*width/2,3*height/2); 
outtextxy(5*width,height,"0."); /*显示字符串*/ 
} 
if(c=='^') 
{ 
num1=atof(str2); /*将第二个操作数转换为浮点数*/ 
strcpy(str2,""); /*将str2清空*/ 
act=5; /*做计算乘方标志值*/ 
setfillstyle(SOLID_FILL,color+3); /*设置用淡绿色实体填充*/ 
bar(2*width+width/2,height/2,15*width/2,3*height/2); /*画矩形*/ 
outtextxy(5*width,height,"0."); /*显示字符串*/ 
} 
if(c=='%') 
{ 
num1=atof(str2); /*将第二个操作数转换为浮点数*/ 
strcpy(str2,""); /*将str2清空*/ 
act=6; /*做计算模运算乘方标志值*/ 
setfillstyle(SOLID_FILL,color+3); /*设置用淡绿色实体填充*/ 
bar(2*width+width/2,height/2,15*width/2,3*height/2); /*画矩形*/ 
outtextxy(5*width,height,"0."); /*显示字符串*/ 
} 
if(c=='=') 
{ 
num2=atof(str2); /*将第二个操作数转换为浮点数*/ 
switch(act) /*根据运算符号计算*/ 
{ 
case 1:result=num1+num2;break; /*做加法*/ 
case 2:result=num1-num2;break; /*做减法*/ 
case 3:result=num1*num2;break; /*做乘法*/ 
case 4:result=num1/num2;break; /*做除法*/ 
case 5:result=pow(num1,num2);break; /*做x的y次方*/ 
case 6:result=fmod(num1,num2);break; /*做模运算*/ 
} 
setfillstyle(SOLID_FILL,color+3); /*设置用淡绿色实体填充*/ 
bar(2*width+width/2,height/2,15*width/2,3*height/2); /*覆盖结果区*/ 
sprintf(temp,"%f",result); /*将结果保存到temp中*/ 
outtextxy(5*width,height,temp); /*显示结果*/ 
} 
if(c=='c') 
{ 
num1=0; /*将两个操作数复位0，符号标志为1*/ 
num2=0; 
flag=1; 
strcpy(str2,""); /*将str2清空*/ 
setfillstyle(SOLID_FILL,color+3); /*设置用淡绿色实体填充*/ 
bar(2*width+width/2,height/2,15*width/2,3*height/2); /*覆盖结果区*/ 
outtextxy(5*width,height,"0."); /*显示字符串*/ 
} 
if(c=='Q')exit(0); /*如果选择了q回车，结束计算程序*/ 
} 
putimage(x,y,rar,XOR_PUT); /*在退出之前消去光标箭头*/ 
return; /*返回*/ 
} 
/*窗口函数*/ 
void mwindow( char *header ) 
{ 
int height; 
cleardevice(); /* 清除图形屏幕 */ 
setcolor( MaxColors - 1 ); /* 设置当前颜色为白色*/ 
setviewport( 20, 20, MaxX/2, MaxY/2, 1 ); /* 设置视口大小 */ 
height = textheight( "H" ); /* 读取基本文本大小 */ 
settextstyle( DEFAULT_FONT, HORIZ_DIR, 1 );/*设置文本样式*/ 
settextjustify( CENTER_TEXT, TOP_TEXT );/*设置字符排列方式*/ 
outtextxy( MaxX/4, 2, header ); /*输出标题*/ 
setviewport( 20,20+height+4, MaxX/2+4, MaxY/2+20, 1 ); /*设置视口大小*/ 
drawboder(); /*画边框*/ 
} 
void drawboder(void) /*画边框*/ 
{ 
struct viewporttype vp; /*定义视口类型变量*/ 
setcolor( MaxColors - 1 ); /*设置当前颜色为白色 */ 
setlinestyle( SOLID_LINE, 0, NORM_WIDTH );/*设置画线方式*/ 
getviewsettings( &vp );/*将当前视口信息装入vp所指的结构中*/ 
rectangle( 0, 0, vp.right-vp.left, vp.bottom-vp.top ); /*画矩形边框*/ 
} 
/*设计鼠标图形函数*/ 
int arrow() 
{ 
int size; 
int raw[]={4,4,4,8,6,8,14,16,16,16,8,6,8,4,4,4}; /*定义多边形坐标*/ 
setfillstyle(SOLID_FILL,2); /*设置填充模式*/ 
fillpoly(8,raw); /*画出一光标箭头*/ 
size=imagesize(4,4,16,16); /*测试图象大小*/ 
rar=malloc(size); /*分配内存区域*/ 
getimage(4,4,16,16,rar); /*存放光标箭头图象*/ 
putimage(4,4,rar,XOR_PUT); /*消去光标箭头图象*/ 
return 0; 
} 
/*按键函数*/ 
int specialkey(void) 
{ 
int key; 
while(bioskey(1)==0); /*等待键盘输入*/ 
key=bioskey(0); /*键盘输入*/ 
key=key&0xff? key&0xff:key>>8; /*只取特殊键的扫描值，其余为0*/ 
return(key); /*返回键值*/ 
} 
