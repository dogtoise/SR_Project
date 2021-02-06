#include "StandardEngineFramework.h"
#include "TestComponent.h"



TestComponent::TestComponent(GameObject * owner)
	: Component(BehaviourType::Update | BehaviourType::LateUpdate, owner)
{

}


TestComponent::~TestComponent()
{
}

void TestComponent::Update()
{
	int a = 0;
}

void TestComponent::LateUpdate()
{

	int b = 0;
}

void TestComponent::OnEnable()
{
	
}

void TestComponent::OnDisable()
{
}
