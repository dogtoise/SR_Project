#pragma once
#include "StandardEngineFramework.h"

namespace BattleEvent
{
	static const std::string KillEnemy = "BattleEvent.KillEnemy";
	static const std::string KillBoss = "BattleEvent.KillBoss";
}

namespace SceneEvent
{
	static const std::string Transition = "SceneEvent.Transition";
}

namespace GameEvent
{
	static const std::string BossAppear = "GameEvent.BossAppear";
	static const std::string BossCaution = "GameEvent.BossCaution";
	static const std::string BossDie = "GameEvent.BossDie";
	static const std::string PlayerDie = "GameEvent.PlayerDie";
}
