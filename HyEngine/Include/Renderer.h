#pragma once




class ENGINE_DLL Renderer
{
public:
	Renderer();
	~Renderer();

	//----------------------------------------------------------------------------------------------------------------
	// CORE INTERFACE
	//----------------------------------------------------------------------------------------------------------------
	//bool Init(HWND hWnd, const Settings::Window& windowSettings, const Settings::Rendering& rendererSettings);
	//void Exit();


	/*bool InsertGameObject(class GameObject* go);
	void RemoveGameObjecgt(class GameObejct* go);*/

	void Render(class IRenderable * renderable);
	void RenderList(std::vector<class IRenderable* > renderables);

	void RenderBegin();
	void RenderEnd();

	// default setter 
	void SetOpaqueContext();


	void SetAlphaContext();


	void BeginRenderEvent(std::wstring message);
	void EndRenderEvent(std::wstring message);



	//----------------------------------------------------------------------------------------------------------------
	// GETTERS
	//----------------------------------------------------------------------------------------------------------------




	//----------------------------------------------------------------------------------------------------------------
	// DATA
	//----------------------------------------------------------------------------------------------------------------
	//bool m_bEnableBlend;

private :
//	std::unordered_map<ERenderType, class GameObject* > m_RenderObjects;

	//std::vector<class GameObject*> m_RenderOpaque;
	//std::vector<class GameObject*> m_RenderAlpha;
};

