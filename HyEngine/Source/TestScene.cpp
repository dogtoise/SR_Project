#include "StandardEngineFramework.h"
#include "TestScene.h"
#include "TriangleObj.h"
#include "IObjectFactory.h"
#include "GeometryFactory.h"
#include "Fighter.h"
#include "Renderer.h"
//TestScene::TestScene()
//	: Scene()
//{
//
//}
//
//
//TestScene::~TestScene()
//{
//}
//
//
//
//void TestScene::Load()
//{
//
//
//#pragma region Create Example
//	/*
//	// 아래 예제는 active false로 시작하는 예
//	auto obj = Fighter::Create(this);
//	obj->SetActive(false);
//	m_gameObjectsOnScene.push_back(obj);
//	*/
//
//
//	
//	// 아래 예제는 active true로 시작하는 예
//	auto obj = Fighter::Create(this);
//	obj->SetActive(true);
//	m_gameObjectsOnScene.push_back(obj);
//	
//
//	AddGameObject(Fighter::Create(this));
//#pragma endregion
//
//
//}
//
//void TestScene::Unload()
//{
//	for (auto obj : m_gameObjectsOnScene)
//	{
//		obj->Destroy(obj);
//	}
//}
//
//void TestScene::RenderUI() const
//{
//
//}
//
//void TestScene::Update()
//{
//
//}
//
//void TestScene::RenderObject(Renderer * renderer)
//{
//	renderer->SetOpaqueContext();
//	for (auto& renderObj : m_gameObjectsOnScene)
//	{
//		if (renderObj->GetActive())
//		{
//
//		}
//	}
//
//
//
//}
//
