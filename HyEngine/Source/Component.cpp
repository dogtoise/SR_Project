#include "StandardEngineFramework.h"
#include "..\Include\Component.h"



Component::Component(DWORD behaviourType, GameObject* owner)
	: Object(),
	m_behviourType(behaviourType),
	m_pOwner(owner)
{

}


Component::~Component()
{
}

void Component::Initialize()
{

	/*if (m_behviourType & BehaviourType::Update)
	{
		UpdateDispatcher::UpdateDispatch
		(
			std::bind(&Component::Update, this),
			std::bind(&Component::UpdateCompleted, this)
		);
	}
	if (m_behviourType & BehaviourType::LateUpdate)
	{
		UpdateDispatcher::LateUpdateDispatch
		(
			std::bind(&Component::LateUpdate, this),
			std::bind(&Component::LateUpdateCompleted, this)
		);
	}*/

	m_bInitialized = true;
}

bool Component::CompareTag(std::wstring tag)
{
	return m_tag == tag;
}
