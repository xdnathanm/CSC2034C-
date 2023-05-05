#include <iostream>
#include "pawn.h"
#include "player.h"
pawn board[8][8];
void printBoard(pawn board[8][8]);
pawn* fillBoard(pawn board[8][8]);
void move(player player, pawn board [ 8] [ 8]);
bool moveCheckF(int, int, int, int, player player);

int main()
{
	player player1; player1.setPNumber(1);
	player player2; player2.setPNumber(2);
	int winner = 0;
	fillBoard(board);
	
	printBoard(board);
	while (!player1.getWin() || !player2.getWin() )
	{
		move(player1, board);
		move(player2, board);
		if (player1.getPScore() == 12)
		{
			player1.setWin(true);
			winner = player1.getPNumber();
		}
		else if(player2.getPScore() == 12)
		{
			player2.setWin(true);
			winner = player2.getPNumber();
		}
	}
	std::cout << "Player " << winner << "is the winner. "<< std::endl
		<< "player 1 score: " << player1.getPScore() << "  player 2 score: " << player2.getPScore();
	std::cout << std::endl;
	return 0;
}
pawn* fillBoard(pawn board [8] [8])
{
	for (int i = 0; i < 8; i++)
	{
		for (int k = 0; k < 8; k++)

		{
			


			if (i == 0 && k%2 != 0)
			{
				pawn pawn;
				pawn.setx(k);
				pawn.sety(i);
				pawn.setTile('*');
				board[i][k].setTile(pawn.getTile());
			}
			else if(i==1 && k%2 ==0)
			{
				pawn pawn;
				pawn.setx(k);
				pawn.sety(i);
				pawn.setTile('*');
				board[i][k].setTile(pawn.getTile());

			}
			else if (i == 2 && k % 2 != 0)
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
bool moveCheckF(int xI, int yI, int xF,int yF,player player) // checks if the move is legal or if the piece selected can be moved legally
{
	int cCount = 0;
	if (board[yI][xI].getTile() != '*' && player.getPNumber() == 1)  // checks if player 1 is actually selecting their tile
		return true;
	if (board[yI][xI].getTile() != '^' && player.getPNumber() == 2)  // checks if player 2 is actually selecting their tile
		return true;
	
	if (abs(yI - yF) > 2 && yF!= -1) // checks if they are making a valid move IE moving more than 2 tiles at a time 
		return true;
	
	if (abs(xI - xF) > 2 && xF!= -1)// checks if they are moving more than two tiles on the x-axis
		return true;
	
	if (xI == xF)
		return true;

	if (yI == yF)
		return true;
	for (int i = 0; i < 8; i++)
	{
		
		if (board[yI+1][i].getTile() == '*' && player.getPNumber()==1)
		{
			cCount++;
		}
		if (board[yI - 1][i].getTile() == '^' && player.getPNumber() == 2)
		{
			cCount++;
		}
	}
	if (!board[yI][xI].getKing() && player.getPNumber() == 1 ) // checks if the piece is a not a king and trying to move back for p1 and p2.
	{
		if (yI > yF && yF > -1)
		{
			return true;
		}
	}
	if (!board[yI][xI].getKing()&& player.getPNumber() == 2)
	{
		if (yF > yI && yF > -1)
		{
			return true;
		}
	}

	if (cCount == 4 && (yI < 2 || yI >5))
		return true;

	return false;
}

void move(player player, pawn board[8][8])
{	// x y coordinates of a tile a player wishes to move
	int pXTChoice = 0;
	int pYTChoice = 0;
	// x y coordinates of a open square where a player wishes to move their selected tile. 
	int pXDChoice = -1;
	int pYDChoice = -1;
	int captureDif = 0;
	std::cout << "Player" << player.getPNumber() <<" Pick an x coordinate and then a y coordinate to select which tile to move";
	std::cin >> pXTChoice; std::cin >> pYTChoice;
	pXTChoice = pXTChoice - 1; pYTChoice = pYTChoice - 1; // adjusts the input to work with the array,
	if (player.getPNumber() == 1)
	{
		while (moveCheckF(pXTChoice,pYTChoice,pXDChoice,pYDChoice,player))
		{
			std::cout << " please select a valid choice for player1 a ( * ) tile" << std::endl;
			std::cin >> pXTChoice; std::cin >> pYTChoice;
			pXTChoice = pXTChoice - 1; pYTChoice = pYTChoice - 1;

		}
		printf("\n%s\n", "Select a x and y destination for your tile. ");
		std::cin >> pXDChoice; std::cin >> pYDChoice;
		pXDChoice = pXDChoice - 1; pYDChoice = pYDChoice - 1;
		while (moveCheckF(pXTChoice, pYTChoice, pXDChoice, pYDChoice, player))
		{
			std::cout << "Please pick a valid destination" << std::endl;
			std::cin >> pXDChoice; std::cin >> pYDChoice;
			pXDChoice = pXDChoice - 1; pYDChoice = pYDChoice - 1;

		}
		board[pYDChoice][pXDChoice].setTile('*');
		board[pYTChoice][pXTChoice].setTile(' ');
		captureDif = pYDChoice - pYTChoice;
		if (abs(captureDif) == 2)
		{
			if (board[pYDChoice - 1][pXDChoice - 1].getTile() == '^')
			{
				board[pYDChoice - 1][pXDChoice - 1].setTile(' ');
				player.setPScore(1);
			}
			else if (board[pYDChoice - 1][pXDChoice + 1].getTile() == '^')
			{
				board[pYDChoice - 1][pXDChoice + 1].setTile(' ');
			}
			std::cout << std::endl << "Player" << player.getPNumber() << " captured a piece" << std::endl;

		}
	}else if(player.getPNumber() == 2)
	{
		while (moveCheckF(pXTChoice, pYTChoice, pXDChoice, pYDChoice,player))
		{
			std::cout << " please select a valid choice for player2  a ( ^ ) tile" << std::endl;
			std::cin >> pXTChoice; std::cin >> pYTChoice;
			pXTChoice = pXTChoice - 1; pYTChoice = pYTChoice - 1;
		}
		printf("\n%s\n", "Select a x and y destination for your tile. ");
		std::cin >> pXDChoice; std:: cin >> pYDChoice;
		pXDChoice = pXDChoice - 1; pYDChoice = pYDChoice - 1;
		while (moveCheckF(pXTChoice, pYTChoice, pXDChoice, pYDChoice,player))
		{
			std::cout << "Please pick a valid destination" << std::endl;
			std::cin >> pXDChoice; std::cin >> pYDChoice;
			pXDChoice = pXDChoice - 1; pYDChoice = pYDChoice - 1;

		}
		board[pYDChoice][pXDChoice].setTile('^');
		board[pYTChoice][pXTChoice].setTile(' ');
		captureDif = pYDChoice - pYTChoice;

		if (abs(captureDif) == 2)
		{
			if (board[pYDChoice + 1][pXDChoice + 1].getTile() == '*')
			 
			{
				board[pYDChoice + 1][pXDChoice + 1].setTile(' ');
				player.setPScore(1);
			}
			else if (board[pYDChoice + 1][pXDChoice - 1].getTile() == '*')
			{
				board[pYDChoice + 1][pXDChoice - 1].setTile(' ');
			}
			std::cout << std::endl<< "Player" << player.getPNumber() << " captured a piece" << std::endl;

		}
	}
	printBoard(board);
}