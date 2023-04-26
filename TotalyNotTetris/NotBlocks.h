#pragma once

class NotBlocks
{
private:
	
	//const int N = 4;
	int x;
	int y;
	char blocks = '*';
public:
	// constructor
	NotBlocks();
	// destructor
	~NotBlocks();

	//accessors
	int getX();
	int getY();
	// mutators. 
	char setLocation(int x, int y);
};