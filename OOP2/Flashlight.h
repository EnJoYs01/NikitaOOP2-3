#pragma once
#include "pch.h"
#include "Point.h"
class Flashlight :public Point {
private:
	int width;
	int TypeOfLight;
	int brightness;
public:
	Flashlight(int, int, int ,int TYPEOFLIGHT = 1, int Brightness = 2, COLORREF = RGB(0, 0, 0));
	void Show();
	void Hide();
	void SetTypeOfLight(int);
	int GetTypeOfLight();
	int GetWidth();
	void SetWidth(int);
	void setBrightness(int);
	int getBrightness();
};