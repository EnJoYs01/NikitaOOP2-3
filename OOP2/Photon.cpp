#include "pch.h"
#include "Photon.h"

extern HDC hdc;

Photon::Photon(int startX, int startY, int Sourse, int speed, COLORREF color) : Point(startX, startY, color) {
	this->setSpeed(speed);
	this->setSourse(Sourse);
}

void Photon::Show() {
	HPEN pen = CreatePen(PS_SOLID, 0.5, this->getColor());
	SelectObject(hdc, pen);
	if (this->getTrajectory() == 2) {
		MoveToEx(hdc, this->getX(), this->getY(), NULL);
		LineTo(hdc, this->getX() + 7, this->getY() + 10);
	}
	else {
		MoveToEx(hdc, this->getX(), this->getY(), NULL);
		LineTo(hdc, this->getX() - 10, this->getY());
	}
	DeleteObject(pen);
}

void Photon::Hide() {
	COLORREF defColor = this->getColor();
	this->setColor(RGB(255, 255, 255));
	this->Show();
	this->setColor(defColor);
}

void Photon::setTrajectory(int value) {
	if (value == 0) {
		this->trajectory = value;
		this->used = false;
	}
	else {
		this->trajectory = value;
		this->used = true;
	}
}

int Photon::getTrajectory() {
	return this->trajectory;
}

void Photon::setSpeed(int speed) {
	this->speed = speed;
}

int Photon::getSpeed() {
	return this->speed;
}

int Photon::getSourse() {
	return this->sourse;
}

void Photon::setSourse(int Sourse) {
	this->sourse = Sourse;
}

bool Photon::isUsed() {
	return this->used;
}