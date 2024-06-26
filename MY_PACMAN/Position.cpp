#include "Position.h"
Position::Position(short x, short y) {
	this->x = x;
	this->y = y;
}

bool Position::operator == (Position other) {	
	return this->x == other.GetX() && this->y == other.GetY();
}


short Position::GetX() {
	return this->x;
}

short Position::GetY() {
	return this->y;
}

// return postion (x, y)
Position Position::GetPos() {
	Position MyPos(this->x, this->y);
	return MyPos;
}

// modify x
void Position::ModX(short NewX) {
	this->x = NewX;
}

// modify y
void Position::ModY(short NewY) {
	this->y = NewY;
}

void Position::ModCoords(short NewX, short NewY) {
	this->x = NewX;
	this->y = NewY;
}

void Position::ModPos(Position NewPos) {
	this->x = NewPos.GetX();
	this->y = NewPos.GetY();
}
