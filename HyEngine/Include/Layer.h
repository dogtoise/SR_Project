#pragma once



class Layer
{
public :
	// 추가할 때 반드시 string 값도 최신화 해줄 것.
	static const UINT Default = 0x0001;
	static const UINT UI      = 0x0002;
	static const UINT Player  = 0x0004;

	static const std::wstring LayerToName(UINT layer)
	{
		for (auto layerMap : layersMap)
		{
			if (layerMap.second == layer)
				return layerMap.first;
		}
		return NULL;
	}
	static const UINT NameToLayer(std::wstring name)
	{
		for (auto layerMap : layersMap)
		{
			if (layerMap.first == name)
				return layerMap.second;
		}
		return NULL;
	}
private :
	static const std::unordered_map<std::wstring, UINT> layersMap;
	
};



class LayerMask
{
public :
	LayerMask(UINT value)
		: value(value)
	{

	}
	LayerMask(const LayerMask& value)
		: value(value.value)
	{
		
	}

	static LayerMask GetMask(const std::wstring& name)
	{
		LayerMask layerMask(Layer::NameToLayer(name));
		return layerMask;
	}
	UINT GetValue()
	{
		return value;
	}
private :
	UINT value;
};