#include "StandardEngineFramework.h"

#include <Windows.h>
#include <time.h>

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, PSTR pScmdl, int iCmdShow)
{
	srand(static_cast<unsigned>(time(NULL)));

	Application VQDemo(L"VQEngine Demo");
	/*VQDemo.Init(hInst, iCmdShow);
	HWND hwnd = FindWindow(0, "VQEngine Demo");

	ShowWindow(hwnd, iCmdShow);*/
	if (VQDemo.Init(hInst, iCmdShow))
	{
		VQDemo.Run();
	}
	VQDemo.Exit();

	return 0;
}