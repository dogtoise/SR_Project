#include "StandardEngineFramework.h"
#include "Transform.h"
using namespace LinearMath;


Transform::Transform(const Vector3 & position, const Quaternion & rotation, const Vector3 & scale)
	: 
	m_position(position)
	, m_rotation(rotation)
	, m_originalPosition(position)
	, m_originalRotation(rotation)
	, m_scale(scale)
{

}

Transform::~Transform()
{
}

Transform & Transform::operator=(const Transform &t)
{
	this->m_position = t.m_position;
	this->m_rotation = t.m_rotation;
	this->m_scale = t.m_scale;
	return *this;
}

void Transform::Translate(const Vector3 & translation)
{
	m_position = m_position + translation;
}

void Transform::Translate(float x, float y, float z)
{
	m_position = m_position + Vector3(x, y, z);
}

void Transform::Scale(const Vector3 & scale)
{
	m_scale = scale;
}

void Transform::RotateAroundPointAndAxis(const Vector3 & axis, float angle, const Vector3 & point)
{
	Vector3 R(m_position - point);
	const Quaternion rot = Quaternion::FromAxisAngle((const D3DXVECTOR3)axis, angle);
	R = rot.TransformVector(R);
	m_position = point+R; 
}

D3DXMATRIX Transform::WorldTransformationMatrix() const
{
	D3DXMATRIX output;
	D3DXMatrixAffineTransformation(&output, m_scale.x(),&(const D3DXVECTOR3)Vector3::Zero, &(const D3DXQUATERNION)m_rotation, &(const D3DXVECTOR3)m_position);
	return output;
}

D3DXMATRIX Transform::WorldTransformationMatrix_NoScale() const
{
	D3DXVECTOR3 scale = Vector3::One;
	D3DXVECTOR3 rotOrigin = Vector3::Zero;
	D3DXMATRIX output;
	return *D3DXMatrixAffineTransformation(&output, scale.x, &rotOrigin, &(const D3DXQUATERNION)m_rotation, &(D3DXVECTOR3)m_position);
}

D3DXMATRIX Transform::RotationMatrix() const
{
	return m_rotation.Matrix();
}

// builds normal matrix from world matrix, ignoring translation
// and using inverse-transpose of rotation/scale matrix
//https://stackoverflow.com/questions/13654401/why-transforming-normals-with-the-transpose-of-the-inverse-of-the-modelview-matr
// this link is about normal translation using inverse and transpose
// https://paroj.github.io/gltut/Illumination/Tut09%20Normal%20Transformation.html
// TODO : 검증이 필요하다.
// 포팅함 
D3DXMATRIX Transform::NormalMatrix(const D3DXMATRIX & world)
{
	D3DXMATRIX nrm = world;
	nrm._41 = nrm._42 = nrm._43 = 0;
	nrm._44 = 1;

	float det = D3DXMatrixDeterminant(&nrm);
	D3DXMatrixInverse(&nrm, &det, &nrm);
	D3DXMatrixTranspose(&nrm, &nrm);
	return nrm;
}

Transform * Transform::Find(std::wstring name)
{
	return nullptr;
}

Transform * Transform::GetChild(int index)
{
	return nullptr;
}

void Transform::LookAt(const Transform & target)
{
}

void Transform::Rotate(const Vector3 & eulers)
{
}

void Transform::SetParent(Transform * parent)
{
	m_parent = parent;
	if (m_parent == nullptr)
		m_root = nullptr;
	else if (m_parent->m_parent == nullptr)
		m_root = m_parent;
	else
	{
		m_root = m_parent->m_root;
	}
}

