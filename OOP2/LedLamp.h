#pragma once
#include "Lamp.h"
class LedLamp : public Lamp{
private:
	bool lampshade;
public:
	LedLamp(int, int, int, int, bool lampshade = true, COLORREF = RGB(0, 0, 0));
	void Show();
	void Hide();
};

