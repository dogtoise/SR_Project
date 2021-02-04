#pragma once
#include "Object.h"

// 게임오브젝트는 
// 렌더 해봤자 디버그 정도(기즈모)

// 아니다 차라리
// gameobject에서 메쉬, 각종 버텍스정보를 들고있고
// GameObject를 렌더하는거
// Component는 보조적인 추가도구 느낌으로

// Scene에서 미리 필요한 오브젝트들 풀을
// 미리 정의해두고 (bullet등) 
// 필요할 때 풀에서 꺼내 사용하는 식으로 구현

class Component;
class GameObject : public Object
{
protected :
	GameObject();
public :
	~GameObject();


protected:
	// --------------------------------
	// INITIALIZER
	// -----------------------------------
	//virtual void InitializePrototype() = 0;

	//virtual Object* Clone() = 0;
public :

	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void LateUpdate() = 0;
	virtual void Render() = 0;

	// --------------------------------------
	// PUBLIC METHODS
	// --------------------------------------

	//template <typename Type>
	//Component* AddComponent()
	//{
	//	Type* component = new Type();
	//	component->Initialize();
	//	m_components.push_back(component);
	//	return m_components;
	//}

	bool CompareTag(std::wstring tag);

	template <typename Type>
	 Component* GetComponent();
	// Returns the component of Type type in the
	// GameObject or any of its children using depth first search.
	//template <typename Type>
	// Component* GetComponentInChildren();
	//// Retrieves the component of Type type in the 
	//// GameObject or any of its parents.
	//template <typename Type>
	// Component* GetComponentInParent();
	template <typename Type>
	std::vector<class Component* > GetComponents();
	/*template <typename Type>
	std::vector<class Component* > GetComponentsInChildren();
	template <typename Type>
	std::vector<class Component* > GetComponentsInParent();*/

	void SetActive(bool active);

	// Gets the component of the specified type, if it exists.
	template <typename T>
	bool TryGetComponent(_Out_ Component** result);


	

	// ----------------------------------------------------------
	// STATIC METHODS
	// ---------------------------------------------------------------
	static GameObject* Find(std::wstring name);
	static std::vector<GameObject*> FindGameObjectsWithTag(std::wstring name);
	static GameObject* FindWithTag(std::wstring name);

	


protected :
	// --------------------------------------
	// PROPERTIES
	// --------------------------------------
	bool m_bActiveSelf;
	//TODO : Layer m_layer;
	// TODO : Scene m_scene;
	std::wstring m_tag;
	// The Transform attached to this GameObject.
	class Transform* m_pTransform;
	UINT m_layer;
	//Scene that the GameObject is part of.
	class IScene* m_pScene;

public :
	static std::vector<class Component* > m_components;
};


