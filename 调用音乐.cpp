#include<iostream>
#include<windows.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib") 
using namespace std;
#include<stdio.h>
int main()

{

	//�ļ�����ֻ���ǲ����ļ�

	PlaySound(TEXT("D:\\ksl.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

	Sleep(50000);							//�ȴ���������

	return 0;

}

