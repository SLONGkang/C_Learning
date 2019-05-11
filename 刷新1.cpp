#include<stdio.h>
#include<time.h>
#include<stdlib.h> 
#include <conio.h>
int main(){
int i;
    for(i=0;i<100;i++)
    {
        system("cls");
        printf("%d",i);       // 具体打印内容，在printf这里设计，可以做一个子函数来用

        Sleep(1);
    }
    system("pause");
return 0;
}
