#pragma once
#include "IObjectFactory.h"
#include "TriangleObj.h"

class GeometryFactory : public IObjectFactory
{
public :
	// Inherited via IObjectFactory
	virtual Object * Create(void * arg) override;

public :
	// geometry type index
	static const UINT Triangle = 0;
	static const UINT Cube = 1;
	static const UINT Quad = 2;
	enum GeometryType
	{
		TRIANGLE = 0 ,
		CUBE,
		QUAD
	};
private :
	Object* CreateTriangle();
	Object* CreateCube();
	Object* CreateQuad();
};

