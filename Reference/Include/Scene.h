#pragma once
#include "IScene.h"
#include "GameObject.h"
class GameObject;

class Scene : public IScene
{
protected :
	// Inherited via IScene
	virtual void Update()  =0;
	virtual void Load() =0;
	virtual void Unload() =0;
	virtual void RenderUI() const =0;

	// TODO 
	// GameObject* CreateNewGameObject();

	// Updates the scene's bounding box boundaries. This has to be called after 
	// a new game object added to a scene (or after getting done adding multiple
	// game objects as this needs to be called only once).
	void CalculateSceneBoundingBox();

	// TODO
	// void AddLoght(const Light& light);

	// TODO 
	// Model LoadModel(const std::string& modelPath);


public :
	//struct BaseSceneParams
	//{
	//	// Renderer* pRenderer;

	//};
	//Scene(const BaseSceneParams& params);
	//~Scene() = default;
	Scene();
	~Scene() = default;

	// Moves objects from serializedScene into objects vector and sets the scene pointer in objects
	//void LoadScene(SerializedScene& scene, const Settings::Window& windowSettings);
	void LoadScene();

	// Clears object/light containers and camera settings
	void UnloadScene();

	// Updates selected camera and calls overridden Update from derived scene class
	void UpdateScene();

	// TODO 
	// Prepares the scene and shadow views for culling, sorting, instanced draw lists, lights, etc.
	void PreRender();



	void Render();

	// TODO 
	void RenderOpaque();
	void RenderAlpha();
	void RenderLights() const;
	void RenderSkybox(const D3DXMATRIX& viewProj) const;

	// Renders debugging information such as bounding boxes, wireframe meshes, etc.
	int RenderDebug(const D3DXMATRIX& viewProj) const;
	

	// Gatters
	// TODO 
	// GetCamera 등등




protected : 

	//template <typename T>
	//void AddGameObject()
	//{
	//	//shared_ptr<T> obj = Object::Create<T>();
	//	T* obj = Object::CreateClone()
	//	m_pObjects.push_back(obj);
	//}

	//void AddGameObject(const std::wstring prototypeName)
	//{
	//	Object*  clone = Object::CreateClone(prototypeName);
	//	m_pObjects.push_back((GameObject*)clone);
	//}
	void AddGameObject(GameObject* obj)
	{

		m_pObjects.push_back(obj);
	}



	//----------------------------------------------------------------------------------------------------------------
	// SCENE DATA
	//----------------------------------------------------------------------------------------------------------------
	// TODO : friend class SceneResourceView;

	//---------------------------------------------
	// SCENE RESOURCE CONTAINERS
	//---------------------------------------
	// TODO : std::vector<Mesh>
	// TODO : std::vector<Camera>
	std::vector<GameObject*> m_pObjects;
	// TODO : Light m_directionalLight;
	// TODO : static light // non-moving
	// TODO : dynamic light // moving
	// TODO : skybox

	//-----------------------------------
	// SCENE STATE
	//-------------------------------------------
	int m_selectedCamera;
	Settings::SceneRender m_sceneRenderSettings;


	//------------------------------------------------
	// SYSTEMS
	//--------------------------------------------------
	// TODO : Renderer * m_pRenderer;
	// TODO : LODManager m_LODManager;


	// TODO : Pool에 있는 오브젝트를
	// 이 함수를 통해 요청해서 받아온다.
	static GameObject* RequestObject();
private :

	// TODO : GameObjectPool m_objectPool;
	// TODO : MaterialPool m_materials;
	// TOOD : ModelLoader
	// TODO : ModelLoadQueue

	// TODO? : BoundingBox m_sceneBoundingBox;

	SceneView m_sceneView;



private:

	void StartLoadingModels();
	void EndLoadingModels();

	//void AddStaticLight(const Light& light);
	//void AddDynamicLight(const Light& light);



	void ClearLights();
};

