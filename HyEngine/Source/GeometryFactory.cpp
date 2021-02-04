#include "StandardEngineFramework.h"
#include "GeometryFactory.h"
#include "TriangleObj.h"

Object * GeometryFactory::Create(void * arg)
{
	int* type = (int*)arg;
	switch (*type)
	{
	case GeometryFactory::TRIANGLE :
		return CreateTriangle();
		break;
	case GeometryFactory::CUBE :
		return CreateCube();
		break;
	case GeometryFactory::QUAD :
		return CreateQuad();
		break;
	}

	return nullptr;
}

Object * GeometryFactory::CreateTriangle()
{
	////Object* test = new Object();
	//TriangleObj * result = new TriangleObj();
	//
	//result->Init();

	//return result;
	return nullptr;
}

Object * GeometryFactory::CreateCube()
{
	return nullptr;
}

Object * GeometryFactory::CreateQuad()
{
	return nullptr;
}
