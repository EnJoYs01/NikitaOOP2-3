#include "pch.h"
#include "LedLamp.h"

extern HDC hdc;

LedLamp::LedLamp(int X, int Y, int Height, int Radius, bool lampshade, COLORREF color) : Lamp(X, Y, Height, Radius, color){
	this->lampshade = lampshade;
}

void LedLamp::Show() {
	MoveToEx(hdc, this->getX(), this->getY(), NULL);
	HPEN pen = CreatePen(PS_SOLID, 2, this->getColor());
	SelectObject(hdc, pen);
	LineTo(hdc, this->getX() + 15, this->getY() - this->getHeight());
	if (this->lampshade == true) {
		Ellipse(hdc, this->getX() + 15, this->getY() - this->getHeight() - 10, this->getX() + 15 + 40, this->getY() - this->getHeight() + 10);
		Ellipse(hdc, this->getX() + 20, this->getY() - this->getHeight() - 5, this->getX() + 20 + 30, this->getY() - this->getHeight() + 5);
	}
	else {
		Ellipse(hdc, this->getX() + 15, this->getY() - this->getHeight() - 10, this->getX() + 15 + 40, this->getY() - this->getHeight() + 10);
	}
	DeleteObject(pen);

	HRGN ellipse = CreateEllipticRgn(this->getX() - this->getRadius(), this->getY() - this->getRadius() / 2, 
		this->getX() + this->getRadius(), this->getY() + this->getRadius() / 2);
	HBRUSH brush = CreateSolidBrush(this->getColor());
	FillRgn(hdc, ellipse, brush);
	DeleteObject(brush);
}

void LedLamp::Hide() {
	COLORREF defColor = this->getColor();
	this->setColor(RGB(255, 255, 255));
	this->Show();
	this->setColor(defColor);
}
