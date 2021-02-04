#pragma once

#include "Component.h"

class Camera : public Component
{
public :
	Camera();
	~Camera();

	void SetViewMatrix();
	D3DXMATRIX GetViewMatrix();


};