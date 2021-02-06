#include "StandardEngineFramework.h"
#include "..\Include\Scene.h"
#include "Renderer.h"


Scene::Scene()
{

}
Scene::~Scene()
{
	for (auto& obj : m_opaqueObjects)
		SAFE_DELETE(obj);
	m_opaqueObjects.clear();
	for (auto& obj : m_alphaObjects)
		SAFE_DELETE(obj);
	m_alphaObjects.clear();
}

//void Scene::LoadScene(SerializedScene & scene, const Settings::Window & windowSettings)
//{
//	Load(scene);
//}
void Scene::LoadScene()
{
	Load();
}

void Scene::UnloadScene()
{
	Unload();
}

void Scene::UpdateScene()
{
	for (auto& obj : m_opaqueObjects)
		obj->Update();
	for (auto& obj : m_alphaObjects)
		obj->Update();
	
	Update();

	for (auto& obj : m_opaqueObjects)
	{
		obj->LateUpdate();
		if (obj->m_bWantsDestroy)
			SAFE_DELETE(obj);
	}
	for (auto& obj : m_alphaObjects)
	{
		obj->LateUpdate();
		if (obj->m_bWantsDestroy)
			SAFE_DELETE(obj);
	}
}


void Scene::RenderScene(Renderer * renderer)
{
	renderer->SetOpaqueContext();
	for (auto& opaqueObj : m_opaqueObjects)
	{
		if (opaqueObj->GetActive())
			renderer->Render(opaqueObj);
	}
	
	renderer->SetAlphaContext();
	for (auto& alphaObj : m_alphaObjects)
	{
		if (alphaObj->GetActive())
			renderer->Render(alphaObj);
	}

	RenderUI();
	RenderLights();
	RenderSkybox();
}

void Scene::AddOpaqueObject(GameObject * obj)
{
	m_opaqueObjects.push_back(obj);
}

void Scene::AddAlphaObject(GameObject * obj)
{
	m_alphaObjects.push_back(obj);
}


void Scene::RenderLights() const
{
	// TODO 
}

void Scene::RenderSkybox() const
{
	// TODO
}
