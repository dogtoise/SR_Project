#include "StandardEngineFramework.h"
#include "BehaviourSystem.h"
#include "Component.h"



BehaviourSystem::BehaviourSystem()
{
}


BehaviourSystem::~BehaviourSystem()
{
}

void BehaviourSystem::InsertComponent(Component* component)
{
	m_components.push_back(component);
}

void BehaviourSystem::RemoveComponent(Component * component)
{
	for (int i = 0; i < m_components.size(); i++)
	{
		auto& comp = m_components[i];
		if (comp == component)
			m_components.erase(m_components.begin() + i);
	}
}

void BehaviourSystem::Update()
{
	for (auto& component : m_components)
		component->Update();
}

void BehaviourSystem::LateUpdate()
{
	for (auto component : m_components)
		component->LateUpdate();
}


