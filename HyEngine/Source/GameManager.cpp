#include "StandardEngineFramework.h"
#include "GameManager.h"
#include "GameObject.h"
#include "Renderer.h"
#include "BehaviourSystem.h"
#include "UpdateDispatcher.h"
//
//IMPLEMENT_SINGLETON(GameManager)
//
//GameManager::GameManager()
//{
//
//}
//
//
//GameManager::~GameManager()
//{
//
//}
//
//bool GameManager::InsertObject(Object * object)
//{
//	GameObject * go = dynamic_cast<GameObject*>(object);
//	if (go != nullptr)
//	{
//		//m_pRenderer->InsertGameObject(go);
//		switch (go->GetRenderType())
//		{
//		case ERenderType::RenderAlpha:
//			m_alphaObjects.emplace_back(go);
//			break;
//		case ERenderType::RenderOpaque:
//			m_opaqueObjects.emplace_back(go);
//		}
//
//		return true;
//	}
//
//
//
//	Component * com = dynamic_cast<Component*>(object);
//	if (com != nullptr)
//	{
//		m_components.emplace_back(com);
//		return true;
//	}
//
//	return false;
//}
//
//void GameManager::RenderObjects(Renderer * renderer)
//{
//	//renderer->BeginRenderEvent(L"Start Object Render");
//	
//	renderer->SetOpaqueContext();
//	renderer->RenderList(m_opaqueObjects);
//	
//	renderer->SetAlphaContext();
//	renderer->RenderList(m_alphaObjects);
//
//	//renderer->EndRenderEvent(L"End Object Render");
//}
//
//void GameManager::UpdateObjects()
//{
//	UpdateDispatcher::Update();
//	UpdateDispatcher::LateUpdate();
//}
//
//
