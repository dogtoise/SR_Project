#pragma once
#include "Object.h"

// ���ӿ�����Ʈ�� 
// ���� �غ��� ����� ����(�����)

// �ƴϴ� ����
// gameobject���� �޽�, ���� ���ؽ������� ����ְ�
// GameObject�� �����ϴ°�
// Component�� �������� �߰����� ��������

// Scene���� �̸� �ʿ��� ������Ʈ�� Ǯ��
// �̸� �����صΰ� (bullet��) 
// �ʿ��� �� Ǯ���� ���� ����ϴ� ������ ����

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


