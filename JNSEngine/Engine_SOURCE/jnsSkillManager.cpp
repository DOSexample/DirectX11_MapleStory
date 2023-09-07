#include "jnsSkillManager.h"
#include "..\\JNSEngine\\jnsSkillResources.h"

namespace jns
{
	std::unordered_map<std::wstring, GameObject*> SkillManager::mSkills;
	std::unordered_map<std::wstring, SkillData*> SkillManager::mSkillData;
	void SkillManager::Initialize()
	{
		// ���� ���Ŀ� �Ľ��� �ϰ� �ȴٸ� �̸��̵� �̷������� �����ؼ� ������ �����Ҽ� ������ �ʹ�. // ���� �� ��ȹ�� ������ ���Ŀ� ���� ������ �غ� ����
		mSkillData[L"Normal_Assain_First_Attack"] = new SkillData{ L"Normal_Assain_First_Attack", 5, 0.5f, eKeyCode::NONE };
		mSkillData[L"Normal_Assain_Second_Attack"] = new SkillData{ L"Normal_Assain_Second_Attack", 5, 1.0f, eKeyCode::NONE };
		mSkillData[L"BloodyMeso"] = new SkillData{ L"BloodyMeso", 5, 1.0f, eKeyCode::NONE };
		mSkillData[L"Rogue_SkillflashJump_01"] = new SkillData{ L"Rogue_SkillflashJump_01", 0, 1.0f, eKeyCode::NONE };
		mSkillData[L"Rogue_SkillflashJump_02"] = new SkillData{ L"Rogue_SkillflashJump_02", 0, 1.0f, eKeyCode::NONE };
	}

	void SkillManager::AddSkill(const std::wstring& key, GameObject* skill)
	{
		mSkills.insert(std::make_pair(key, skill));
	}

	GameObject* SkillManager::FindSkill(const std::wstring& key)
	{
		std::unordered_map<std::wstring, GameObject*>::iterator iter
			= mSkills.find(key);
		
		if (iter != mSkills.end())
			return iter->second;


		return nullptr;
	}

	SkillData* SkillManager::FindSkillData(const std::wstring& key)
	{
		std::unordered_map<std::wstring, SkillData*>::iterator iter
			= mSkillData.find(key);
		if (iter != mSkillData.end()) 
			return iter->second;
		
		return nullptr;
	}

	void SkillManager::Release()
	{
		// ���̺� �ε�
		for (auto& mDatas : mSkillData)
		{
			delete mDatas.second;
			mDatas.second = nullptr;
		}
		mSkillData.clear();
	}

}