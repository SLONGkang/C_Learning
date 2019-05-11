#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int i,y,c,computer=0,you=0,tied=0,matches;
	char x;
	printf("Startig the CPSC 1011 Rock, Paper, Scissors Game!\n\nEnter the number of matches to play: ");
	scanf("%d",&matches);
	printf("\n");
	
	for(i=1;i<=matches;i++)
	{
		A:
		printf("\tMatch%d: Enter R for rock,P for paper,or S for scissors:",i);
		
		
		scanf("%d"); 
		scanf("%c",&x);
		
		switch(x)
		{
			case 'S':y=0;break;
			case 'R':y=1;break;
			case 'P':y=2;break;
			default :printf("\tErrors!Again!\n");goto A;
		}
		
		srand(time(NULL));
		c=rand()*rand()%3;
	
		if(y==0)
		{
			switch(c)
			{
				case 0:
					printf("\tThe computer chose scissors.You tied.\n");
					tied+=1;
					break;
				case 1:
					printf("\tThe computer chose rock.You lose.\n");
					computer+=1;
					break;
				case 2:
					printf("\tThe computer chose paper.You win!\n");
					you+=1;
					break;
			}
			
		}
		
		if(y==1)
		{
			switch(c)
			{
				case 0:
					printf("\tThe computer chose scissors.You win!.\n");
					you+=1;
					break;
				case 1:
					printf("\tThe computer chose rock.You tied.\n");
					tied+=1;
					break;
				case 2:
					printf("\tThe computer chose paper.You lose.\n");
					computer+=1;
					break;
			}
			
		}
		
		if(y==2)
		{
			switch(c)
			{
				case 0:
					printf("\tThe computer chose scissors.You lose.\n");
					computer+=1;
					break;
				case 1:
					printf("\tThe computer chose rock.You win!\n");
					you+=1;
					break;
				case 2:
					printf("\tThe computer chose paper.You tied.\n");
					tied+=1;
					break;
			}
			
		}
		printf("\tScores:\t");
		if(you!=0)
		printf("You-%d\t",you);
		if(computer!=0)
		printf("Computer-%d\t",computer);
		if(tied!=0)
		printf("Tied-%d\n",tied); 
		printf("\n\n"); 
	}
	printf("The game of %d matches is complete.",matches);
    printf("The final scores are:\nYou:\t\t%d\nComputer:\t%d\nTies:\t\t%d\n",you,computer,tied);

    return 0;	
 } 
