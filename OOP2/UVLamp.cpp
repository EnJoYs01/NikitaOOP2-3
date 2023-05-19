#include "pch.h"
#include "UVLamp.h"

extern HDC hdc;

UVLamp::UVLamp(int X, int Y, int Height, int Radius, int colorStand, COLORREF color) : Lamp(X, Y, Height, Radius, color) {
	this->colorStand = colorStand;
}

void UVLamp::Show() {
	MoveToEx(hdc, this->getX(), this->getY(), NULL);
	HPEN pen = CreatePen(PS_SOLID, 2, this->getColor());
	SelectObject(hdc, pen);
	LineTo(hdc, this->getX() - 15, this->getY() - this->getHeight());
	Ellipse(hdc, this->getX() - 15, this->getY() - this->getHeight() - 10, this->getX() - 15 - 40, this->getY() - this->getHeight() + 10);
	DeleteObject(pen);

	if (this->colorStand == 1) {
		this->setColor(RGB(255, 0, 0));
	}
	else if (this->colorStand == 2) {
		this->setColor(RGB(0, 255, 0));
	}
	else if (this->colorStand == 3) {
		this->setColor(RGB(0, 0, 255));
	}
	HRGN ellipse = CreateEllipticRgn(this->getX() - this->getRadius(), this->getY() - this->getRadius() / 2, 
		this->getX() + this->getRadius(), this->getY() + this->getRadius() / 2);
	HBRUSH brush = CreateSolidBrush(this->getColor());
	FillRgn(hdc, ellipse, brush);
	DeleteObject(brush);
}

void UVLamp::Hide() {
	COLORREF defColor = this->getColor();
	this->setColor(RGB(255, 255, 255));
	this->Show();
	this->setColor(defColor);
}