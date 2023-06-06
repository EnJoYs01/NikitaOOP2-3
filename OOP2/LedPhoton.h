#pragma once
#include "Photon.h"
class LedPhoton :public Photon{
public:
	LedPhoton(int, int, int, int speed = 3, COLORREF color = RGB(244, 169, 0));
	void Show();
	void Hide();
};

