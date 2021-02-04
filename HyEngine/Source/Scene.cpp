#include "StandardEngineFramework.h"
#include "..\Include\Scene.h"

void Scene::CalculateSceneBoundingBox()
{
}

Scene::Scene()
{
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
}

void Scene::UpdateScene()
{

	// TODO : Camera.Update(dt);
	Update();
	for (auto object : m_pObjects)
	{
		object->Update();
	}

}

void Scene::PreRender()
{
}




int Scene::RenderDebug(const D3DXMATRIX & viewProj) const
{
	return 0;
}

void Scene::Render()
{
	for (auto object : m_pObjects)
	{
		object->Render();
	}
}

void Scene::RenderOpaque()
{
}

void Scene::RenderAlpha()
{
}

void Scene::RenderLights() const
{

}

void Scene::RenderSkybox(const D3DXMATRIX & viewProj) const
{
}
