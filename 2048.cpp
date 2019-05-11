#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
int main()
{
printf("正在启动中，请稍后！\n");
Sleep(1000);
system("bin\\Version\\games\\0.1\\0.1.exe");
return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#define WIN 256 // 可以修改决定游戏输赢的值
// 矩阵数组
int num[4][4]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int t[5]={0,0,0,0,0}; // 辅助数组
int move=0;   // 记录移动步数
int score=0;  // 记录得分情况
int max=0;  // max表示游戏输赢，max=WIN时赢
int change=1;
// 产生一个随机位置和随机数
void Srand()
{
  int i,j;
  do// 产生一个随机位置，如果产生的位置有数据，就继续随机生成一个新位置
  {
    i=((unsigned)rand())%4;
    j=((unsigned)rand())%4;
  }while(num[i][j]!=0);
  if(((unsigned)rand())%4==0)
  {   // 产生一个随机数，如果该数对4取余=0，则填充为4
    num[i][j]=4;
  }
  else
  {
    num[i][j]=2;
  }
  move++;
}
void Print()
{
  int j,i;
  system("CLS");
  printf("*~~~~~~~~2048~~~~~~~*\n");
  printf("*author:  亚威      *\n");
  printf("*得分: %d  步数: %d  \n",score,move);
  printf("*~~~~~~~~~~~~~~~~~~~*\n");
  for(i=0;i<=3;i++)
  {
    for(j=0;j<=3;j++)
    {
      if(num[i][j]==0)
        printf("*    ");
      else
        printf("*%4d",num[i][j]);
    }
    printf("*\n*~~~~~~~~~~~~~~~~~~~*\n");
  }
}
// 消除t数组中前面和中间出现的0
void fun()
{
  int i,j;
  for(i=0;i<=3;i++)
  {
    if(t[i]==0)
    {
      for(j=i+1;j<=3;j++)
      {
        if(t[j]!=0)
        {
          change=1;
          break;
        }
      }
      t[i]=t[j];
      t[j]=0;
    }
    if(j>=3)
      break;
  }
}
// 合并操作
void hebing()
{
  int i;
  for(i=0;i<=2;i++)
  {
    if((t[i]!=0)&&(t[i]==t[i+1]))
    {
      t[i]*=2;
      score+=t[i];
      change=1;
      t[i+1]=0;
    }
    if(max<t[i])
      max=t[i];
  }
}
// 合并相邻且相等的两个数
void add()
{
  fun();  // 消除前面的和中间的0
  hebing();  // 合并相邻且相等的两个数
  fun();  // 再次消0
}
int main()
{
  int i,j;
  int gameover=1;
  // 产生一个随机位置
  srand((unsigned)time(NULL));
  max=0;
  while(gameover&&(max<WIN))
  {
    
    if(change)
    {
      Srand();  // 产生一个随机位置和随机数
    }
    
    change=0;
    Print();  // 显示界面
    char in=getch();  // 读取操作命令
    switch(in)
    {
    case 'w':
    case 'W':
      for(i=0;i<=3;i++)
      {  // 依次处理第1至第4列
        for(j=0;j<=3;j++)
        {   // 把第i列的数据依次赋给辅助数组t
          t[j]=num[j][i];
        }
        add();  // 核心：合并相邻且相等的两个数
        for(j=0;j<=3;j++)
        {   // 把处理后的数据依次放到矩阵对应位置
          num[j][i]=t[j];
        }
      }
      
      break;
    case 's':
    case 'S':
      for(i=0;i<=3;i++)
      {  // 依次处理第1至第4列
        for(j=0;j<=3;j++)
        {   // 把第i列的数据依次赋给辅助数组t
          t[3-j]=num[j][i];
        }
        add();  // 核心：合并相邻且相等的两个数
        for(j=0;j<=3;j++)
        {   // 把处理后的数据依次放到矩阵对应位置
          num[j][i]=t[3-j];
        }
      }
      break;
    case 'a':
    case 'A':
      for(i=0;i<=3;i++)
      {  // 依次处理第1至第4列
        for(j=0;j<=3;j++)
        {   // 把第i列的数据依次赋给辅助数组t
          t[j]=num[i][j];
        }
        add();  // 核心：合并相邻且相等的两个数
        for(j=0;j<=3;j++)
        {   // 把处理后的数据依次放到矩阵对应位置
          num[i][j]=t[j];
        }
      }
      break;
    case 'd':
    case 'D':
      for(i=0;i<=3;i++)
      {  // 依次处理第1至第4列
        for(j=0;j<=3;j++)
        {   // 把第i列的数据依次赋给辅助数组t
          t[3-j]=num[i][j];
        }
        add();  // 核心：合并相邻且相等的两个数
        for(j=0;j<=3;j++)
        {   // 把处理后的数据依次放到矩阵对应位置
          num[i][j]=t[3-j];
        }
      }
      break;
    }
    gameover=0;
    for(i=0;i<=3;i++)
    {
      for(j=0;j<=3;j++)
      {
        if(num[i][j]==0)
          gameover=1;
      }
    }
    if((gameover==0)&&(change==0))
      break;
  }
  Print();
  if(max>=WIN)
  {
    printf("你赢了！\n");
    printf("你很牛啊!!!\n");
  }
  else
  {
    printf("游戏结束！\n");
    printf("努力啊!!!\n");
  }
  getch();
  return 0;
}


