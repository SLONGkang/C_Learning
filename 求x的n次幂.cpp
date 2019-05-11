#include <stdio.h>

double mypow( double x, int n );

int main()
{
    double x;
    int n;

    scanf("%lf %d", &x, &n);
    mypow(x, n);

    return 0;
}

double mypow( double x, int n )
{
  double z;
  int i;
  i=1;
  z=1;
  if(n<0)
     printf("´íÎó£¡");
  else
    if(n==0)
      z=1;
    else
      do{
      	z=z*x;
      	i=i+1;
	  }while(i<=n);
	  printf("%lf",z);
  return z;
}


