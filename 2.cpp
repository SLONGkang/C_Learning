
//c语言动态心型的实现代码，帮助熟悉指针和程序：

 

#include <stdio.h>
#include <windows.h> 
#include <stdlib.h>

void show( int m)

{
	float y, x, z, f;
    for (y = 1.5f; y > -1.5f; y-=0.1f)
    {
        for (x = -1.5f; x < 1.5f; x += 0.05f)
        {
            z = x*x + y*y -1;
            f = z*z*z - x*x*y*y*y;
            putchar(f <= 0.0f ? "*********"[(int)(f*-8.0f)]:' ');
        }
        putchar('\n');
    }

    getchar();

   // char a[3][5];

 

char *a=(char *)malloc((4*m/2+m)*(4*m+m));

    int i,j,k;

         

for(k=0;k<(4*m/2+m);k++)

 

for(i=0;i<(4*m+m);i++)

 

 *(a+k*(4*m+m)+i)=' ';

 

 

 

 

  for(i=0;i<=(4*m/2);i++)

  * (a+i+((4*m/2)-i)*(4*m+m))='*';

 

  for(j=(4*m/2);j<=4*m;j++)

   *(a+j+(j-(4*m/2))*(4*m+m))='*';

 

 

 

 for(k=0;k<(4*m/2+1);k++)

 {

   for(i=0;i<(4*m+m);i++)

   {

     printf("%c",*(a+(k*(4*m+m))+i));

    }

     printf("\n");

  }

 

 

}

 

int main()

{

   int num;

int b;

   printf("please input one number:");

   scanf("%d",&num);

   show(num);

while(num)

{

   for(b=0;b<6;b++)

   {

   Sleep(1);

   show(b);

   }

 for(b=6;b>=0;b--)

   {

   Sleep(1);

   show(b);

   }

   exit(1);

}
 

return 0;

}

