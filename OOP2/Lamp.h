#pragma once
#include "Point.h"
class Lamp : public Point{
private:
	int radius;
	int height;
public:
	Lamp(int, int, int, int, COLORREF = RGB(0, 0, 0));
	void Show();
	void Hide();
	int getRadius();
	int getHeight();
};

