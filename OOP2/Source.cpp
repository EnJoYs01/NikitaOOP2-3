#include"pch.h"
#include"Mirror.h"
#include"Prism.h"
#include"LedLamp.h"
#include"UVLamp.h"
#include"LedPhoton.h"
#include"UVPhoton.h"

const int MAX_PHOTONS = 70;

HDC hdc;

std::vector<Lamp*> Lamps;
std::vector<Photon*> Photons;

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_TIMER:
	{
		for (int i = 0; i < MAX_PHOTONS; i++) {
			int x1 = 115 + rand() % (155 - 115 + 1);
			int x2 = Lamps[1]->getX() - 55 + rand() % ((Lamps[1]->getX() - 15) - (Lamps[1]->getX() - 55) + 1);
			if ((Photons[i]->getY() >= 105 || Photons[i]->getX() >= 200) && Photons[i]->getColor() == RGB(244, 169, 0)) {
				Photons[i]->setTrajectory(0);
				Photons[i]->MoveTo(x1, 30);
			}
			else if (Photons[i]->getY() <= 20 && Photons[i]->getColor() == RGB(244, 169, 0)) {
				Photons[i]->setTrajectory(0);
				Photons[i]->MoveTo(x1, 30);
			} else if ((Photons[i]->getY() >= 105 || Photons[i]->getX() >= 1000) && Photons[i]->getColor() == RGB(62, 6, 148)) {
				Photons[i]->setTrajectory(0);
				Photons[i]->MoveTo(x2, 30);
			}
			else if (Photons[i]->getY() <= 20 && Photons[i]->getColor() == RGB(62, 6, 148)) {
				Photons[i]->setTrajectory(0);
				Photons[i]->MoveTo(x2, 30);
			}
			else if (Photons[i]->getX() >= 120 && Photons[i]->getX() <= 140 && Photons[i]->getY() >= 70) {
				Photons[i]->setTrajectory(1);
			}else if (Photons[i]->getX() >= 145 && Photons[i]->getX() <= 165 && Photons[i]->getY() >= 60) {
				Photons[i]->setTrajectory(2);
			}
		}
		InvalidateRect(hwnd, NULL, TRUE);
		break;
	}
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		hdc = BeginPaint(hwnd, &ps);		

		Mirror myMirror(120, 70);
		myMirror.Show();

		Prism myPrism(145, 60);
		myPrism.Show();

		for (int i = 0; i < Lamps.size(); i++) {
			Lamps[i]->Show();
		}

		for (int i = 0; i < MAX_PHOTONS; i++) {
			if (Photons[i]->getTrajectory() == 1) {
				Photons[i]->MoveTo(Photons[i]->getX(), Photons[i]->getY() - Photons[i]->getSpeed());
			}
			else if (Photons[i]->getTrajectory() == 2) {
				Photons[i]->MoveTo(Photons[i]->getX() + 5, Photons[i]->getY() + 2);
			}
			else {
				Photons[i]->MoveTo(Photons[i]->getX(), Photons[i]->getY() + Photons[i]->getSpeed());
			}
		}

		EndPaint(hwnd, &ps);
		break;
	}
	case WM_CREATE:
	{
		SetTimer(hwnd, 1, 100, NULL);
		break;
	}
	case WM_DESTROY:
	{
		PostQuitMessage(EXIT_SUCCESS);
		break;
	}
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR czCmdLine, int nCmdShow)
{
	srand(time(NULL));
	
	Lamps.push_back(new LedLamp(100, 100, 70, 30));
	Lamps.push_back(new UVLamp(Lamps[0]->getX() + 115, 100, 70 , 30)/*(215, 100, 70, 30)*/);

	int x = 0;
	for (int i = 0; i < MAX_PHOTONS/2; i++) {
		x = Lamps[0]->getX() + 15 + rand() % (Lamps[0]->getX() + 55 - (Lamps[0]->getX() + 15) + 1);
		Photons.push_back(new LedPhoton(x, 30, x, 30 + 20, rand() % 5 + 1));
	}

	for (int i = MAX_PHOTONS / 2;  i < MAX_PHOTONS; i++) {
		int x12 = Lamps[1]->getX() - 55 + rand() % ((Lamps[1]->getX() - 15) - (Lamps[1]->getX() - 55) + 1);
		Photons.push_back(new UVPhoton(x12, 30, x12, 30 + 20, rand() % 5 + 1, RGB(62, 6, 148)));
	}

	HWND hwnd{};
	MSG msg{};

	WNDCLASSEX wc{ sizeof(WNDCLASSEX) };
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = reinterpret_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));
	wc.hCursor = LoadCursor(nullptr, IDI_APPLICATION);
	wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
	wc.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);
	wc.hInstance = hInstance;
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = L"MyAppClass ";
	wc.lpszMenuName = nullptr;
	wc.style = CS_VREDRAW | CS_HREDRAW;

	if (!RegisterClassEx(&wc))
	{
		return EXIT_FAILURE;
	}

	hwnd = CreateWindow(wc.lpszClassName, L"Player", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 0, 0, 600, 400, NULL, NULL, NULL, NULL);
	if (hwnd == INVALID_HANDLE_VALUE)
	{
		return EXIT_FAILURE;
	}

	while (GetMessage(&msg, NULL, NULL, NULL))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return static_cast<int>(msg.wParam);
}
