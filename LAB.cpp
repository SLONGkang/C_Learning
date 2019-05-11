#include<stdio.h>
int main()
{
int x=0,m,s,a[9],i;
printf("Enter in the value: ");
for(i=0;i<9;i++)
scanf("%d",&a[i]);
printf("\n");
printf("You enterd:\n%d %d %d\n%d %d %d\n%d %d %d\n\n",a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8]);
printf("Analyzing...\n");
i=0;
s=a[i]+a[i+1]+a[i+2];
m=a[i]+a[i+3]+a[i+6];

if(s==15)
;
else
{
x=1;
printf("[%d,%d,%d] dose not work!\n",a[i],a[i+1],a[i+2]);
}
i=i+3;
s=a[i]+a[i+1]+a[i+2];

if(s==15)
;
else{
x=1;
printf("[%d,%d,%d] dose not work!\n",a[i],a[i+1],a[i+2]);
}

i=i+3;
s=a[i]+a[i+1]+a[i+2];
if(s==15)
;
else{
printf("[%d,%d,%d] dose not work!\n",a[i],a[i+1],a[i+2]);
x=1;
}
i=0;

if(m==15)
;
else
{
x=1;
printf("Column %d dose not work!\n",i);
}
i+=1;
m=a[i]+a[i+3]+a[i+6];
if(m==15)
;
else
{
x=1;
printf("Column %d dose not work!\n",i);
}
i+=1;
m=a[i]+a[i+3]+a[i+6];

if(m==15)
;
else
{
x=1;
printf("Column %d dose not work!\n",i);
}

if(x==0)
{
printf("\nThis is a magic square!\n");
}
else
printf("\nThis is not a magic square!\n");

return 0;

}



