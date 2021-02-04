#pragma once
#include "Object.h"

class Component : public Object
{
public:
	Component();
	~Component();


public :
	// ------------------------------------------------------------
	// PUBLIC METHODS
	// ------------------------------------------------------------
	bool CompareTag(std::wstring tag);\

	//Returns the component of Type type if the game object has one attached, null if it doesn't.
	template <typename T>
	Component* GetComponent();

	//Returns the component of Type type in the GameObject or any of its children using depth first search.
	template <typename T>
	Component* GetComponentInChildren();
	
	template <typename T>
	Component* GetComponentInParent();

	template<typename T>
	std::vector<Component*> GetComponents();
	template <typename T>
	std::vector<Component*> GetComponentsInChildren();
	template <typename T>
	std::vector<Component*> GetComponentsInParent();

	// Gets the component of the specified type, if it exists.
	template <typename T>
	bool TryGetComponent(_Out_ Component** result);

	void SetGameObject(GameObject* obj)
	{
		m_pGameObject = obj;
	}
	GameObject* GetGameObejct()
	{
		return m_pGameObject;
	}
public :

	virtual void Update() = 0;
	virtual void Render() = 0;
private :
	// ---------------------------------------------------------
	// PROPERTIES
	// ---------------------------------------------------------------
	class GameObject* m_pGameObject;
	std::wstring m_tag;




	// Inherited via Object
	virtual void Initialize() override;



};

