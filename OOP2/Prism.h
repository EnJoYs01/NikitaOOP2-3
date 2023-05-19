#pragma once
#include "Point.h"
class Prism :public Point{
public:
	Prism(int, int, COLORREF color = RGB(255, 0, 0));
	void Show();
	void Hide();
};

