#pragma once
#ifndef POSITION_H
#define POSITION_H


class Position {
public:
	Position(short x = 0, short y = 0);
	short GetX();
	short GetY();
	Position GetPos();
	void ModX(short NewX); 
	void ModY(short NewY);
	void ModCoords(short NewX, short NewY); // modify coordinate
	void ModPos(Position NewPos);
	bool operator == (Position other);
private:
	short x, y;
};


#endif POSITION_H