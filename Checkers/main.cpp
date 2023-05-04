#include <iostream>
#include "pawn.h"
#include "player.h"
pawn board[8][8];
void printBoard(pawn board[8][8]);
pawn* fillBoard(pawn board[8][8]);
void move(player player, pawn board [ 8] [ 8]);

int main()
{
	player player1; player1.setPNumber(1);
	player player2; player2.setPNumber(2);
	fillBoard(board);
	printBoard(board);
	move(player1, board);
	move(player2, board);
	std::cout << std::endl;
	return 0;
}
pawn* fillBoard(pawn board [8] [8])
{
	for (int i = 0; i < 8; i++)
	{
		for (int k = 0; k < 8; k++)

		{
			


			if (i == 0 && k%2 == 0)
			{
				pawn pawn;
				pawn.setx(k);
				pawn.sety(i);
				pawn.setTile('*');
				board[i][k].setTile(pawn.getTile());
			}
			else if(i==1 && k%2 !=0)
			{
				pawn pawn;
				pawn.setx(k);
				pawn.sety(i);
				pawn.setTile('*');
				board[i][k].setTile(pawn.getTile());

			}
			else if (i == 2 && k % 2 == 0)
			{	pawn pawn;
				pawn.setx(k);
				pawn.sety(i);
				pawn.setTile('*');
				board[i][k].setTile(pawn.getTile());
			}
			else if (i == 5 && k % 2 == 0)
			{
				pawn pawn;
				pawn.setx(k);
				pawn.sety(i);
				pawn.setTile('^');
				board[i][k].setTile(pawn.getTile());
			}
			else if (i == 6 && k % 2 != 0)
			{
				pawn pawn;
				pawn.setx(k);
				pawn.sety(i);
				pawn.setTile('^');
				board[i][k].setTile(pawn.getTile());
			}
			else if (i == 7 && k % 2 == 0)
			{
				pawn pawn;
				pawn.setx(k);
				pawn.sety(i);
				pawn.setTile('^');
				board[i][k].setTile(pawn.getTile());
			}
			else {
				board[i][k].setTile(' ');
			}
		}
	}
	return* board;
}
void printBoard(pawn board[8][8])
{
	int j = 1;
	int l = 1;
	for (int i = 0; i < 8; i++)
	{
		
		if (j != 1)
		{
			l = i+1;
			printf("%d", l);
		}
		for (int k = 0; k < 8; k++)
		{
			for ( j; j < 9; j++)
			{
				
				printf("%*d ",4,j);
				
			}
			if (j == 9)
			{
				std::cout << std::endl; printf("%d", l);
				j++;
			}
			
			std:: cout << "| "<< board[i][k].getTile() << "  ";

		}
		std::cout << "|" << std::endl;
		std::cout << "  ";
		for (int i = 0; i < 40; i++)
		{
			
			printf("%c", '-');
		}
		printf("\n");
	}
}

void move(player player, pawn board[8][8])
{	// x y coordinates of a tile a player wishes to move
	int pXTChoice = 0;
	int pYTChoice = 0;
	// x y coordinates of a open square where a player wishes to move their selected tile. 
	int pXDChoice = 0;
	int pYDChoice = 0;
	std::cout << "PLayer" << player.getPNumber() <<" Pick an x coordinate and then a y coordinate to select which tile to move";
	std::cin >> pXTChoice; std::cin >> pYTChoice;
	pXTChoice = pXTChoice - 1; pYTChoice = pYTChoice - 1;
	if (player.getPNumber() == 1)
	{
		while (board[pYTChoice][pXTChoice].getTile() != '*')
		{
			std::cout << " please select a valid choice for player1 a ( * ) tile" << std::endl;
			std::cin >> pXTChoice; std::cin >> pYTChoice;
			pXTChoice = pXTChoice - 1; pYTChoice = pYTChoice - 1;

		}
		printf("\n%s\n", "Select a x and y destination for your tile. ");
		std::cin >> pXDChoice; std::cin >> pYDChoice;
		pXDChoice = pXDChoice - 1; pYDChoice = pYDChoice - 1;
		board[pYDChoice][pXDChoice].setTile('*');
		board[pYTChoice][pXTChoice].setTile(' ');

	}else if(player.getPNumber() == 2)
	{
		while (board[pYTChoice][pXTChoice].getTile() != '^')
		{
			std::cout << " please select a valid choice for player2  a ( ^ ) tile" << std::endl;
			std::cin >> pXTChoice; std::cin >> pYTChoice;
			pXTChoice = pXTChoice - 1; pYTChoice = pYTChoice - 1;
		}
		printf("\n%s\n", "Select a x and y destination for your tile. ");
		std::cin >> pXDChoice; std:: cin >> pYDChoice;
		pXDChoice = pXDChoice - 1; pYDChoice = pYDChoice - 1;
		board[pYDChoice][pXDChoice].setTile('^');
		board[pYTChoice][pXTChoice].setTile(' ');
	}
	printBoard(board);
}



