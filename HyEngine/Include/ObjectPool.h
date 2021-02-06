#pragma once

#include <queue>
#include <memory>
#include <stdexcept>
//
//#define DEFAULT_CHUNK_SIZE 10
//
//class IObjectPool
//{
//
//};
//template <typename T>
//class ObjectPool : IObjectPool
//{
//private :
//	queue<T*> freeList;
//	size_t chunkSize;
//	ObjectPool(const ObjectPool<T>& src);
//	ObjectPool operator= (const ObjectPool<T>& rhs);
//
//public:
//	ObjectPool(size_t chunkSize = DEFAULT_CHUNK_SIZE);
//	virtual ObjectPool(void);
//
//	template<typename ObjectType>
//	void CreateObjects()
//	{
//		for (int i = 0; i < this->chunkSize; i++)
//		{
//			freeList.push(T::Create());
//		}
//	}
//	template<typename A1>
//	void CreateObjects(A1 arg1)
//	{
//		for (int i = 0; i < this->chunkSize; i++)
//		{
//			freeList.push(T::Create(arg1));
//		}
//	}
//	template<typename A1, typename A2>
//	void CreateObjects(A1 arg1, A2 arg2)
//	{
//		for (int i = 0; i < this->chunkSize; i++)
//		{
//			freeList.push(T::Create(arg1, arg2));
//		}
//	}
//	template<typename A1, typename A2>
//	void CreateObjects(A1 arg1, A2 arg2)
//	{
//		for (int i = 0; i < this->chunkSize; i++)
//		{
//			freeList.push(T::Create(arg1, arg2));
//		}
//	}
//	template<typename A1, typename A2, typename A3>
//	void CreateObjects(A1 arg1, A2 arg2, A3 arg3)
//	{
//		for (int i = 0; i < this->chunkSize; i++)
//		{
//			freeList.push(T::Create(arg1, arg2, arg3 ));
//		}
//	}
//	template< typename A1, typename A2, typename A3, typename A4>
//	void CreateObjects(A1 arg1, A2 arg2, A3 arg3, A4 arg4)
//	{
//		for (int i = 0; i < this->chunkSize; i++)
//		{
//			freeList.push(T::Create(arg1, arg2, arg3, arg4));
//		}
//	}
//
//
//	T* AccquireObject();
//	void ReleaseObejct(T* obj);
//};
//
//
//template<typename T>
//inline ObjectPool<T>::ObjectPool(size_t chunkSize)
//{
//	this->chunkSize = chunkSize;
//}
//
//
//template<typename T>
//inline T * ObjectPool<T>::AccquireObject()
//{
//	auto obj = freeList.front();
//	freeList.pop();
//
//	return obj;
//}
//
//template<typename T>
//inline void ObjectPool<T>::ReleaseObejct(T * obj)
//{
//	freeList.push(obj);
//}
//
//
//template<typename T>
//ObjectPool<T>::~ObjectPool(void)
//{
//}
