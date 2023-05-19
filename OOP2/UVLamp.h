#pragma once
#include "Lamp.h"
class UVLamp :public Lamp{
private:
	int colorStand;
public:
	UVLamp(int, int, int, int, int colorStand = 0, COLORREF = RGB(0, 0, 0));
	void Show();
	void Hide();
};

