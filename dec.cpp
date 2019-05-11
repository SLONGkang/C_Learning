#include<stdio.h>
#include<math.h>
int main()
{

int x,m,y;
double i;
printf("Starting the CPSC 1011 Decimal to Binary Converter!\n\n");

for(;printf("Please enter a binary number (or EOF to quit): "),scanf("%lf",&i)!=EOF ; )
{


        x=i;
    
        if(i>0&&i==x)
                ;
        else
        {
                printf("\n\tSorry,that was not a binary whole number.\n\n");
                continue;
        }

        for(;x>0;)
        {
                y=x%10;
                x=x/10;
                if(y!=1&&y!=0)
                        break;
        }
        if(y!=1&&y!=0)
        {
                printf("\n\tSorry that not a binary whole number.\n\n");
                continue;
        }

       
        x=i;
            y=0;
        for(m=0;x>0;m++)
        {
                y+=(x%10)*(pow(2,m));
                x=x/10;
        }

        x=i;
        printf("\n\t%d (base-2) is equivalent to ",x);
      

                        printf("%d",y);


       
        printf(" (base-10)!\n\n");
	}

        printf("\n\tThank you for using the CPSC 1011 Decimal to Binary Generator.\n");
		printf("Goodbye!\n");
        return 0;
}
