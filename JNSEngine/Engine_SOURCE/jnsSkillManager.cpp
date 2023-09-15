#include "jnsSkillManager.h"
#include "..\\JNSEngine\\jnsSkillResources.h"

namespace jns
{
	std::unordered_map<std::wstring, GameObject*> SkillManager::mSkills;
	std::unordered_map<std::wstring, std::shared_ptr<SkillData>>  SkillManager::mSkillData;
	void SkillManager::Initialize()
	{
		// ���� ���Ŀ� �Ľ��� �ϰ� �ȴٸ� �̸��̵� �̷������� �����ؼ� ������ �����Ҽ� ������ �ʹ�. // ���� �� ��ȹ�� ������ ���Ŀ� ���� ������ �غ� ����
		mSkillData[L"Normal_Assain_First_Attack"] = std::make_shared<SkillData>(L"Normal_Assain_First_Attack", 10, 0.5f, 4, eKeyCode::NONE );
		mSkillData[L"Normal_Assain_Second_Attack"] = std::make_shared<SkillData>(L"Normal_Assain_Second_Attack", 10, 1.0f, 4, eKeyCode::NONE);
		mSkillData[L"BloodyMeso"] = std::make_shared<SkillData>(L"BloodyMeso", 5, 1.0f, 1, eKeyCode::NONE);
		mSkillData[L"Rogue_SkillflashJump_01"] = std::make_shared<SkillData>(L"Rogue_SkillflashJump_01", 0, 1.0f, 0, eKeyCode::NONE);
		mSkillData[L"Rogue_SkillflashJump_02"] = std::make_shared<SkillData>(L"Rogue_SkillflashJump_02", 0, 1.0f, 0, eKeyCode::NONE);
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

	std::shared_ptr<SkillData> SkillManager::FindSkillData(const std::wstring& key)
	{
		std::unordered_map<std::wstring, std::shared_ptr<SkillData>>::iterator iter
			= mSkillData.find(key);
		if (iter != mSkillData.end()) 
			return iter->second;
		
		return nullptr;
	}

	//
	void SkillManager::Release()
	{
		// �� Ÿ�ֿ̹� ���� ��������� ������ ���� �����ҵ���
		// ���̺� �ε�
		/*for (auto& mDatas : mSkillData)
		{
			delete mDatas.second;
			mDatas.second = nullptr;
		}
		mSkillData.clear();*/
	}

}