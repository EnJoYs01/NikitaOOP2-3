#include "pch.h"
#include "SwitchableFlashlight.h"
#include "Flashlight.h"

extern HDC hdc;

SwitchableFlashlight::SwitchableFlashlight(int X, int Y, int Width, int TYPEOFLIGHT, COLORREF color) : Flashlight(X, Y, Width, TYPEOFLIGHT, color) {}

void SwitchableFlashlight::Show() {
	HPEN pen = CreatePen(PS_SOLID, 2, getColor());
	SelectObject(hdc, pen);
	Rectangle(hdc, getX(), getY(), getX() + 30, getY() + 15);
	Rectangle(hdc, getX() + 13, getY() - 5, getX() + 18, getY());
	MoveToEx(hdc, getX(), getY() + 15, NULL);
	LineTo(hdc, getX() - 7, getY() + GetWidth() / 2 + 15);
	LineTo(hdc, getX() - 7, getY() - GetWidth() / 2);
	LineTo(hdc, getX(), getY());
	DeleteObject(pen);
}

void SwitchableFlashlight::Hide() {
	COLORREF currentcolor = getColor();
	setColor(RGB(255, 255, 255));
	this->Show();
	setColor(currentcolor);
}