#include "StandardEngineFramework.h"
#include "..\Include\Application.h"



Application::Application(LPCWSTR appName)
	: 
	m_appName(appName),
	m_bAppWantsExit(false),
	//m_dt(1000 / (double)240),
	m_dt(1 / (double)60),
	m_maxSkipFrames(10)
{


	DirectXDevice::Create();
	// template 



}


Application::~Application()
{

}

bool Application::Init(HINSTANCE hInstance, int nCmdShow)
{
	m_hInstance = hInstance;

	// TODO : File로 읽어들이기
	//Settings::Engine settings;
	//settings.logger = Settings::Logger{ true, true };
	//settings.window = Settings::Window
	//{
	//	WinMaxWidth,
	//	WinMaxHeight,
	//	false,
	//	true
	//};
	//// todo : settings.sceneNames


	// LOG
	InitLoggingService();
	Engine::Create();	

	// TODO : ENGINE->Initialize
	// TODO : ENGINE->Load
	// WINDOW
	InitWindow();
	DirectXDevice::Get()->Init(m_hWnd);
	ShowWindow(m_hWnd, nCmdShow);
	ENGINE->Initialize(m_hWnd);

	ENGINE->Load();


	
	
	

	return true;
}

void Application::Run()
{
	TIMER->reset();
	double accumulatedTime = 0.0f;
	int nLoops = 0;

	MSG msg = {};

	while (!m_bAppWantsExit)
	{
		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		if (KEYBOARD->Up(VK_ESCAPE))
		{
			/*if (MOUSE->IsCaptured())
			{
				MOUSE->CaptureMouse(false);
			}*/
			//else/* if (!ENGINE->IsLoading())*/
			{
				m_bAppWantsExit = true;
			}

		}

		if (msg.message == WM_QUIT/* && !ENGINE->IsLoading()*/)
		{
			m_bAppWantsExit = true;
		}

		TIMER->tick();

		if (!ENGINE->m_bIsPaused)
		{
			// compute fps
			CalculateFrameStatistics();

			// accumulate the elapsed time since the last frame
			accumulatedTime += TIMER->getDeltaTime();
			
			// now update the game logic with fixed delta time as often as possible
			nLoops = 0;
			while (accumulatedTime >= m_dt && nLoops < m_maxSkipFrames)
			{
				ENGINE->SimulateFrame();

				accumulatedTime -= m_dt;
				nLoops++;
			}

			// peek into the future and generate the output
			ENGINE->RenderFrame();
		}
	}

}

void Application::Exit()
{
	ENGINE->Exit();
	ShutdownWindows();
}

LRESULT Application::MessageHandler(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam)
{
	const Settings::Window& settings = Engine::sEngineSettigns.window;

	switch (umsg)
	{
	case WM_CLOSE :
		// Log 
		m_bAppWantsExit = true;
		PostQuitMessage(0);
		break;
	case WM_SIZE:
		// TODO :LOG
		break;
	case WM_ACTIVATE :
		//if (LOWORD(wparam) == WA_INACTIVE)
		//{
		//	// TODO : LOG

		//	MOUSE->CaptureMouse(false);
		//	ENGINE->Pause();
		//	TIMER->stop();
		//}
		//else
		//{
		//	MOUSE->CaptureMouse(true);
		//	ENGINE->Unpause();
		//	TIMER->start();
		//}
		break;
	case WM_ENTERSIZEMOVE :
		ENGINE->Pause();
		// todo : resizing
		TIMER->stop();
		break;
	case WM_EXITSIZEMOVE:
		ENGINE->Unpause();
		// todo : resizing 
		TIMER->start();
		// TODO : ONRESIZE()
		break;
	case WM_GETMINMAXINFO :
		((MINMAXINFO*)lparam)->ptMinTrackSize.x = WinMinWidth;
		((MINMAXINFO*)lparam)->ptMinTrackSize.y = WinMinHeight;
		break;
	}
	return DefWindowProc(hwnd, umsg, wparam, lparam);
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT umessage, WPARAM wparam, LPARAM lparam)
{
	switch (umessage)
	{
	case WM_DESTROY:	// Check if the window is being destroyed.
		PostQuitMessage(0);
		return 0;
		
	case WM_QUIT:		// Check if the window is being closed.
		PostQuitMessage(0);
		return 0;
	default: // All other messages pass to the message handler in the system class.
		return g_pAppHandle->MessageHandler(hwnd, umessage, wparam, lparam);
	}
	//return DefWindowProc(hwnd, umessage, wparam, lparam);
}


void Application::UpdateWindowDimensions(int w, int h)
{
	m_windowHeight = h;
	m_windowWidth = w;
}

