#pragma once

struct ENGINE_DLL SimpleVertex
{
	SimpleVertex() {}

	SimpleVertex(float x, float y, float z)
		: x(x), y(y), z(z)
	{}
	
	float x, y, z;

	static const DWORD FVF;
};

struct ENGINE_DLL ColorVertex
{
	ColorVertex() {}

	ColorVertex(float x, float y, float z, D3DCOLOR c)
		: x(x), y(y), z(z), color(c)
	{

	}

	float x, y, z;
	D3DCOLOR color;

	static const DWORD FVF;
};

struct ENGINE_DLL VertexNormal
{
	VertexNormal() {}

	VertexNormal(float x, float y, float z, float nx, float ny, float nz)
		: x(x), y(y), z(z), nx(nx), ny(ny), nz(nz)
	{}

	float x, y, z;
	float nx, ny, nz;

	static const DWORD FVF;
};

struct ENGINE_DLL TextureVertex
{
	TextureVertex() {}

	TextureVertex(
		float x, float y, float z,
		float nx, float ny, float nz,
		float u, float v)
		: x(x), y(y), z(z),
		nx(nx), ny(ny), nz(nz),
		u(u), v(v)
	{}

	float x, y, z;
	float nx, ny, nz;
	float u, v;

	static const DWORD FVF;
};