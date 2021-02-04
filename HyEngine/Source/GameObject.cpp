#include "StandardEngineFramework.h"
#include "GameObject.h"
#include "Component.h"



GameObject::GameObject()
	: Object()
{

}


GameObject::~GameObject()
{
}

 std::vector< Component* > GameObject::m_components;