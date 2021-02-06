#include "StandardEngineFramework.h"

#include <Windows.h>
#include <time.h>
//#include "TestScene.h"
#include "TestScene2.h"

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, PSTR pScmdl, int iCmdShow)
{
	srand(static_cast<unsigned>(time(NULL)));

	Application VQDemo(L"VQEngine Demo");

	EngineConfig engineConfig;

	//engineConfig.scenes.push_back(new TestScene2());
	//engineConfig.defaultSceneIndex = 0;

	if (VQDemo.Init(hInst, iCmdShow, engineConfig))
	{
		VQDemo.Run();
	}
	VQDemo.Exit();

	return 0;
}