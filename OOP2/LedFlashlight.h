#pragma once
#include "pch.h"
#include "Flashlight.h"
class LedFlashlight :public Flashlight {
public:
	LedFlashlight(int, int, int, int Brightness, COLORREF = RGB(0, 0, 0));
	void Show();
	void Hide();
};
