#pragma once

class UpdateDispatcher
{
public:
	static void UpdateDispatch(std::function<EUpdateResult(void)> onUpdate, std::function<void(void)> onCompleted)
	{
		if (onUpdate == nullptr || onCompleted == nullptr)
		{
			// 넣을게 없으면 람다라도 넣거나
			// 아예 호출 ㄴㄴ
			assert(false);
		}
		updates.push_back(onUpdate);
		updateCompletes.push_back(onCompleted);
	}
	static void LateUpdateDispatch(std::function<EUpdateResult(void)> onLateUpdate, std::function<void(void)> onCompleted)
	{
		if (onLateUpdate == nullptr || onCompleted == nullptr)
		{
			// 넣을게 없으면 람다라도 넣거나
			// 아예 호출 ㄴㄴ
			assert(false);
		}
		lateUpdates.push_back(onLateUpdate);
		lateUpdateCompletes.push_back(onCompleted);
	}

	static void Update()
	{
		for (int i = 0; i < updates.size(); i++)
		{
			if (updates[i]() == EUpdateResult::Stop)
			{
				updateCompletes[i]();
				updates.erase(updates.begin() + i);
				updateCompletes.erase(updateCompletes.begin() + i);
			}
		}
	}
	static void LateUpdate()
	{
		for (int i = 0; i < lateUpdates.size(); i++)
		{
			if (lateUpdates[i]() == EUpdateResult::Stop)
			{
				lateUpdateCompletes[i]();
				lateUpdates.erase(lateUpdates.begin() + i);
				lateUpdateCompletes.erase(lateUpdateCompletes.begin() + i);
			}
		}
	}
private :
	static std::vector<std::function<EUpdateResult(void)>> updates;
	static std::vector<std::function<void(void)>> updateCompletes;

	static std::vector<std::function<EUpdateResult(void)>> lateUpdates;
	static std::vector<std::function<void(void)>> lateUpdateCompletes;


};

