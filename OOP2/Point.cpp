#include "pch.h"
#include "Point.h"

extern HDC hdc;

Point::Point(int X, int Y, COLORREF color) : Figure(X, Y){
	this->setColor(color);
}

void Point::setColor(COLORREF color) {
	this->color = color;
}

COLORREF Point::getColor() {
	return this->color;
}

void Point::Show() {
	SetPixel(hdc, this->getX(), this->getY(), this->getColor());
}

void Point::Hide() {
	COLORREF defColor = this->color;
	this->setColor(RGB(255, 255, 255));
	SetPixel(hdc, this->getX(), this->getY(), this->getColor());
	this->setColor(defColor);
}

void Point::MoveTo(int X, int Y) {
	this->Hide();
	this->setX(X);
	this->setY(Y);
	this->Show();
}