#include<stdio.h>
#include<string.h>
int main()
{
    char str[20] ={'\0'}
    char p[20] = {'\0'};
    gets(str);
    int s = 0;
    int mark;
    int i = 0;
    for (int j = 0; j < sizeof(str) + 1; j++)
    {
        if (str[j] == '-')
        {
            s++;
        }
        if (s == 2)
        {
            mark = j;
            break;
        }
    }
    for (int k = mark + 1; k < strlen(str) ; k++)
    {
        p[i++] = str[k];
    }
    p[i++] = '-';
    for (int k = 0; k < mark; k++)
    {
        p[i++] = str[k];
    }
    p[i] = '\0';
    printf("%s", p);    getchar();
return 0;
}
