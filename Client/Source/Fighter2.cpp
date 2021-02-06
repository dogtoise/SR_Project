#include "StandardEngineFramework.h"
#include "Fighter2.h"
#include "ObjLoader.h"
#include "VertexTypes.h"
#include "TestComponent2.h"
#include "Scene.h"
//Fighter2::Fighter2(Scene* scene)
//	: GameObject(ERenderType::RenderOpaque, scene, Tags::Player)
//{
//
//	AddComponent(TestComponent2::Create(this));
//
//
//}
Fighter2::Fighter2(Scene* scene)
	: GameObject(ERenderType::RenderOpaque, scene, Tags::Player)
{
	AddComponent(TestComponent2::Create(this));
}
//
//Fighter2::Fighter2(Scene* scene)
//	: GameObject(ERenderType::RenderOpaque, scene, Tags::Player)
//{
//
//	AddComponent(TestComponent2::Create(this));
//
//
//}
//
//
//Fighter2::~Fighter2()
//{
//
//}
//
void Fighter2::Initialize()
{
	//objl::Loader loader;
	//loader.LoadFile("../Resources/knife_LOD2.obj");
	//m_pTransform = new Transform();
	objl::Loader loader;
	loader.LoadFile("../Resources/knife_LOD2.obj");
	m_pTransform = new Transform();


	//m_pTransform = new Transform();

	////std::vector <objl::Vertex > vecs = loader.LoadedVertices.size();

	//DEVICE->CreateVertexBuffer
	//(
	//	loader.LoadedVertices.size() * sizeof(TextureVertex),
	//	D3DUSAGE_DYNAMIC,
	//	TextureVertex::FVF,
	//	D3DPOOL_DEFAULT,
	//	&vertexBuffer,
	//	0
	//);

	//TextureVertex* vertices;
	//vertexBuffer->Lock(0, 0, (void**)&vertices, 0);

	//for (int i = 0; i < loader.LoadedVertices.size(); i++)
	//{
	//	vertices[i].x = loader.LoadedVertices[i].Position.X;
	//	vertices[i].y = loader.LoadedVertices[i].Position.Y;
	//	vertices[i].z = loader.LoadedVertices[i].Position.Z;

	//	vertices[i].nx = loader.LoadedVertices[i].Normal.X;
	//	vertices[i].ny = loader.LoadedVertices[i].Normal.Y;
	//	vertices[i].nz = loader.LoadedVertices[i].Normal.Z;

	//	vertices[i].u = loader.LoadedVertices[i].TextureCoordinate.X;
	//	vertices[i].v = loader.LoadedVertices[i].TextureCoordinate.Y;
	//}

	//vertexBuffer->Unlock();

	//DEVICE->CreateIndexBuffer
	//(
	//	loader.LoadedIndices.size() * sizeof(unsigned int),
	//	D3DUSAGE_DYNAMIC,
	//	D3DFMT_INDEX32,
	//	D3DPOOL_DEFAULT,
	//	&indexBuffer,
	//	nullptr
	//);

	//unsigned int * indices = nullptr;
	//indexBuffer->Lock(0, 0, (void**)&indices, 0);

	//for (int i = 0; i < loader.LoadedIndices.size(); i++)
	//{
	//	indices[i] = loader.LoadedIndices[i];
	//}
	//indexBuffer->Unlock();

	//vertexNum = loader.LoadedVertices.size();
	//primCount = loader.LoadedIndices.size() / 3;

	//D3DXMATRIX proj;
	//D3DXMatrixPerspectiveFovLH
	//(
	//	&proj,
	//	D3DX_PI* 0.5f, // 90 degree
	//	WinMaxWidth / WinMaxHeight,
	//	1.0f,
	//	1000.0f
	//);
	//DEVICE->SetTransform(D3DTS_PROJECTION, &proj);


	//D3DMATERIAL9 material;
	//material.Ambient = (D3DXCOLOR)D3DCOLOR_XRGB(255, 255, 255);
	//material.Diffuse = (D3DXCOLOR)D3DCOLOR_XRGB(255, 255, 255);
	//material.Specular = (D3DXCOLOR)D3DCOLOR_XRGB(255, 255, 255);
	//material.Emissive = (D3DXCOLOR)D3DCOLOR_XRGB(0, 0, 0);
	//material.Power = 5.0f;

	//DEVICE->SetMaterial(&material);

	//// setup a directional light

	//D3DLIGHT9 dirLight;
	//ZeroMemory(&dirLight, sizeof(dirLight));
	//dirLight.Type = D3DLIGHT_DIRECTIONAL;
	//dirLight.Ambient = D3DXCOLOR(0.8f, 0.8f, 0.8f, 1.0f);
	//dirLight.Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	//dirLight.Specular = D3DXCOLOR(0.2f, 0.2f, 0.2f, 1.0f);
	//dirLight.Direction = D3DXVECTOR3(1.0f, 0.0f, 0.0f);

	//// set and enable the light

	//DEVICE->SetLight(0, &dirLight);
	//DEVICE->LightEnable(0, true);


	//// automatic normalization of vertex normal
	//DEVICE->SetRenderState(D3DRS_NORMALIZENORMALS, true);
	//DEVICE->SetRenderState(D3DRS_SPECULARENABLE, true);


	//D3DXCreateTextureFromFile(
	//	DEVICE,
	//	L"../Resources/Knife_hangar.png",
	//	&texture);
	//D3DXCreateTextureFromFile(
	//	DEVICE,
	//	L"../Resources/Lightmap-0_comp_light.png",
	//	&lightMap);

	//// Set Texture Filter States.
	//DEVICE->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
	//DEVICE->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
	//DEVICE->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_LINEAR);

	//DEVICE->SetSamplerState(1, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
	//DEVICE->SetSamplerState(1, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
	//DEVICE->SetSamplerState(1, D3DSAMP_MIPFILTER, D3DTEXF_LINEAR);
}
//
//
void Fighter2::Render()
{
// 
// 	// Animate the camera:
	// The camera will circle around the center of the scene.  We use the
	// sin and cos functions to generate points on the circle, then scale them
	// by 10 to further the radius.  In addition the camera will move up and down
	// as it circles about the scene.
// 	static float angle = (3.0f * D3DX_PI) / 2.0f;
// 	static float cameraHeight = 0.0f;
// 	static float cameraHeightDirection = 5.0f;
// 
// 	D3DXVECTOR3 position(cosf(angle) * 10.0f, cameraHeight, sinf(angle) * 10.0f);
// 
// 	// the camera is targetted at the origin of the world
// 	D3DXVECTOR3 target(0.0f, 0.0f, 0.0f);
// 
// 	// the worlds up vector
// 	D3DXVECTOR3 up(0.0f, 1.0f, 0.0f);
// 
// 	D3DXMATRIX viewMatrix;
// 	D3DXMatrixLookAtLH(&viewMatrix, &position, &target, &up);
// 
// 
// 	D3DXMatrixIdentity(&viewMatrix);
// 	DEVICE->SetTransform(D3DTS_VIEW, &viewMatrix);
// 
// 	angle += 0.001f;
// 	if (angle >= 6.28f)
// 		angle = 0.0f;
// 
// 	// compute the height of the camera for the next frame
// 	cameraHeight += cameraHeightDirection * 0.001f;
// 	if (cameraHeight >= 10.0f)
// 		cameraHeightDirection = -5.0f;
// 
// 	if (cameraHeight <= -10.0f)
// 		cameraHeightDirection = 5.0f;
// 
// 	DEVICE->SetTexture(0, texture);
// 	//DEVICE->SetTexture(1, lightMap);
// 
// 	//DEVICE->SetTextureStageState(0, D3DTSS_TEXCOORDINDEX, 0);
// 	//DEVICE->SetTextureStageState(1, D3DTSS_TEXCOORDINDEX, 0);
// 
// 	//DEVICE->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_SELECTARG1);
// 
// 	//DEVICE->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
// 
// 	//DEVICE->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_SELECTARG1);
// 
// 	//DEVICE->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
// 
// 	//// color operation을 modulate로 설정
// 	//DEVICE->SetTextureStageState(1, D3DTSS_COLOROP, D3DTOP_MODULATE);
// 
// 	//DEVICE->SetTextureStageState(1, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
// 
// 	//// 컬러의 첫 번째 인자는 현재 스테이지의 텍스처의 컬러 값
// 	//DEVICE->SetTextureStageState(1, D3DTSS_COLORARG1, D3DTA_TEXTURE);
// 
// 	//// 컬러의 두 번째 인자는 이전 스테이지에서 전달된 컬러 값
// 	//DEVICE->SetTextureStageState(1, D3DTSS_COLORARG2, D3DTA_CURRENT);
// 
// 	//// 알파의 첫 번째 인자는 현재 스테이지의 텍스처의 알파 값
// 	//DEVICE->SetTextureStageState(1, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
// 
// 	//// 알파의 두 번째 인자는 이전 스테이지에서 전달된 알파 값
// 	//DEVICE->SetTextureStageState(1, D3DTSS_ALPHAARG2, D3DTA_CURRENT);
// 
// 	//g_pd3dDevice->SetTextureStageState(2, D3DTSS_COLOROP, D3DTOP_DISABLE);
// 	//g_pd3dDevice->SetTextureStageState(2, D3DTSS_ALPHAOP, D3DTOP_DISABLE);
// 
// 
// 	DEVICE->SetStreamSource(0, vertexBuffer, 0, sizeof(TextureVertex));
// 
// 	DEVICE->SetFVF(TextureVertex::FVF);
// 
// 	DEVICE->SetIndices(indexBuffer);
// 
// 
// 	DEVICE->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, vertexNum, 0, primCount);

}
//

//void Fighter2::Render()
//{
//}
