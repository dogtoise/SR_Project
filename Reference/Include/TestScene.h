#pragma once
#include "Scene.h"
class TestScene : public Scene
{
public  :
	TestScene();
	~TestScene();




	// Inherited via Scene

	virtual void Load() override;

	virtual void Unload() override;

	virtual void RenderUI() const override;


	// Inherited via Scene
	virtual void Update() override;

//	virtual void RenderOpaque() override; 


};

