#pragma once
#include "Object.h"



class ENGINE_DLL Component : public Object
{
public:
	// example : Component(BehaviourType::Update | BehaviourType::LateUpdate)
	explicit Component(DWORD behaviourType, GameObject * owner); 
	virtual ~Component();

protected :
	void Initialize();

public :
	virtual void Update() = 0;
	virtual void LateUpdate() = 0;
	virtual void OnEnable() = 0;
	virtual void OnDisable() = 0;
public :
	// ------------------------------------------------------------
	// PUBLIC METHODS
	// ------------------------------------------------------------
	bool CompareTag(std::wstring tag);

	//Returns the component of Type type if the game object has one attached, null if it doesn't.
	template <typename T>
	Component* GetComponent()
	{
		return m_pOwner->GetComponent<T>();
	}

	template <typename T>
	bool TryGetComponent(_Out_ Component** result)
	{
		result = GetComponent<T>();
		if (result == nullptr)
			return false;
		return true;
	}
	
	GameObject* GetGameObejct()
	{
		return m_pOwner;
	}
	DWORD GetBehaviourType()
	{
		return m_behviourType;
	}
public :


private :
	// ---------------------------------------------------------
	// PROPERTIES
	// ---------------------------------------------------------------
	class GameObject* m_pOwner;
	std::wstring m_tag;
	DWORD m_behviourType;

	bool m_bInitialized;



};
