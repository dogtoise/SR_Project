#include "StandardEngineFramework.h"
#include "TestScene.h"
#include "TriangleObj.h"
#include "IObjectFactory.h"
#include "GeometryFactory.h"
#include "Fighter.h"
TestScene::TestScene()
	: Scene()
{

}


TestScene::~TestScene()
{
}



void TestScene::Load()
{
//#pragma region Create Prototype
//	IObjectFactory * factory = new GeometryFactory();
//	TriangleObj::CreatePrototype
//	(
//		L"Triangle_Test", 
//		factory, 
//		(void*)&GeometryFactory::Triangle
//	);
//	delete factory;
//#pragma endregion



//#pragma region AddGameObejcts
//	AddGameObject(L"Triangle_Test");
//#pragma endregion 


//#pragma region Render list set
//
//#pragma endregion


	m_pObjects.push_back(Fighter::Create());
}

void TestScene::Unload()
{
}

void TestScene::RenderUI() const
{
}

void TestScene::Update()
{

}

