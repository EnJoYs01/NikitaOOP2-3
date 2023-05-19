#pragma once
#include"Figure.h"
class Point : public Figure{
private:
	COLORREF color;
public:
	Point(int, int, COLORREF color = RGB(0, 0, 0));
	virtual void Hide();
	virtual void Show();
	void MoveTo(int, int);
	void setColor(COLORREF color);
	COLORREF getColor();
};

