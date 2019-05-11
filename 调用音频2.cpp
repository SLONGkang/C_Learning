#include<iostream>
#include<windows.h>
 
#pragma comment(lib,"winmm.lib")
using namespace  std;
 
int main()
{
    if(PlaySound(TEXT("D:\\ksl.wav"),0,SND_FILENAME|SND_ASYNC|SND_LOOP))
    {
        cout<<"ÒôÀÖÒÑ²¥·Å"<<endl;
    }
    else
    {
        cout<<"²¥·ÅÊ§°Ü"<<endl;
    }
system("PAUSE");
return 0;
}