void Application::InitWindow()
{
	g_pAppHandle = this;

	WNDCLASSEX wndClass;

	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	wndClass.hIconSm = wndClass.hIcon;
	wndClass.hInstance = m_hInstance;
	wndClass.lpfnWndProc = (WNDPROC)WndProc;
	wndClass.lpszClassName = m_appName;
	wndClass.lpszMenuName = NULL;
	wndClass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wndClass.cbSize = sizeof(WNDCLASSEX);


	WORD wHr = RegisterClassEx(&wndClass);
	assert(wHr != 0);

	m_hWnd = CreateWindowEx
	(
		WS_EX_APPWINDOW,
		m_appName,
		m_appName,
		WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		(HMENU)NULL,
		m_hInstance,
		NULL
	);
	RECT rect = { 0, 0, (LONG)WinMaxWidth, (LONG)WinMaxHeight};

	UINT centerX = (GetSystemMetrics(SM_CXSCREEN) - (UINT)WinMaxWidth) / 2;
	UINT centerY = (GetSystemMetrics(SM_CYSCREEN) - (UINT)WinMaxHeight) / 2;

	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE);

	MoveWindow
	(
		m_hWnd,
		centerX, centerY,
		rect.right - rect.left, rect.bottom - rect.top,
		true
	);

	ShowWindow(m_hWnd, SW_SHOWNORMAL);//윈도우창을 보이게해주는것
	SetForegroundWindow(m_hWnd);//실행시켰을때 제일위로 올라오게하는것
	SetFocus(m_hWnd);//포커스 , 키보드나 마우스를 눌렀을때 조작이되는창.

	ShowCursor(true);

	//int width, height;
	//int posX, posY;				// window position
	//// global handle
	//g_pAppHandle = this;
	//
	//WNDCLASSEX wc = {};
	//wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	//wc.lpfnWndProc = WndProc;
	//wc.cbClsExtra = 0;
	//wc.cbWndExtra = 0;
	//wc.hInstance = m_hInstance;
	//wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	//wc.hIconSm = wc.hIcon;
	//wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	//wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	//wc.lpszMenuName = NULL;
	//wc.lpszClassName = m_appName;
	//wc.cbSize = sizeof(WNDCLASSEX);

	//WORD wHr = RegisterClassEx(&wc);
	//DWORD error =  GetLastError();
	//assert(wHr != 0);



	//// get client desktop resolution
	//width = GetSystemMetrics(SM_CXSCREEN);
	//height = GetSystemMetrics(SM_CYSCREEN);
	//// TEST
	//width = WinMaxWidth;
	//height = WinMaxHeight;



	//// set screen settings
	////if (windowSettings.fullScreen)
	//if(false)
	//{
	//	DEVMODE dmScreenSettings;
	//	memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));
	//	dmScreenSettings.dmSize = sizeof(dmScreenSettings);
	//	dmScreenSettings.dmPelsWidth = (unsigned long)width;
	//	dmScreenSettings.dmPelsHeight = (unsigned long)height;
	//	dmScreenSettings.dmBitsPerPel = 32;
	//	dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;
	//	ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN);

	//	posX = posY = 0;
	//}
	//else
	//{
	//	//width = std::min(windowSettings.width, width);
	//	//height = std::min(windowSettings.height, height);

	//	//if (width != windowSettings.width || height != windowSettings.height)
	//	//{
	//	//	/*Log::Warning("Resolution not supported (%dx%d): Fallback to (%dx%d)"
	//	//		, windowSettings.width, windowSettings.height
	//	//		, width, height
	//	//	);*/
	//	//	//TODO : LOG

	//	//	windowSettings.width = width;
	//	//	windowSettings.height = height;
	//	//}

	//	posX = (GetSystemMetrics(SM_CXSCREEN) - width) / 2;
	//	posY = (GetSystemMetrics(SM_CYSCREEN) - height) / 2;
	//}

	//// create window with screen settings

	///*m_hWnd = CreateWindowEx
	//(
	//	WS_EX_APPWINDOW,
	//	m_appName,
	//	m_appName,
	//	WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_OVERLAPPEDWINDOW,
	//	CW_USEDEFAULT,
	//	CW_USEDEFAULT,
	//	CW_USEDEFAULT,
	//	CW_USEDEFAULT,
	//	NULL,
	//	(HMENU)NULL,
	//	m_hInstance,
	//	NULL
	//);
	//DWORD error2 = GetLastError();*/
	//m_hWnd = CreateWindowEx(
	//	WS_EX_APPWINDOW,			// Forces a top-level window onto the taskbar when the window is visible.
	//	m_appName,					// class name
	//	m_appName,					// Window name
	//	WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_OVERLAPPEDWINDOW,					// Window style
	//	posX, posY, width, height,	// Window position and dimensions
	//	NULL, NULL,					// parent, menu
	//	m_hInstance, NULL
	//);
	//assert(m_hWnd != NULL);
	//DWORD dw = GetLastError();
}

void Application::ShutdownWindows()
{
	ShowCursor(true);

	if (Engine::sEngineSettigns.window.fullScreen)
	{
		ChangeDisplaySettings(NULL, 0);
	}

	// Remove the window.
	DestroyWindow(m_hWnd);
	m_hWnd = NULL;

	// Remove the application instance.
	UnregisterClass(m_appName, m_hInstance);
	m_hInstance = NULL;

	// Release the pointer to this class.
	g_pAppHandle = nullptr;

	return;
}

void Application::CalculateFrameStatistics()
{
	static int nFrames;				    // number of frames seen
	static double elapsedTime;		    // time since last call
	nFrames++;

	// compute average statistics over one second
	if ((TIMER->getTotalTime() - elapsedTime) >= 1.0)
	{
		// set fps and mspf
		m_fps = nFrames;
		m_mspf = 1000.0 / (double)m_fps;

		// reset
		nFrames = 0;
		elapsedTime += 1.0;
	}
}

void Application::InitLoggingService()
{
	// create file Logger
	std::shared_ptr<Utility::Logger<Utility::FileLogPolicy >> engineLogger
		(new Utility::Logger<Utility::FileLogPolicy>(L"engine.log"));

	// set name of current thread
	engineLogger->setThreadName("mainThread");

	// register the logging service
	Utility::ServiceLocator::provideFileLoggingService(engineLogger);


#ifdef _DEBUG
	// print starting message
	Utility::ServiceLocator::getFileLogger()->print<Utility::SeverityType::info>("The file logger was created successfully.");
#endif
}
