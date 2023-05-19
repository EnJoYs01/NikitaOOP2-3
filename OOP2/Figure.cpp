#include "pch.h"
#include "Figure.h"

Figure::Figure(int X, int Y){
	this->setX(X);
	this->setY(Y);
}

void Figure::setX(int X) {
	this->x = X;
}

void Figure::setY(int Y) {
	this->y = Y;
}

int Figure::getX() {
	return this->x;
}

int Figure::getY() {
	return this->y;
}