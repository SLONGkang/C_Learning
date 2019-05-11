#include<stdio.h>
#include<stdlib.h> 
int  main()
{    
int i = 1;    
while(1)    
{    
 printf("在while（1）里\n");  
       while(i++)  
	      {
           printf("i = %d\n",i);
   if(i > 3)  
             {
			                 goto TiaoChu; 
		           }  
				         }
						     }
   
	  	 TiaoChu:   printf("程序结束\n"); 
	     return 0;
		 }

