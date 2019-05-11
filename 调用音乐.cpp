#include<iostream>
#include<windows.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib") 
using namespace std;
#include<stdio.h>
int main()

{

	//文件类型只能是波形文件

	PlaySound(TEXT("D:\\ksl.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

	Sleep(50000);							//等待声音播放

	return 0;

}

