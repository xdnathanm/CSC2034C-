#include "NotBlocks.h"



	NotBlocks :: NotBlocks()
	{
		 int x = 0; // array map {sb1x,sb1y,sb2x,sb2y,sb3x,sb3y,sb4x,sb4y}
		 int y = 0;
		 char block = '*';

	}
	NotBlocks :: ~NotBlocks()
	{
		
	}
	int NotBlocks::getX()
	{

		return x;
	}
	int NotBlocks::getY()
	{
		return y;
	}
	char NotBlocks::setLocation(int x, int y)
	{
		this->x = x;
		this->y = y;
		return this->blocks;
	}
	


	