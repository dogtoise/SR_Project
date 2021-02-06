#include "StandardEngineFramework.h"
#include "Engine.h"

#include "TestScene.h"
#include "Renderer.h"

Settings::Engine Engine::sEngineSettigns ;

IMPLEMENT_SINGLETON(Engine)

// todo keyboard, mouse, timer
Engine::Engine()
	: 
	m_bLoading(false),
	m_bIsPaused(false)
{
	DirectXDevice::Create();
	UIDGen::Create();

	m_pRenderer = new Renderer();
	m_pMouse = new Utility::Mouse();
	m_pKeyboard = new Utility::Keyboard();
	m_pTimer = new Timer();
}
Engine::~Engine()
{
	delete m_pTimer;
	delete m_pKeyboard;
	delete m_pMouse;
	delete m_pRenderer;
	DirectXDevice::Destroy();
	UIDGen::Destroy();
}

bool Engine::Initialize(HWND hWnd, EngineConfig engineConfig)
{
	DirectXDevice::Get()->Init(hWnd);

	m_pTimer->start();

	this->engineConfig = engineConfig;
	m_scenes = engineConfig.scenes;




	return false;
}

void Engine::Exit()
{
	m_pActiveScene->UnloadScene();
	for (auto& scene : m_scenes)
	{
		delete scene;
	}
	
}

bool Engine::Load()
{
	m_bLoading = true;

	LoadShaders();
	LoadScenes();

	m_bLoading = false;
	return false;
}

void Engine::SimulateFrame()
{
	m_pKeyboard->Update();
	m_pMouse->Update();
	m_pActiveScene->UpdateScene();
}

void Engine::RenderFrame()
{
	RenderDebug();
	m_pActiveScene->RenderScene(m_pRenderer);
}

Scene * Engine::GetActiveScene()
{
	return m_pActiveScene;
}


bool Engine::LoadShaders()
{
	// TODO 
	return true;
}

void Engine::LoadScenes()
{
	m_currentLevel = engineConfig.defaultSceneIndex;
	m_pActiveScene = engineConfig.scenes[m_currentLevel];
	m_pActiveScene->LoadScene();
}


void Engine::RenderDebug()
{

}
