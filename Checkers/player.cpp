#include "player.h"

player::player()
{

	int pNumber = 0;
	int pScore = 0;
	bool winner = false;

}

player:: ~player(){}

// accessors
int player::getPNumber()
{
	return pNumber;
}
int player::getPScore()
{
	return pScore;
}
bool player::getWin()
{
	return winner;
}

// mutators
void player::setPNumber(int pNumber)
{
	this->pNumber = pNumber;
}
void player::setPScore(int pScore)
{
	this->pScore = pScore;
}
void player::setWin(bool winner)
{
	this->winner = winner;
}