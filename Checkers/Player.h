#pragma once
#ifndef PLAYER_h
#define PLAYER_H



class player
{
	private:
		int pNumber = 0;
		int pScore = 0;
		bool winner = false;

	public:
		player();
		~player();
		//accessors
		int getPNumber();
		int getPScore();
		bool getWin();
		// mutators
		void setPNumber(int pNumber);
		void setPScore(int pScore);
		void setWin(bool winner);
}; 
#endif // PLAYER_h