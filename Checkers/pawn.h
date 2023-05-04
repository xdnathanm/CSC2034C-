#pragma once
#ifndef PAWN_H
#define PAWN_H


class pawn
{
	private:
		int x = 0;
		int y = 0;
		bool king = false;
		char tile = ' ';
	public:
		pawn(); // constructor
		~pawn();// destructor
		 // accessors
		int getx();
		int gety();
		char getTile();
		bool getKing();
		// mutators
		void setx(int x);
		void sety(int y);
		void setKing(bool king);
		void setTile(char tile);


};
#endif // !PAWN_H