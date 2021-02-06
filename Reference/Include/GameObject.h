#pragma once
#include "Object.h"
#include "IRenderable.h"


class Component;
class ENGINE_DLL GameObject : public Object, public IRenderable
{
protected :
	GameObject(ERenderType renderType, class Scene* scene, const std::wstring& tag );
public :
	virtual ~GameObject();


protected:
	// --------------------------------
	// INITIALIZER
	// -----------------------------------
	//virtual void InitializePrototype() = 0;

	//virtual Object* Clone() = 0;
protected :

	virtual void Initialize();


public :
	virtual void Render() = 0;
	void Update();
	void LateUpdate();

	// --------------------------------------
	// PUBLIC METHODS
	// --------------------------------------


	bool CompareTag(std::wstring tag);

	inline ERenderType GetRenderType()const { return m_renderType; }


	Component* AddComponent(Component* component)
	{
		m_components.emplace_back(component);
		return component;
	}

	template <typename Type>
	Component* GetComponent()
	{
		for (auto& component : m_components)
		{
			Type* comp = dynamic_cast<Type*>(component);
			if (comp != nullptr)
				return comp;
		}
		return nullptr;
	}

	template <typename Type>
	std::vector<class Component* > GetComponents()
	{
		std::vector<component*> comVec;
		for (auto& component : m_components)
		{
			Type* comp = dynamic_cast<Type*> (component);
			if (comp != nullptr)
				comVec.push_back(comp);
		}
		return comVec;
	}

	inline void SetActive(bool active) { m_bActiveSelf = active; }
	inline bool GetActive() { return m_bActiveSelf; }

	// Gets the component of the specified type, if it exists.
	template <typename T>
	bool TryGetComponent(_Out_ Component** result)
	{
		for (auto& component : m_components)
		{
			T * comp = dynamic_cast<T*>(component);
			if (comp != nullptr)
			{
				result = comp;
				return true;
			}
		}
		return false;
		

	}


	

	// ----------------------------------------------------------
	// STATIC METHODS
	// ---------------------------------------------------------------



protected :
	// --------------------------------------
	// PROPERTIES
	// --------------------------------------
	bool m_bActiveSelf;
	//TODO : Layer m_layer;
	// TODO : Scene m_scene;
	const std::wstring m_tag;
	// The Transform attached to this GameObject.
	class Transform* m_pTransform;
	UINT m_layer;
	//Scene that the GameObject is part of.
	class Scene* m_pScene;

	ERenderType m_renderType;
public :
	std::vector<class Component* > m_components;
};
