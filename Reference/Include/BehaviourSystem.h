#pragma once


class BehaviourSystem
{
public:
	BehaviourSystem();
	~BehaviourSystem();


public :
	void InsertComponent(class Component* component);
	void RemoveComponent(class Component* component);



	void Update();
	void LateUpdate();

private : 

	std::vector<class Component*> m_components;
};

