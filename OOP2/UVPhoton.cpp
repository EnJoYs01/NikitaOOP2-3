#include "pch.h"
#include "UVPhoton.h"

extern HDC hdc;

UVPhoton::UVPhoton(int startX, int startY, int endX, int endY, int speed, COLORREF color) : Photon(startX, startY, endX, endY, speed, color) {}

void UVPhoton::Show() {
	HPEN pen = CreatePen(PS_SOLID, 0.5, this->getColor());
	SelectObject(hdc, pen);
	if (this->getTrajectory() == 2) {
		MoveToEx(hdc, this->getX(), this->getY(), NULL);
		LineTo(hdc, this->getX() + 7, this->getY() + 10);
	}
	else if (this->getTrajectory() == 1) {
		MoveToEx(hdc, this->getX(), this->getY(), NULL);
		LineTo(hdc, this->getX(), this->getY() + 10);
	}
	else {
		MoveToEx(hdc, this->getX(), this->getY(), NULL);
		LineTo(hdc, this->getX(), this->getY() + 10);
	}
	DeleteObject(pen);
}

void UVPhoton::Hide() {
	COLORREF defColor = this->getColor();
	this->setColor(RGB(255, 255, 255));
	this->Show();
	this->setColor(defColor);
}
