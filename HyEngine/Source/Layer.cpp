#include "StandardEngineFramework.h"
#include "Layer.h"



const std::unordered_map<std::wstring, UINT> Layer::layersMap =
{
	{ L"Default", Default },
	{ L"UI", UI },
	{ L"Player", Player }
};