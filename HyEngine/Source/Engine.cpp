#include "StandardEngineFramework.h"
#include "Engine.h"

#include "TestScene.h"

Settings::Engine Engine::sEngineSettigns ;

IMPLEMENT_SINGLETON(Engine)

Engine::Engine()
	: 
	m_pMouse(new Utility::Mouse()),
	m_pKeyboard(new Utility::Keyboard()),
	m_pTimer(new Timer()),
	m_bLoading(false),
	m_bIsPaused(false)
{
	DirectXDevice::Create();
}
Engine::~Engine()
{
}

bool Engine::Initialize(HWND hWnd)
{
	m_bLoading = true;

	m_pTimer->start();


	// TODO : renderer initialize


	LoadShaders();

	// TODO : UI initilaize

	m_engineConfig.bShowBoundingBoxes = false;
	m_engineConfig.bShowProfiler = false;

	//Scene::BaseSceneParams baseSceneParams = Scene::BaseSceneParams();


	m_pScenes.push_back(new TestScene());


	//  TODO : select shader?

	// TODO : Log [ENGINE] : Initialized
	m_bLoading = false;
	return false;
}

void Engine::Exit()
{
}

bool Engine::Load()
{
	// TOOD  : LOG ENGINE Loading

	m_bLoading = true;

	// TODO
	// prepare loading screen resources
	// loading screen textures. 미리 로드
	// 여기서 로딩씬 텍스처 등 
	// 각종 리소스를 다운받는다.


	// TODO : RenderLoading Screen

	//if (!LoadSceneFromFile())
	//{
	//	// TODO Log::Error(Engine couldn't load scene.)
	//	// return false;
	//}
	LoadScene(0);

	// TODO 각종 렌더패스 초기화
	// 렌더링 미정으로 인한 보류


	m_bLoading = false;
	// TOOD : LOG Engine Loaded(async)


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
	RENDER_BEGIN
	PreRender();
	Render();
	RENDER_END
}

IScene * Engine::GetActiveScene()
{
	return m_pActiveScene;
}

bool Engine::LoadSceneFromFile()
{
	m_currentLevel = sEngineSettigns.levelToLoad;

	m_pActiveScene = m_pScenes[m_currentLevel];

	//m_pActiveScene->LoadScene()
	return false;
}

bool Engine::LoadScene(int level)
{
	m_pActiveScene = m_pScenes[level];
	// temp
	m_pActiveScene->LoadScene();
	return true;
}

bool Engine::LoadShaders()
{
	return false;
}

void Engine::PreRender()
{
	m_pActiveScene->PreRender();
}

void Engine::Render()
{
	m_pActiveScene->Render();
	m_pActiveScene->RenderSkybox(D3DXMATRIX());
	// TODO 
	/*m_pActiveScene->RenderOpaque();
	m_pActiveScene->RenderAlpha();*/
	m_pActiveScene->RenderLights();

}

void Engine::RenderUI()
{
	//m_pActiveScene->RenderUI();
}

void Engine::RenderDebug()
{
	m_pActiveScene->RenderDebug(D3DXMATRIX());
}
