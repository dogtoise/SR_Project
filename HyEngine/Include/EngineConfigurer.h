#pragma once


class EngineConfigurer
{
	DECLARE_SINGLETON(EngineConfigurer)
private:
	EngineConfigurer();
	~EngineConfigurer();

public :
	void InsertScene(Scene* scene);


private :
	std::vector<Scene*> m_pScenes;

	int m_currentLevel;
};

