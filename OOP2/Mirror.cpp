#include "pch.h"
#include "Mirror.h"

extern HDC hdc;

Mirror::Mirror(int X, int Y) : Point(X, Y) {}

void Mirror::Show() {
	MoveToEx(hdc, this->getX(), this->getY(), NULL);
	HPEN pen = CreatePen(PS_SOLID, 1, this->getColor());
	SelectObject(hdc, pen);
	Ellipse(hdc, this->getX(), this->getY(), this->getX() + 9, this->getY() + 20);
	DeleteObject(pen);
}

void Mirror::Hide() {
	COLORREF defColor = this->getColor();
	this->setColor(RGB(255, 255, 255));
	this->Show();
	this->setColor(defColor);
}

