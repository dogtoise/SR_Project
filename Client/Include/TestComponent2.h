#pragma once

#include "Component.h"


class TestComponent2 : public Component
{
private :
	//explicit TestComponent2(class GameObject* owner);
	TestComponent2(GameObject * owner)
		: Component(BehaviourType::Update | BehaviourType::LateUpdate, owner)
	{

	}

	virtual ~TestComponent2() {}


public:	
	static TestComponent2 * Create(GameObject * owner)
	{
		TestComponent2 * com = new TestComponent2(owner);
		com->Initialize();
		return com;

		//return nullptr;
	}

	// Inherited via Component
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void OnEnable() override;
	virtual void OnDisable() override;
};
//
//class TestComponent2 : public Component
//{
//private:
//	TestComponent2(class GameObject * owner);
//	~TestComponent2();
//
//
//public:
//	static TestComponent2 * Create(GameObject * owner)
//	{
//		TestComponent2 * com = new TestComponent2(owner);
//		com->Initialize();
//		return com;
//	}
//
//private:
//
//
//	// Inherited via Component
//	virtual void Update() override;
//
//
//	virtual void LateUpdate() override;
//
//	virtual void OnEnable() override;
//
//	virtual void OnDisable() override;
//
//};
//
