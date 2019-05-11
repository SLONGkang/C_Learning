#include<stdio.h>
int main()
{
        int y;
        double x,z;
        x=100.0;
        z=0;
        for(y=10;y>0;y--){
                z=x/2+x+z;
                x=x/2;
        }
    printf("%f\n",z); 
    printf("%f",x);
    return 0;

}

