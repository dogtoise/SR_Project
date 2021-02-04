#pragma once
#include "GameObject.h"

class Fighter : public GameObject
{
public:
	Fighter();
	~Fighter();



public :


	// Inherited via GameObject
	virtual void Initialize() override;

private :



	// Inherited via GameObject
	virtual void Update() override;

	virtual void LateUpdate() override;

	virtual void Render() override;

public :
	static Fighter* Create()
	{
		Fighter* fighter = new Fighter();
		fighter->Initialize();
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

