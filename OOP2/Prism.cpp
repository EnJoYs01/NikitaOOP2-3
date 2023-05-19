#include "pch.h"
#include "Prism.h"

extern HDC hdc;

Prism::Prism(int X1, int Y1, COLORREF color) : Point(X1, Y1, color) {}

void Prism::Show() {
	HPEN pen = CreatePen(PS_SOLID, 1, this->getColor());
	SelectObject(hdc, pen);

	MoveToEx(hdc, this->getX(), this->getY(), NULL);
	LineTo(hdc, this->getX() + 10, this->getY() + 15);
	MoveToEx(hdc, this->getX() + 10, this->getY() + 15, NULL);
	LineTo(hdc, this->getX() + 20, this->getY());
	MoveToEx(hdc, this->getX() + 20, this->getY(), NULL);
	LineTo(hdc, this->getX(), this->getY());

	DeleteObject(pen);
}

void Prism::Hide() {
	COLORREF defColor = this->getColor();
	this->setColor(RGB(255, 255, 255));
	this->Show();
	this->setColor(defColor);
}