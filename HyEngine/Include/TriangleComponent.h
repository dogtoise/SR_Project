#pragma once

#include "Component.h"

class TriangleComponent : public Component
{
protected:
	TriangleComponent();
	~TriangleComponent();

public: 
	static TriangleComponent* Create()
	{
		TriangleComponent* obj = new TriangleComponent();
		obj->Initialize();
		return obj;
	}



	virtual void Update() override;

	virtual void Render() override;
	// Inherited via Component
	virtual void Initialize() override;


private :
	IDirect3DVertexBuffer9 * triangleBuffer = nullptr;




};

