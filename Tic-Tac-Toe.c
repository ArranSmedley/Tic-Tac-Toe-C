#include<stdio.h>


typedef struct Player
{
	char Name[10];
	char Symbol;
	int number;				//Player Struct
	
	struct Player *next;
} player;


typedef struct Board
{
	char matrix[3][3]; //2D Array
	int MP;					//Board Struct
	
} board;


typedef struct 	Pieces
{
	char X;
	char O;					//Pieces Struct
} pieces;


typedef struct Positons
{
	int x;					//Positions Struct
	int y;
} position;


void init_board(char matrix[3][3]);
void get_computer_move(char matrix[3][3]);
char check(char matrix[3][3]);
void print_state(char matrix[3][3]);
void print_instructions();


int main(void)
{
	PlayGame(); //Start playing the game

	if (PlayGame() == 0)
	{
			
    PlayGame(); //If game ends replay the game	

	}	
}

int PlayGame(int MatchesPlayed)
{
	board brd;
	position pos;
	pieces pie; 			//Declaring Variables
	char winner;
	
    int rounds_played, selection;
	
	winner = ' ';
	
	player p1;
	player p2;
	player AI;
	
	int current_player = 1;
	int isPlaying;
	int drawCount = 0;
	
	int option;
	
	printf("\n \n \n ****TIC TAC TOE****\n");
    printf("\n Enter 1 of the following options: \n \n");
	printf("1. Player vs Player \n");						//Start menu
	printf("2. Player vs AI \n");
	printf("3. Exit \n");
	scanf("%d",&option);
	
	
	
	switch(option)
        {
            case 1:
		
					isPlaying = 1;    //Selections for menu
            break;
			
            case 2: 
			
					isPlaying = 2;
            break;
			
			case 3: return 0;
		}
		
	
	
	
	
	if (isPlaying == 1)
	{
			system("cls"); 		//Clear screen
	init_board(brd.matrix);   //Initialise board
	print_instructions();		//Print the rules and instructions
	printf("Enter player-1 name: ");
	scanf("%s", &p1.Name);
	p1.Symbol = 'X';					//Enter player names symbols will be assigned
	p1.number = 1;
	printf("Enter player-2 name: ");
	scanf("%s", &p2.Name);
	p2.Symbol = 'O';	
	p2.number = 2;
	system("cls");
	printf("%s's symbol is 'X'.\n\n", p1.Name);
	printf("%s's symbol is 'O'.\n\n", p2.Name);
	pie.X = p1.Symbol ;
	pie.O = p2.Symbol;

	print_state(brd.matrix);	//Print board
	}
	
	
	
	if (isPlaying == 2)
	{
			system("cls");
	init_board(brd.matrix);
	print_instructions();
	printf("Enter player-1 name: ");
	scanf("%s", &p1.Name);
	p1.Symbol = 'X';
	AI.Symbol = 'O';
	system("cls");								//Players Symbol is set and AI's is set also
	printf("%s's symbol is 'X'.\n\n", p1.Name);
	printf("AI's symbol is 'O'.\n\n");

	

	pie.X = p1.Symbol;
	pie.O = AI.Symbol;
	
	print_state(brd.matrix);
	}
  
  
  
  
  
	while (isPlaying == 1)
	{
		switch(current_player)
		{
			case 1: 
				printf("Player %s's turn .. \n", p1.Name);   //Enter co-ordinates
				printf("Enter X,Y coordinates for your move: ");
				scanf("%d%*c%d", &pos.x, &pos.y);
				pos.x--; 
				pos.y--;
				
				if(brd.matrix[pos.x][pos.y]!= ' ')
				{
					printf("\nInvalid move, try again.\n");		//If co-ordinates arent right or is empty invalid
					current_player = 1;
					break;
					
				}
				else 
				{ 
					brd.matrix[pos.x][pos.y] = pie.X; //Put symbol in section
				}
				system("cls");
				print_state(brd.matrix);   //Re-print board
				winner = check(brd.matrix);  //Check is player is winning
				if(winner == 'Y')
				{
					printf("Player 1 won!\n");
					isPlaying = 0;
					break;
				}
				
				drawCount = 0;
				for(int x = 0; x < 3; x++)
				{
					for(int y = 0; y < 3; y++)
					{
						if(brd.matrix[x][y] != ' ')
						{
							drawCount++;		//for every section on the board
						}
					}
				}
				if(drawCount >= 9)
				{
				///GAME is a draw
				printf("DRAW");
					isPlaying = 0;			//if section is equal or greater than 9 its a draw
					return 0;
					break;
					
				}
				
				current_player = 2; 	//Switch curnt player
			case 2:
				printf("Player %s's turn .. \n", p2.Name); 
				printf("Enter X,Y coordinates for your move: ");
				scanf("%d%*c%d", &pos.x, &pos.y);
				pos.x--; 
				pos.y--;
				
				if(brd.matrix[pos.x][pos.y]!= ' ')
				{
					printf("\n Invalid move, try again.\n");
					current_player = 2;
					break;
				}
				else 
				{
					brd.matrix[pos.x][pos.y] = pie.O;
				}
				system("cls");
				print_state(brd.matrix);
				winner = check(brd.matrix);	
				
				if(winner == 'Y')
				{
					printf("Player 2 won!\n");
					isPlaying = 0;
					break;
				}
				
				drawCount = 0;
				for(int x = 0; x < 3; x++)
				{
					for(int y = 0; y < 3; y++)
					{
						if(brd.matrix[x][y] != ' ')
						{
							drawCount++;
						}
					}
				}
				if(drawCount >= 9)
				{
				///GAME is a draw
				printf("DRAW");
					isPlaying = 0;
					break;
				}
							
				current_player = 1;
		}
	}
		
				
				
				
	while (isPlaying == 2)
	{
		switch(current_player)
		{
			case 1: 
				printf("Player %s's turn .. \n", p1.Name); 
				printf("Enter X,Y coordinates for your move: ");
				scanf("%d%*c%d", &pos.x, &pos.y);
				pos.x--; 
				pos.y--;
				
				if(brd.matrix[pos.x][pos.y]!= ' ')
				{
					printf("\nInvalid move, try again.\n");
					current_player = 1;
					break;
					
				}
				else 
				{ 
					brd.matrix[pos.x][pos.y] = pie.X; 
				}
				system("cls");
				print_state(brd.matrix);
				winner = check(brd.matrix);
				if(winner == 'Y')
				{
					printf("Player 1 won!\n");
					isPlaying = 0;
					break;
				}
				
				drawCount = 0;
				for(int x = 0; x < 3; x++)
				{
					for(int y = 0; y < 3; y++)
					{
						if(brd.matrix[x][y] != ' ')
						{
							drawCount++;
						}
					}
				}
				if(drawCount >= 9)
				{
				///GAME is a draw
				printf("DRAW");
					isPlaying = 0;
					return 0;
					break;
					
				}
				
				current_player = 2;
			case 2:
			
				printf("Player AI's turn .. \n", p1.Name); 
				printf("Enter X,Y coordinates for your move: ");
				pos.x = rand() % 3 + 1;
				pos.y = rand() % 3 + 1; //Random points for AI 
				pos.x--; 
				pos.y--;
				
				if(brd.matrix[pos.x][pos.y]!= ' ')
				{
					printf("\n Invalid move, try again.\n");
					current_player = 2;
					break;
				}
				else 
				{
					brd.matrix[pos.x][pos.y] = pie.O;
				}
				
				system("cls");
				print_state(brd.matrix);
				winner = check(brd.matrix);
				if(winner == 'Y')
				{
					printf("Player AI won!\n");
					isPlaying = 0;
					break;
				}
				current_player = 1;
		}
	}
				
	if (isPlaying == 0)
	{
 return 0;
	}
}


