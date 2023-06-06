#include "pch.h"
#include "LedPhoton.h"

extern HDC hdc;

LedPhoton::LedPhoton(int startX, int startY, int Sourse, int speed, COLORREF color) : Photon(startX, startY, Sourse, speed, color) {}

void LedPhoton::Show() {
	HPEN pen = CreatePen(PS_SOLID, 0.5, this->getColor());
	SelectObject(hdc, pen);
	if (getSourse() == 1 || getSourse() == 2) {
		if (this->getTrajectory() == 1) {
			MoveToEx(hdc, this->getX(), this->getY(), NULL);
			LineTo(hdc, this->getX() - 10, this->getY() - 8);
		}
		else if (this->getTrajectory() == 2) {
			MoveToEx(hdc, this->getX(), this->getY(), NULL);
			LineTo(hdc, this->getX() - 10, this->getY() + 8);
		}
		else {
			MoveToEx(hdc, this->getX(), this->getY(), NULL);
			LineTo(hdc, this->getX() - 10, this->getY());
		}
	}
	else {
		if (this->getTrajectory() == 1) {
			MoveToEx(hdc, this->getX(), this->getY(), NULL);
			LineTo(hdc, this->getX() + 10, this->getY() - 8);
		}
		else if (this->getTrajectory() == 2) {
			MoveToEx(hdc, this->getX(), this->getY(), NULL);
			LineTo(hdc, this->getX() + 10, this->getY() + 8);
		}
		else {
			MoveToEx(hdc, this->getX(), this->getY(), NULL);
			LineTo(hdc, this->getX() + 10, this->getY());
		}
	}
	DeleteObject(pen);
}

void LedPhoton::Hide() {
	COLORREF defColor = this->getColor();
	this->setColor(RGB(255, 255, 255));
	this->Show();
	this->setColor(defColor);
}

