include<stdio.h>
int main()

if(c=='-') 
{ 
if(strcmp(str2,"")==0) /*���str2Ϊ�գ�˵���Ǹ��ţ������Ǽ���*/ 
flag=-1; /*���ø�����־*/ 
else 
{ 
num1=atof(str2); /*���ڶ���������ת��Ϊ������*/ 
strcpy(str2,""); /*��str2���*/ 
act=2; /*�����������־ֵ*/ 
setfillstyle(SOLID_FILL,color+3); 
bar(2*width+width/2,height/2,15*width/2,3*height/2); /*������*/ 
outtextxy(5*width,height,"0."); /*��ʾ�ַ���*/ 
} 
} 
if(c=='*') 
{ 
num1=atof(str2); /*���ڶ���������ת��Ϊ������*/ 
strcpy(str2,""); /*��str2���*/ 
act=3; /*������˷���־ֵ*/ 
setfillstyle(SOLID_FILL,color+3); bar(2*width+width/2,height/2,15*width/2,3*height/2); 
outtextxy(5*width,height,"0."); /*��ʾ�ַ���*/ 
} 
if(c=='/') 
{ 
num1=atof(str2); /*���ڶ���������ת��Ϊ������*/ 
strcpy(str2,""); /*��str2���*/ 
act=4; /*�����������־ֵ*/ 
setfillstyle(SOLID_FILL,color+3); 
bar(2*width+width/2,height/2,15*width/2,3*height/2); 
outtextxy(5*width,height,"0."); /*��ʾ�ַ���*/ 
} 
if(c=='^') 
{ 
num1=atof(str2); /*���ڶ���������ת��Ϊ������*/ 
strcpy(str2,""); /*��str2���*/ 
act=5; /*������˷���־ֵ*/ 
setfillstyle(SOLID_FILL,color+3); /*�����õ���ɫʵ�����*/ 
bar(2*width+width/2,height/2,15*width/2,3*height/2); /*������*/ 
outtextxy(5*width,height,"0."); /*��ʾ�ַ���*/ 
} 
if(c=='%') 
{ 
num1=atof(str2); /*���ڶ���������ת��Ϊ������*/ 
strcpy(str2,""); /*��str2���*/ 
act=6; /*������ģ����˷���־ֵ*/ 
setfillstyle(SOLID_FILL,color+3); /*�����õ���ɫʵ�����*/ 
bar(2*width+width/2,height/2,15*width/2,3*height/2); /*������*/ 
outtextxy(5*width,height,"0."); /*��ʾ�ַ���*/ 
} 
if(c=='=') 
{ 
num2=atof(str2); /*���ڶ���������ת��Ϊ������*/ 
switch(act) /*����������ż���*/ 
{ 
case 1:result=num1+num2;break; /*���ӷ�*/ 
case 2:result=num1-num2;break; /*������*/ 
case 3:result=num1*num2;break; /*���˷�*/ 
case 4:result=num1/num2;break; /*������*/ 
case 5:result=pow(num1,num2);break; /*��x��y�η�*/ 
case 6:result=fmod(num1,num2);break; /*��ģ����*/ 
} 
setfillstyle(SOLID_FILL,color+3); /*�����õ���ɫʵ�����*/ 
bar(2*width+width/2,height/2,15*width/2,3*height/2); /*���ǽ����*/ 
sprintf(temp,"%f",result); /*��������浽temp��*/ 
outtextxy(5*width,height,temp); /*��ʾ���*/ 
} 
if(c=='c') 
{ 
num1=0; /*��������������λ0�����ű�־Ϊ1*/ 
num2=0; 
flag=1; 
strcpy(str2,""); /*��str2���*/ 
setfillstyle(SOLID_FILL,color+3); /*�����õ���ɫʵ�����*/ 
bar(2*width+width/2,height/2,15*width/2,3*height/2); /*���ǽ����*/ 
outtextxy(5*width,height,"0."); /*��ʾ�ַ���*/ 
} 
if(c=='Q')exit(0); /*���ѡ����q�س��������������*/ 
} 
putimage(x,y,rar,XOR_PUT); /*���˳�֮ǰ��ȥ����ͷ*/ 
return; /*����*/ 
} 
/*���ں���*/ 
void mwindow( char *header ) 
{ 
int height; 
cleardevice(); /* ���ͼ����Ļ */ 
setcolor( MaxColors - 1 ); /* ���õ�ǰ��ɫΪ��ɫ*/ 
setviewport( 20, 20, MaxX/2, MaxY/2, 1 ); /* �����ӿڴ�С */ 
height = textheight( "H" ); /* ��ȡ�����ı���С */ 
settextstyle( DEFAULT_FONT, HORIZ_DIR, 1 );/*�����ı���ʽ*/ 
settextjustify( CENTER_TEXT, TOP_TEXT );/*�����ַ����з�ʽ*/ 
outtextxy( MaxX/4, 2, header ); /*�������*/ 
setviewport( 20,20+height+4, MaxX/2+4, MaxY/2+20, 1 ); /*�����ӿڴ�С*/ 
drawboder(); /*���߿�*/ 
} 
void drawboder(void) /*���߿�*/ 
{ 
struct viewporttype vp; /*�����ӿ����ͱ���*/ 
setcolor( MaxColors - 1 ); /*���õ�ǰ��ɫΪ��ɫ */ 
setlinestyle( SOLID_LINE, 0, NORM_WIDTH );/*���û��߷�ʽ*/ 
getviewsettings( &vp );/*����ǰ�ӿ���Ϣװ��vp��ָ�Ľṹ��*/ 
rectangle( 0, 0, vp.right-vp.left, vp.bottom-vp.top ); /*�����α߿�*/ 
} 
/*������ͼ�κ���*/ 
int arrow() 
{ 
int size; 
int raw[]={4,4,4,8,6,8,14,16,16,16,8,6,8,4,4,4}; /*������������*/ 
setfillstyle(SOLID_FILL,2); /*�������ģʽ*/ 
fillpoly(8,raw); /*����һ����ͷ*/ 
size=imagesize(4,4,16,16); /*����ͼ���С*/ 
rar=malloc(size); /*�����ڴ�����*/ 
getimage(4,4,16,16,rar); /*��Ź���ͷͼ��*/ 
putimage(4,4,rar,XOR_PUT); /*��ȥ����ͷͼ��*/ 
return 0; 
} 
/*��������*/ 
int specialkey(void) 
{ 
int key; 
while(bioskey(1)==0); /*�ȴ���������*/ 
key=bioskey(0); /*��������*/ 
key=key&0xff? key&0xff:key>>8; /*ֻȡ�������ɨ��ֵ������Ϊ0*/ 
return(key); /*���ؼ�ֵ*/ 
} 
