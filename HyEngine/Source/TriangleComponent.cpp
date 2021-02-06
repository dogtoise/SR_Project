#include "StandardEngineFramework.h"
#include "TriangleComponent.h"
#include "VertexTypes.h"
//
//
//TriangleComponent::TriangleComponent()
//	: Component()
//{
//}
//
//
//TriangleComponent::~TriangleComponent()
//{
//}
//
//
//
//void TriangleComponent::Update()
//{
//}
////
////void TriangleComponent::Render()
////{
////	DEVICE->SetStreamSource(0, triangleBuffer, 0, sizeof(SimpleVertex));
////	DEVICE->SetFVF(SimpleVertex::FVF);
////
////	DEVICE->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 1);
////}
//
//void TriangleComponent::Initialize()
//{
//	//m_pTransform = Transform::Create();
//	//
//
//
//	DEVICE->CreateVertexBuffer
//	(
//		3 * sizeof(SimpleVertex),
//		D3DUSAGE_DYNAMIC,
//		SimpleVertex::FVF,
//		D3DPOOL_DEFAULT,
//		&triangleBuffer,
//		0
//	);
//	SimpleVertex* vertices;
//	triangleBuffer->Lock(0, 0, (void**)&vertices, 0);
//	vertices[0] = SimpleVertex(-1.0f, 0.0f, 2.0f);
//	vertices[1] = SimpleVertex(0.0f, 1.0f, 2.0f);
//	vertices[2] = SimpleVertex(1.0f, 0.0f, 2.0f);
//
//	triangleBuffer->Unlock();
//
//	D3DXMATRIX proj;
//	D3DXMatrixPerspectiveFovLH
//	(
//		&proj,
//		D3DX_PI * 0.5f,
//		WinMaxWidth / WinMaxHeight,
//		1.0f,
//		1000.0f
//	);
//	DEVICE->SetTransform(D3DTS_PROJECTION, &proj);
//
//	DEVICE->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
//}
//
//void TriangleComponent::LateUpdate()
//{
//}
//
//void TriangleComponent::OnEnable()
//{
//}
//
//void TriangleComponent::OnDisable()
//{
//}
//
