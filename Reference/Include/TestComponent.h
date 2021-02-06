#pragma once

#include "Component.h"
class TestComponent : public Component
{
private:
	TestComponent(class GameObject * owner);
	~TestComponent();


public :
	static TestComponent * Create(GameObject * owner)
	{
		TestComponent * com = new TestComponent(owner);
		com->Initialize();
		return com;
	}

private :


	// Inherited via Component
	virtual void Update() override;


	virtual void LateUpdate() override;

	virtual void OnEnable() override;

	virtual void OnDisable() override;

};

