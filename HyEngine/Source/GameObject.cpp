#include "StandardEngineFramework.h"
#include "GameObject.h"
#include "Component.h"



GameObject::GameObject(ERenderType renderType, Scene* scene, const std::wstring& tag)
	: Object(),
	m_renderType(renderType),
	m_bActiveSelf(true),
	m_pScene(scene),
	m_tag(tag)
{
	m_pTransform = new Transform();

	switch (renderType)
	{
	case ERenderType::RenderAlpha :
		scene->AddAlphaObject(this);
		break;
	case ERenderType::RenderOpaque:
		scene->AddOpaqueObject(this);
		break;
	}
}


GameObject::~GameObject()
{
	delete m_pTransform;
	for (auto& com : m_components)
		SAFE_DELETE(com);
	m_components.clear();
}

void GameObject::Initialize()
{



}

void GameObject::Update()
{
	for (auto& com : m_components)
	{
		if (com->GetBehaviourType() & BehaviourType::Update)
		{
			com->Update();
		}
	}
}

void GameObject::LateUpdate()
{
	for (auto& com : m_components)
	{
		if (com->GetBehaviourType() & BehaviourType::LateUpdate)
		{
			com->LateUpdate();
		}

		if (com->m_bWantsDestroy)
		{
			SAFE_DELETE(com);
		}
	}


}

bool GameObject::CompareTag(std::wstring tag)
 {
	 return m_tag == tag;
 }
