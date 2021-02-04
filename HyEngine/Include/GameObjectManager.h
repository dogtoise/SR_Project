#pragma once

class GameObject;

class GameObjectManager
{
public:
	GameObjectManager();
	~GameObjectManager();

public :
	template <typename T>
	static GameObject* Create(LogicType logicType, RenderType renderType)
	{

	}
private :
	std::vector<GameObject* > m_gameObjects;
};

