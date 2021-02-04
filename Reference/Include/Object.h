#pragma once
#include "IObject.h"

class ObjDesc
{

};


class Object : public IObject
{

public:
	Object();
public:
	~Object();

protected:
	// --------------------------------
	// Clone 
	// -----------------------------------
	//virtual Object* Clone() = 0;
	// example 
	/*
	class Pawn
	Object * Clone()
	{
		Object * obj = new Pawn(*this);
		return obj;
	}
	
	*/
	//virtual Object* Clone() = 0;
	virtual void Initialize() = 0;
	
public:
	// ----------------------------------
	// PUBLIC METHODS
	// -----------------------------------
	UINT GetInstanceID();
	std::wstring ToString();

	// -----------------------------------
	// STATIC METHODS
	// -----------------------------------
	/*static void Destroy();
	static void DontDestroyOnLoad();
	template <typename T>
	static Object* FindObjectOfType();
	template <typename T>
	static std::vector<Object*> FindObjectsOfType();*/
	/*static Object* Instantiate(const Object& original);
	static Object* Instantiate(const Object& original, const Transform& parent);
	static Object* Instantiate(const Object& original, const Vector3& position, const Quaternion& rotation);
	static Object* Instantiate(const Object& original, const Vector3& position, const Quaternion& rotation, const Transform& parent);*/


	// ------------------------------------
	// OPERATORS
	// -----------------------------------
	inline bool operator != (Object* other) { return this->GetInstanceID() != other->GetInstanceID(); }
	inline bool operator == (Object* other) { return this->GetInstanceID() == other->GetInstanceID(); }

private:


private:
	std::wstring m_name;
	LONGLONG m_id;
//private :
//	//DWORD m_logicType;
//	//DWORD m_renderType;
//public :
//	const DWORD& GetLogicType() const;
//	void SetLogicType(const DWORD& logicType);
//	const DWORD& GetRenderType() const;
//	void SetRenderType(const DWORD& renderType);

protected :
	//struct DefaultInfo
	//{
	//	DWORD logicType;
	//	DWORD renderType;
	//	std::wstring name;
	//	std::wstring tag;
	//	Layer layer;
	//	bool isActive;
	//};
	//void SetDefaultInfo(const DefaultInfo& info)
	//{
	//	m_logicType = info.logicType;
	//	m_renderType = info.renderType;
	//	m_name = info.name;
	//	

	//}
	// -------------------------------------------
	// MANAGEMENT 
	// ---------------------------------------------

public:
	//template <typename ObjType>
	//static ObjType* Create();


	/*static void CreatePrototype(const std::wstring& prototypeName, 
		class IObjectFactory * factory, 
		void* arg = nullptr);
	static void CreatePrototype(const std::wstring& prototypeName,
		std::function<Object*(void* arg)> creator,
		void* arg = nullptr);
	
	static Object* CreateClone(const std::wstring& prototypeName)
	{
		auto obj = m_objects[prototypeName];
		if (obj == nullptr)
		{
			throw std::invalid_argument("The prototype does not exist.");
		}
		else
			return obj->Clone();
	}*/
protected:
	
private :

	//static std::unordered_map<std::wstring, Object*> m_objects;
	//static std::vector<Object*> m_objects;
};

//template<typename ObjType>
//inline ObjType* Object::Create()
//{
//	ObjType* object = nullptr;
//	for (auto obj : m_objects)
//	{
//		// TODO : ∞À¡ı
//		object = dynamic_cast<ObjType*>(obj);
//		
//		// TODO : clone create logic 
//		if (object != nullptr) // return clone
//		{
//			return new ObjType(*object);
//		}
//	}
//	if (object == nullptr)
//	{
//		// prototype create logic 
//		object = ObjType::CreatePrototype();
//		m_objects.push_back(object);
//		return new ObjType(*object);
//	}
//	return nullptr;
//}