void init_board(char matrix[3][3])
{
	  int i, j;

  for(i=0; i<3; i++) 			//Initialise board make sure all sections are empty
    for(j=0; j<3; j++) matrix[i][j] =  ' ';


}



char check(char matrix[3][3])
{
  char Yes = 'N';
  
  for(int i=0; i<3; i++)  //check rows 
  {
	if(matrix[i][0]== matrix[i][1] &&
       matrix[i][0]== matrix[i][2] && matrix[i][0] != ' ')
	   {
		   Yes = 'Y';
	   }
  }
	   

  for(int i=0; i<3; i++)  //check columns 
    if(matrix[0][i]== matrix[1][i] &&
       matrix[0][i]== matrix[2][i] && matrix[0][i] != ' ')
	   Yes = 'Y';

  //check diaganols
  if(matrix[0][0]== matrix[1][1] &&
     matrix[1][1]== matrix[2][2] && matrix[0][0] != ' ')
       Yes = 'Y';

  if(matrix[0][2]== matrix[1][1] &&
     matrix[1][1]== matrix[2][0] && matrix[0][2] != ' ')
       Yes = 'Y';

  return Yes;
}




void print_state(char matrix[3][3])
{
  int t;

	printf("   1   2   3 \n"); //y co-ordinates
  for(t=0; t<3; t++) {	  
  printf("%d  %c | %c | %c ",(t + 1), matrix[t][0],
            matrix[t][1], matrix [t][2]); //Print main board and x co-ordinates
    if(t!=2) printf("\n  ---|---|---\n");
  }
  printf("\n");
}

void print_instructions()
{
 
	 
  printf("\n When prompted to make a move, simply enter the x and y co-ordinates \n corresponding to a tile of your choosing. \n");
  printf("\n Enter Player names below.  \n");
  printf("\n ");
 
}
