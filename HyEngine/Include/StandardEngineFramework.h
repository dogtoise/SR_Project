#pragma once

// default

#include <Windows.h>
#include <stdlib.h>
#include <vector>
#include <list>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <string.h>
#include <assert.h>
#include <random>


/* DirectX9 */
#include <d3d9.h>
#pragma comment(lib, "d3d9.lib")

#include <d3dx9.h>
#pragma comment(lib, "d3dx9.lib")

#include <DirectXMath.h>

#undef min
#undef max


#ifdef EXPORTS_ENGINE
#define ENGINE_DLL _declspec(dllexport)
#else
#define ENGINE_DLL _declspec(dllimport)
#endif

#define SAFE_DELETE(p)  \
if(p)					\
{						\
delete p;				\
p = nullptr;			\
}
#define SAFE_RELEASE(p)  \
if(p)					\
{						\
p->Release();				\
p = nullptr;			\
}
#define SAFE_DELETE_ARRAY(p)\
if (p)\
{\
	delete[] p;\
	p = nullptr;\
}

#define WinMaxWidth 1280
#define WinMaxHeight 720
#define WinMinWidth 200
#define WinMinHeight 200




#include "Settings.h"
#include "DataStructures.h"

// Utilities
#include "Singleton.h"
#include "Log.h"
#include "ServiceLocator.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "MathUtils.h"
#include "LinearMath.h"
#include "UIDGen.h"


// Core
#include "Layer.h"
#include "Enumerators.h"
#include "Timer.h"
#include "DirectXDevice.h"
#include "Application.h"
#include "SceneView.h"
#include "Scene.h"
#include "Transform.h"
#include "Engine.h"

#define ENGINE Engine::Get()
#define KEYBOARD Engine::Get()->GetKeyboard()
#define MOUSE Engine::Get()->GetMouse()
#define TIMER Engine::Get()->GetTimer()






