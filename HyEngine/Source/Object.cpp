#include "StandardEngineFramework.h"
#include "Object.h"
#include "IObjectFactory.h"


Object::Object()
{	
	//m_id = UIDGen::Get()->GetUID();
}


Object::~Object()
{
	//m_id = UIDGen::Get()->GetUID();
}
//
//void Object::CreatePrototype(const std::wstring & prototypeName, IObjectFactory * factory, void* arg )
//{
//	if (m_objects[prototypeName] == nullptr)
//	{
//		m_objects.insert(make_pair(prototypeName, factory->Create(arg)));
//	}
//	else
//	{
//		throw std::invalid_argument("You tried to create a prototype that already exists");
//	}
//}
//
//void Object::CreatePrototype(const std::wstring & prototypeName, std::function<Object*(void*arg)> creator, void * arg)
//{
//	if (m_objects[prototypeName] == nullptr)
//	{
//		m_objects.insert(make_pair(prototypeName, creator(arg)));
//	}
//	else
//	{
//		throw std::invalid_argument("You tried to create a prototype that already exists");
//	}
//}
//
//
//
//const DWORD & Object::GetLogicType() const
//{
//	// TODO: insert return statement here
//	return m_logicType;
//}
//
//void Object::SetLogicType(const DWORD & logicType)
//{
//	m_logicType = logicType;
//}
//
//const DWORD & Object::GetRenderType() const
//{
//	// TODO: insert return statement here
//	return m_renderType;
//}
//
//void Object::SetRenderType(const DWORD & renderType)
//{
//	m_renderType = renderType;
//}
