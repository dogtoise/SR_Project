#include "StandardEngineFramework.h"
#include "TriangleObj.h"
#include "TriangleComponent.h"
//
//
//TriangleObj::TriangleObj()
//	: GameObject()
//{
//}
//
//
//TriangleObj::~TriangleObj()
//{
//}
//
//void TriangleObj::Initialize()
//{
//	m_pTransform =new Transform();
//	//m_pTransform->SetGameObject(this);
//	//m_pTransform->SetTransform(m_pTransform);
//	m_pTransform->SetParent(nullptr);
//	m_tag = L"Default";
//	m_bActiveSelf = true;
//	m_pScene = ENGINE->GetActiveScene();
//	m_layer = Layer::Default;
//	//SetLogicType(LogicType::Update | LogicType::LateUpdate);
//	//SetRenderType(RenderType::RenderOpaque);
//
//
//	//m_components.push_back(m_pTransform);
//	m_components.push_back(TriangleComponent::Create());
//}
//
//void TriangleObj::LateUpdate()
//{
//}
//
//
//
////Object * TriangleObj::Clone()
////{
////	return new TriangleObj(*this);
////}
//
////void TriangleObj::Start()
////{
////}
//
//void TriangleObj::Update()
//{
//	for (auto component : m_components)
//		component->Update();
//}
//
////void TriangleObj::LateUpdate()
////{
////}
//void TriangleObj::Render()
//{
//	/*for (auto component : m_components)
//		component->Render();*/
//	/*DEVICE->SetStreamSource(0, triangleBuffer, 0, sizeof(SimpleVertex));
//	DEVICE->SetFVF(SimpleVertex::FVF);
//
//	DEVICE->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 1);*/
//}