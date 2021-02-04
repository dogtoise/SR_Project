#pragma once
#include "StandardEngineFramework.h"

struct Light;
struct PointLight;
struct DirectionalLight;
class GameObject;

using RenderList = std::vector<const GameObject*>;



struct SceneView
{
	D3DXMATRIX view;
	D3DXMATRIX viewProj;
	D3DXMATRIX viewInverse;
	D3DXMATRIX proj;
	D3DXMATRIX projInverse;
	D3DXMATRIX directionalLightProjection;

	D3DXVECTOR3 cameraPosition;
	Settings::SceneRender sceneRenderSettings;


	// list of objects that has the renderSettings.bRedner = true
	RenderList opaqueList;
	RenderList alphaList;

	// list of objects that fall within the main camera's view frustum
	RenderList culledOpaqueList;
};