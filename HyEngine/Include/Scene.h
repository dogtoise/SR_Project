#pragma once
#include "IScene.h"
#include "GameObject.h"
class GameObject;

class ENGINE_DLL Scene 
{
protected :
	// Inherited via IScene
	virtual void Update()  =0;
	virtual void Load() =0;
	virtual void Unload() =0;
	virtual void RenderUI() const =0;



public :
	explicit Scene();
	virtual ~Scene();


	void LoadScene();


	void UnloadScene();


	void UpdateScene();



	void RenderScene(class Renderer * renderer);




	void AddOpaqueObject(class GameObject* obj);
	void AddAlphaObject(class GameObject* obj);
private :

	void RenderLights() const;
	void RenderSkybox() const;


protected : 
	int m_selectedCamera;
	// TODO : Camera
private :


private:

	std::vector<GameObject* > m_opaqueObjects;
	std::vector<GameObject* > m_alphaObjects;
};

