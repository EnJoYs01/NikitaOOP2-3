#include"pch.h"
#include"Mirror.h"
#include"Prism.h"
#include"LedFlashlight.h"
#include"SwitchableFlashlight.h"
#include"LedPhoton.h"
#include"UVPhoton.h"

const int MAX_SWITCHABLE_PHOTONS = 60;

HDC hdc;
HWND hwnd{};
MSG msg{};

std::vector<Flashlight*> Flashlights;
std::vector<Photon*> Photons;

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_TIMER:
	{
		int maxLedPhotons = Flashlights[1]->getBrightness();
		for (int i = 0; i < MAX_SWITCHABLE_PHOTONS + maxLedPhotons; i++) {
			int switchableY = Flashlights[0]->getY() - Flashlights[0]->GetWidth() / 2 +
				rand() % ((Flashlights[0]->getY() + Flashlights[0]->GetWidth() / 2 + 15) - (Flashlights[0]->getY() - Flashlights[0]->GetWidth() / 2) + 1);
			int ledY = Flashlights[1]->getY() - Flashlights[1]->GetWidth() / 2 +
				rand() % ((Flashlights[1]->getY() + Flashlights[1]->GetWidth() / 2 + 15) - (Flashlights[1]->getY() - Flashlights[1]->GetWidth() / 2) + 1);

			if (Photons[i]->getSourse() == 1 || Photons[i]->getSourse() == 2) {
				if ((Photons[i]->getY() >= Flashlights[0]->getY() + 50 || Photons[i]->getX() <= Flashlights[0]->getX() - 70 
				|| Photons[i]->getY() <= Flashlights[0]->getY() - 100)) {
					Photons[i]->setTrajectory(0);
					Photons[i]->MoveTo(Flashlights[0]->getX() - 7, switchableY);
				}
				else if (Photons[i]->getX() >= Flashlights[0]->getX() - 6) {
					Photons[i]->setTrajectory(0);
					Photons[i]->MoveTo(Flashlights[0]->getX() - 7, switchableY);
				}
				else if (Photons[i]->getX() <= Flashlights[0]->getX() - 40 && Photons[i]->getY() >= Flashlights[0]->getY() - 15 
				&& Photons[i]->getY() <= Flashlights[0]->getY() && !Photons[i]->isUsed()) {
					int value = rand() % 2;
					if (value == 0) {
						Photons[i]->setTrajectory(1);
					}
					else {
						Photons[i]->setTrajectory(2);
					}
				}
				else if (Photons[i]->getX() <=Flashlights[0]->getX() - 44 && Photons[i]->getX() >= Flashlights[0]->getX() - 47 
				&& Photons[i]->getY() >= Flashlights[0]->getY() + 10 && Photons[i]->getY() <= Flashlights[0]->getY() + 30) {
					Photons[i]->setTrajectory(3);
				}			
			}
			else {
				if ((Photons[i]->getY() >= Flashlights[1]->getY() + 100 || Photons[i]->getX() >= Flashlights[1]->getX() + 30 + 7 + 70 
				|| Photons[i]->getY() <= Flashlights[1]->getY() - 50)) {
					Photons[i]->setTrajectory(0);
					Photons[i]->MoveTo(Flashlights[1]->getX() + 30 + 7, ledY);
				}
				else if (Photons[i]->getX() <= Flashlights[1]->getX() + 30 + 6) {
					Photons[i]->setTrajectory(0);
					Photons[i]->MoveTo(Flashlights[1]->getX() + 30 + 7, ledY);
				}
				else if (Photons[i]->getX() >= Flashlights[0]->getX() - 60 && Photons[i]->getY() >= Flashlights[0]->getY() - 15
				&& Photons[i]->getY() <= Flashlights[0]->getY() && !Photons[i]->isUsed()) {
					int value = rand() % 2;
					if (value == 0) {
						Photons[i]->setTrajectory(1);
					}
					else {
						Photons[i]->setTrajectory(2);
					}
				}
				else if (Photons[i]->getX() >= Flashlights[0]->getX() - 53 && Photons[i]->getX() <= Flashlights[0]->getX() - 50 
				&& Photons[i]->getY() >= Flashlights[0]->getY() + 10 && Photons[i]->getY() <= Flashlights[0]->getY() + 30) {
					Photons[i]->setTrajectory(3);
				}
			}
		}
		InvalidateRect(hwnd, NULL, TRUE);
		break;
	}
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		hdc = BeginPaint(hwnd, &ps);

		Mirror myMirror(Flashlights[0]->getX() - 53, Flashlights[0]->getY() + 10);
		myMirror.Show();

		Prism myPrism(Flashlights[0]->getX() - 60, Flashlights[0]->getY() - 15);
		myPrism.Show();

		for (int i = 0; i < Flashlights.size(); i++) {
			Flashlights[i]->Show();
		}

		int maxLedPhotons = Flashlights[1]->getBrightness();
			for (int i = 0; i < MAX_SWITCHABLE_PHOTONS + maxLedPhotons; i++) {
				if (Photons[i]->getSourse() == 1 || Photons[i]->getSourse() == 2) {			
					if (Photons[i]->getTrajectory() == 1) {
						Photons[i]->MoveTo(Photons[i]->getX() - Photons[i]->getSpeed(), Photons[i]->getY() - Photons[i]->getSpeed());
					}
					else if (Photons[i]->getTrajectory() == 2) {
						Photons[i]->MoveTo(Photons[i]->getX() - Photons[i]->getSpeed(), Photons[i]->getY() + Photons[i]->getSpeed());
					}
					else if (Photons[i]->getTrajectory() == 3) {
						Photons[i]->MoveTo(Photons[i]->getX() + Photons[i]->getSpeed(), Photons[i]->getY());
					}
					else{
						Photons[i]->MoveTo(Photons[i]->getX() - Photons[i]->getSpeed(), Photons[i]->getY());
					}
				}
				else {
					if (Photons[i]->getTrajectory() == 1) {
						Photons[i]->MoveTo(Photons[i]->getX() + Photons[i]->getSpeed(), Photons[i]->getY() - Photons[i]->getSpeed());
					}
					else if (Photons[i]->getTrajectory() == 2) {
						Photons[i]->MoveTo(Photons[i]->getX() + Photons[i]->getSpeed(), Photons[i]->getY() + Photons[i]->getSpeed());
					}
					else if (Photons[i]->getTrajectory() == 3) {
						Photons[i]->MoveTo(Photons[i]->getX() - Photons[i]->getSpeed(), Photons[i]->getY());
					}
					else {
						Photons[i]->MoveTo(Photons[i]->getX() + Photons[i]->getSpeed(), Photons[i]->getY());
					}
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

	Flashlights.push_back(new SwitchableFlashlight(300, 100, 20, 1));
	Flashlights.push_back(new LedFlashlight(Flashlights[0]->getX() - 135, 100, 20, 1));

	int maxLedPhotons = Flashlights[1]->getBrightness();

	int y = 0;
	if (Flashlights[0]->GetTypeOfLight() == 1) {
		for (int i = 0; i < MAX_SWITCHABLE_PHOTONS; i++) {
			y = Flashlights[0]->getY() - Flashlights[0]->GetWidth() / 2 +
				rand() % ((Flashlights[0]->getY() + Flashlights[0]->GetWidth() / 2 + 15) - (Flashlights[0]->getY() - Flashlights[0]->GetWidth() / 2) + 1);
			Photons.push_back(new UVPhoton(Flashlights[0]->getX() - 7, y, 1, rand() % 3 + 1));
		}
	}
	else
	{
		for (int i = 0; i < MAX_SWITCHABLE_PHOTONS; i++) {
			y = Flashlights[0]->getY() - Flashlights[0]->GetWidth() / 2 +
				rand() % ((Flashlights[0]->getY() + Flashlights[0]->GetWidth() / 2 + 15) - (Flashlights[0]->getY() - Flashlights[0]->GetWidth() / 2) + 1);
			Photons.push_back(new LedPhoton(Flashlights[0]->getX() - 7, y, 2, rand() % 3 + 1));
		}
	}

	for (int i = MAX_SWITCHABLE_PHOTONS; i < MAX_SWITCHABLE_PHOTONS + maxLedPhotons; i++) {
		y = Flashlights[1]->getY() - Flashlights[1]->GetWidth() / 2 +
			rand() % ((Flashlights[1]->getY() + Flashlights[1]->GetWidth() / 2 + 15) - (Flashlights[1]->getY() - Flashlights[1]->GetWidth() / 2) + 1);		
		Photons.push_back(new LedPhoton(Flashlights[1]->getX() + 30 + 7, y, 0, rand() % 3 + 1));
	}

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
