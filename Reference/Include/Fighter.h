#pragma once
#include "GameObject.h"

class Fighter : public GameObject
{
public:
	Fighter(Scene* scene);
	virtual ~Fighter();



public :


	// Inherited via GameObject
	virtual void Initialize() override;

private :



	virtual void Render() override;

public :
	static Fighter* Create(Scene* scene)
	{
		Fighter* fighter = new Fighter(scene);
		fighter->m_pScene = scene;
		fighter->Initialize();

		//ObjectManager::Get()->InsertObject(fighter);
		return fighter;
	}

private :
	IDirect3DVertexBuffer9 * vertexBuffer = nullptr;

	IDirect3DIndexBuffer9* indexBuffer = nullptr;
	//class objl::Loader loader;
	UINT vertexNum;
	UINT primCount;

	IDirect3DTexture9 * texture = nullptr;
	IDirect3DTexture9* lightMap = nullptr;


};

