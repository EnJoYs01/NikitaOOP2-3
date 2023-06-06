#pragma once
#include "Photon.h"
class UVPhoton : public Photon{
public:
	UVPhoton(int, int, int, int speed = 3, COLORREF color = RGB(62, 6, 148));
	void Show();
	void Hide();
};

