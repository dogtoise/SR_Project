#pragma once




class ENGINE_DLL Engine
{
	friend class Application;

	DECLARE_SINGLETON(Engine)
private:
	Engine();
	~Engine();

public :
	bool Initialize(HWND hWnd);
	void Exit();

	bool Load();
	//void SimulateAndRenderFrame();
	void SimulateFrame();
	void RenderFrame();

	inline void Pause() { m_bIsPaused = true; }
	inline void Unpause() { m_bIsPaused = false; }

	inline Utility::Mouse* GetMouse() const { return m_pMouse; }
	inline Utility::Keyboard* GetKeyboard() const { return m_pKeyboard; }
	inline Timer* GetTimer() const { return m_pTimer; }

public :
	class IScene* GetActiveScene();
private :
	bool LoadSceneFromFile();
	bool LoadScene(int level);
	bool LoadShaders();

	void PreRender();
	void Render();
	void RenderUI();
	void RenderDebug();


	bool inline IsLoading() const { return m_bLoading; }


	// TOGGLES
	void inline TogglePause() { m_bIsPaused = !m_bIsPaused; }
private :
	// static 
	static Settings::Engine sEngineSettigns;

	// systems
	// TODO : INPUT
	// TODO : RENDERER
	Utility::Keyboard *m_pKeyboard;
	Utility::Mouse *m_pMouse;
	Timer *m_pTimer;
private :
	// scene



	// engine state
	bool m_bIsPaused;
	EngineConfig m_engineConfig;
	unsigned long long m_frameCount;

	// THREADED LOADING
	bool m_bLoading;
	// level is scene
	std::queue<int> m_levelLoadQueue;


private :
	//----------------------------------------------------------------------------------------------------------------
	// SCENE
	//----------------------------------------------------------------------------------------------------------------
	std::vector<Scene*> m_pScenes;
	Scene* m_pActiveScene;

	int m_currentLevel;

};
