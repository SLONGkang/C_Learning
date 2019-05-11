
#include <windows.h>

#pragma comment(lib, "Winmm.lib")

 

int main(int argc, char *argv[])

{

	//文件类型只能是波形文件

	PlaySound(TEXT("Data\\1.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

	Sleep(50000);							//等待声音播放

	return 0;

}

