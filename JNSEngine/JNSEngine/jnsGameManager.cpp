#include "jnsGameManager.h"


namespace jns
{
	int GameManager::deathCount;
	int GameManager::bossPlayTime;
	
	void GameManager::InitializeMapData()
	{
		// ����ī��Ʈ ����
		mapdata.deathcnt[jns::eSceneType::RutabysBoss] = 5;
		mapdata.deathcnt[jns::eSceneType::RutabysPierreBoss] = 5;

		// ���� �� �Ű��� ��� 
		mapdata.diedestination[jns::eSceneType::RutabysBoss] = jns::eSceneType::RutabysMain;
		mapdata.diedestination[jns::eSceneType::RutabysPierreBoss] = jns::eSceneType::RutabysMain;
	}
	void GameManager::SetDeathCount(int dcnt)
	{
		deathCount = dcnt;
	}

	int GameManager::GetDeathCount()
	{
		return deathCount;
	}

	void GameManager::SetBossPlayTime(int maxtime)
	{
		bossPlayTime = maxtime;
	}

	int GameManager::GetBossPlayTime()
	{
		return bossPlayTime;
	}

}