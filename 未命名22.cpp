
#include <windows.h>

#pragma comment(lib, "Winmm.lib")

 

int main(int argc, char *argv[])

{

	//�ļ�����ֻ���ǲ����ļ�

	PlaySound(TEXT("Data\\1.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

	Sleep(50000);							//�ȴ���������

	return 0;

}

