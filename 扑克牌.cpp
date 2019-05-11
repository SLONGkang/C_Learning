#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<mem.h> 
struct POKER
{
    int num; // A:1 , J:11 , Q:12 , K:13
    int color; //ºÚ1,ºì2,Ã·3,·½4
}s[52];
 
int main()
{
    int i,num,color;
    memset(s,0,sizeof(struct POKER)*52);
    srand((unsigned)time(0));
     
    int count=0;
    while(count<52)
    {
        num=rand()%13+1;
        color=rand()%4+1;
        int flag_skip=0,flag_end=0;
        for(i=0;i<52;i++)
        {
            if(s[i].num==num && s[i].color==color)
            {
                flag_skip=1;
                break;
            }
        }
        if(flag_skip==1)
        {
            continue;
        }
        while(1)
        {
            i=rand()%52;
            if(s[i].num==0)
            {
                s[i].num=num;
                s[i].color=color;
                count++;
                break;
            }
            else
            {
                continue;
            }
        }       
    }
    for(i=0;i<52;i++)
    {
        if(i%13==0)
        {
            printf("\nÍæ¼Ò%d : ",i/13+1);
        }
        switch(s[i].num)
        {
            case 1: putchar('A');break;
            case 11: putchar('J');break;
            case 12: putchar('Q');break;
            case 13: putchar('K');break;
            default: printf("%d",s[i].num);
        }
        switch(s[i].color)
        {
            case 1:    putchar(6);break;
            case 2: putchar(3);break;
            case 3: putchar(5);break;
            case 4: putchar(4);break;
            default: printf(" ");
        }
        printf(" ");
    }
    return 0;
}
