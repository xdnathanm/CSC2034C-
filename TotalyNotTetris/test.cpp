#include <iostream>
#include "NotBlocks.h"
void printBoard(char board[12][24]);// prints board

int main()
{
	int i = 0;
	int k = 0;
	char board[12][24];
	// makes board
	for (k = 0; k < 24; k++)
	{
		for ( i = 0; i < 12; i++)
		{
			if (i == 0 || i == 11)
			{
				board[i][k] = '|';
			}
			else
			{
				board[i][k] = ' ';
			}
			std::cout << board[i][k];

		}
		if (i == 12)
		{
			std::cout << std::endl;
		}
	}
	k = 0;
		for (i = 0; i < 12; i++)
		{
			board[i][k] = '^';
			std::cout << board[i][k];

		}
		if (i == 12)
		{
			std::cout << std::endl;
		}
	NotBlocks block1;
	NotBlocks block2;
	block1.setLocation(3, 2);
	int x = block1.getX();
	int y = block1.getY();
	
	int range = 0;
	board[block1.getX()][block1.getY()] = block1.setLocation(x, y);
	board[block1.getX()][block1.getY()] = block1.setLocation(x, y + 1);
	//printBoard(board);
	board[block1.getX()][block1.getY()] = block1.setLocation(x, y + 2);
	board[block1.getX()][block1.getY()] = block1.setLocation(x, y + 3);
	range = 4;
	printBoard(board);


	while (y < 24)
	{
		for (int i = 0; i < 4; i++)
		{
			board[block1.getX()][block1.getY()] = block1.setLocation(x, y);
			

			y++;

		}
		board[block1.getX()][block1.getY() - 5] = ' ';
		i = 0;
		
		
			


		
		printBoard(board);
		
	}
	std::cout << std::endl;
	return 0;
}
void printBoard(char board[12][24])
{
	int i = 0;
	for (int k = 0; k < 24; k++)
	{
		for (i = 0; i < 12; i++)
		{

			std::cout << board[i][k];

		}
		if (i == 12)
		{
			std::cout << std::endl;
		}
	}
}