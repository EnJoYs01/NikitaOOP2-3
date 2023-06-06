#include "pch.h"
#include "LedFlashlight.h"

extern HDC hdc;

LedFlashlight::LedFlashlight(int X, int Y, int Width, int Brightness, COLORREF color) : Flashlight(X, Y, Width, 2, Brightness, color) {}

void LedFlashlight::Show() {
	HPEN pen = CreatePen(PS_SOLID, 2, getColor());
	SelectObject(hdc, pen);
	Rectangle(hdc, getX(), getY(), getX() + 30, getY() + 15);
	MoveToEx(hdc, getX() + 29, getY() + 15, NULL);
	LineTo(hdc, getX() + 29 + 7, getY() + GetWidth() / 2 + 15);
	LineTo(hdc, getX() + 29 + 7, getY() - GetWidth() / 2);
	LineTo(hdc, getX() + 29, getY());
	DeleteObject(pen);
}

void LedFlashlight::Hide() {
	COLORREF currentcolor = getColor();
	setColor(RGB(255, 255, 255));
	this->Show();
	setColor(currentcolor);
}