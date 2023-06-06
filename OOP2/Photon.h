#pragma once
#include "Point.h"
class Photon :public Point{
private:
	int trajectory = 0;
	int speed;
	int sourse;
	bool used = false;
public:
	Photon(int, int, int, int speed = 3, COLORREF color = RGB(255, 255, 255));
	void Show();
	void Hide();
	void setTrajectory(int);
	int getTrajectory();
	void setSpeed(int);
	int getSpeed();
	int getSourse();
	void setSourse(int);
	bool isUsed();
};

