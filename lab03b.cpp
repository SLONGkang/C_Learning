#include<stdio.h>
int main(){

float h,r,g,n,f,s,a,m;//�ֱ�Ϊ����ʱ�䣬Сʱ���ʣ��ܹ��ʣ�˰���ʣ�����˰����˰������˰��ҽ��˰

A:
printf("Hours per Week:\t\t");
scanf("%f",&h);
printf("Hourly Rate:\t\t$");
scanf("%f",&r);



g=h*r;
f=0.1*g;
s=0.014*g;
a=0.062*g;
m=0.0145*g;

n=g-f-s-a-m;


printf("Gross Pay:\t\t$%.2f\n",g);
printf("Net Pay:\t\t$%.2f\n\n",n);
printf("Deductions\nFederal:\t\t$%.2f\n",f);
printf("State:\t\t\t$%.2f\n",s);
printf("FICA:\t\t\t$%.2f\n",a);
printf("Medicare:\t\t$%.2f\n\n------------------------------------------\n\n",m);

goto A;
return 0;
}
