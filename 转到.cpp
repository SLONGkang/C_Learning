#include<stdio.h>
#include<stdlib.h> 
int  main()
{    
int i = 1;    
while(1)    
{    
 printf("��while��1����\n");  
       while(i++)  
	      {
           printf("i = %d\n",i);
   if(i > 3)  
             {
			                 goto TiaoChu; 
		           }  
				         }
						     }
   
	  	 TiaoChu:   printf("�������\n"); 
	     return 0;
		 }

