#include "StandardEngineFramework.h"
#include "EngineConfigurer.h"


IMPLEMENT_SINGLETON(EngineConfigurer)

EngineConfigurer::EngineConfigurer()
{
}


EngineConfigurer::~EngineConfigurer()
{
}

void EngineConfigurer::InsertScene(Scene * scene)
{
	for (auto& member : m_pScenes)
	{
		if (member == scene)
			return;
	}
	m_pScenes.push_back(scene);
}
