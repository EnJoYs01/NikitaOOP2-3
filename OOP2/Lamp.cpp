#include "pch.h"
#include "Lamp.h"

extern HDC hdc;

Lamp::Lamp(int X, int Y, int Height, int Radius, COLORREF color) : Point(X, Y, color) {
	this->height = Height;
	this->radius = Radius;
}

void Lamp::Show() {
	MoveToEx(hdc, this->getX(), this->getY(), NULL);
	HPEN pen = CreatePen(PS_SOLID, 2, this->getColor());
	SelectObject(hdc, pen);
	LineTo(hdc, this->getX() + 15, this->getY() - this->height);
	Ellipse(hdc, this->getX() + 15, this->getY() - this->height - 10, this->getX() + 15 + 40, this->getY() - this->height + 10);
	DeleteObject(pen);

	HRGN ellipse = CreateEllipticRgn(this->getX() - this->getRadius(), this->getY() - this->getRadius() / 2, 
		this->getX() + this->getRadius(), this->getY() + this->getRadius() / 2);
	HBRUSH brush = CreateSolidBrush(this->getColor());
	FillRgn(hdc, ellipse, brush);
	DeleteObject(brush);
}

void Lamp::Hide() {
	COLORREF defColor = this->getColor();
	this->setColor(RGB(255, 255, 255));
	this->Show();
	this->setColor(defColor);
}

int Lamp::getRadius() {
	return this->radius;
}

int Lamp::getHeight() {
	return this->height;
}