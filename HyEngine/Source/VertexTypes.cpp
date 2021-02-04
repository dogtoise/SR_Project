#include "StandardEngineFramework.h"
#include "VertexTypes.h"

const DWORD SimpleVertex::FVF = D3DFVF_XYZ;

const DWORD ColorVertex::FVF = D3DFVF_XYZ | D3DFVF_DIFFUSE;

const DWORD VertexNormal::FVF = D3DFVF_XYZ | D3DFVF_NORMAL;

const DWORD TextureVertex::FVF = D3DFVF_XYZ | D3DFVF_TEX1;

