#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
int main()
{
printf("���������У����Ժ�\n");
Sleep(1000);
system("bin\\Version\\games\\0.1\\0.1.exe");
return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#define WIN 256 // �����޸ľ�����Ϸ��Ӯ��ֵ
// ��������
int num[4][4]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int t[5]={0,0,0,0,0}; // ��������
int move=0;   // ��¼�ƶ�����
int score=0;  // ��¼�÷����
int max=0;  // max��ʾ��Ϸ��Ӯ��max=WINʱӮ
int change=1;
// ����һ�����λ�ú������
void Srand()
{
  int i,j;
  do// ����һ�����λ�ã����������λ�������ݣ��ͼ����������һ����λ��
  {
    i=((unsigned)rand())%4;
    j=((unsigned)rand())%4;
  }while(num[i][j]!=0);
  if(((unsigned)rand())%4==0)
  {   // ����һ������������������4ȡ��=0�������Ϊ4
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
  printf("*author:  ����      *\n");
  printf("*�÷�: %d  ����: %d  \n",score,move);
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
// ����t������ǰ����м���ֵ�0
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
// �ϲ�����
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
// �ϲ���������ȵ�������
void add()
{
  fun();  // ����ǰ��ĺ��м��0
  hebing();  // �ϲ���������ȵ�������
  fun();  // �ٴ���0
}
int main()
{
  int i,j;
  int gameover=1;
  // ����һ�����λ��
  srand((unsigned)time(NULL));
  max=0;
  while(gameover&&(max<WIN))
  {
    
    if(change)
    {
      Srand();  // ����һ�����λ�ú������
    }
    
    change=0;
    Print();  // ��ʾ����
    char in=getch();  // ��ȡ��������
    switch(in)
    {
    case 'w':
    case 'W':
      for(i=0;i<=3;i++)
      {  // ���δ����1����4��
        for(j=0;j<=3;j++)
        {   // �ѵ�i�е��������θ�����������t
          t[j]=num[j][i];
        }
        add();  // ���ģ��ϲ���������ȵ�������
        for(j=0;j<=3;j++)
        {   // �Ѵ������������ηŵ������Ӧλ��
          num[j][i]=t[j];
        }
      }
      
      break;
    case 's':
    case 'S':
      for(i=0;i<=3;i++)
      {  // ���δ����1����4��
        for(j=0;j<=3;j++)
        {   // �ѵ�i�е��������θ�����������t
          t[3-j]=num[j][i];
        }
        add();  // ���ģ��ϲ���������ȵ�������
        for(j=0;j<=3;j++)
        {   // �Ѵ������������ηŵ������Ӧλ��
          num[j][i]=t[3-j];
        }
      }
      break;
    case 'a':
    case 'A':
      for(i=0;i<=3;i++)
      {  // ���δ����1����4��
        for(j=0;j<=3;j++)
        {   // �ѵ�i�е��������θ�����������t
          t[j]=num[i][j];
        }
        add();  // ���ģ��ϲ���������ȵ�������
        for(j=0;j<=3;j++)
        {   // �Ѵ������������ηŵ������Ӧλ��
          num[i][j]=t[j];
        }
      }
      break;
    case 'd':
    case 'D':
      for(i=0;i<=3;i++)
      {  // ���δ����1����4��
        for(j=0;j<=3;j++)
        {   // �ѵ�i�е��������θ�����������t
          t[3-j]=num[i][j];
        }
        add();  // ���ģ��ϲ���������ȵ�������
        for(j=0;j<=3;j++)
        {   // �Ѵ������������ηŵ������Ӧλ��
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
    printf("��Ӯ�ˣ�\n");
    printf("���ţ��!!!\n");
  }
  else
  {
    printf("��Ϸ������\n");
    printf("Ŭ����!!!\n");
  }
  getch();
  return 0;
}


