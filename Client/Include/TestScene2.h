#pragma once
#include "Scene.h"

class TestScene2 : public Scene
{
	// Inherited via Scene
	virtual void Update() override;
	virtual void Load() override;
	virtual void Unload() override;
	virtual void RenderUI() const override;
};
//
//class TestScene2 : public Scene
//{
//public:
//	TestScene2();
//	virtual ~TestScene2();
//
//
//	// Inherited via Scene
//
//	virtual void Load() override;
//
//	virtual void Unload() override;
//
//	virtual void RenderUI() const override;
//
//
//	// Inherited via Scene
//	virtual void Update() override;
//
//
//	//	virtual void RenderOpaque() override; 
//
//private:
//	//	ObjectPool<Fighter> * fighterPool;
//
//
//
//	//typedef std::pair<std::function<void(GameObject*)>, GameObject*> ObjPair;
//
//	//std::unordered_map<LONGLONG, ObjPair> m_objMap;
//
//
//};
//
//
//
