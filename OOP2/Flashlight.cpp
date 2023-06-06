#include "pch.h"
#include "Flashlight.h"
#include "Point.h"

extern HDC hdc;

Flashlight::Flashlight(int X, int Y, int Width,int TYPEOFLIGHT, int Brightness, COLORREF color) : Point(X, Y, color) {
	this->SetWidth(Width);
	this->SetTypeOfLight(TYPEOFLIGHT);
	this->setBrightness(Brightness);
}

void Flashlight::Show() {
	HPEN pen = CreatePen(PS_SOLID, 2, getColor());
	SelectObject(hdc, pen);
	Rectangle(hdc, getX(), getY(), getX() + 30, getY() + 15);
	MoveToEx(hdc, getX(), getY() + 15, NULL);
	LineTo(hdc, getX() - 7, getY() + width / 2 + 15);
	LineTo(hdc, getX() - 7, getY() - width / 2);
	LineTo(hdc, getX(), getY());
	DeleteObject(pen);
}

void Flashlight::Hide() {
	COLORREF currentcolor = getColor();
	setColor(RGB(255, 255, 255));
	this->Show();
	setColor(currentcolor);
}

void Flashlight::SetTypeOfLight(int TYPEOFLIGHT) {
	this->TypeOfLight = TYPEOFLIGHT;
}

int Flashlight::GetTypeOfLight() {
	return this->TypeOfLight;
}

int Flashlight::GetWidth() {
	return this->width;
}

void Flashlight::SetWidth(int Width){
	this->width = Width;
}


void Flashlight::setBrightness(int Brightness) {
	this->brightness = Brightness;
}

int Flashlight::getBrightness() {
	if (this->brightness == 1) {
		return 25;
	}
	else if (this->brightness == 2) {
		return 40;
	}
	else {
		return 60;
	}
}