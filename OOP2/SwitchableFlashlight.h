#pragma once
#include "pch.h"
#include "Flashlight.h"
class SwitchableFlashlight :public Flashlight {
public:
	SwitchableFlashlight(int, int, int, int, COLORREF = RGB(0, 0, 0));
	void Show();
	void Hide();
};