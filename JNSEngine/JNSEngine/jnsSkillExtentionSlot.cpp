#include "jnsSkillExtentionSlot.h"
#include "CommonUIInclude.h"

namespace jns
{
	SkillExtentionSlot::SkillExtentionSlot()
	{
	}
	SkillExtentionSlot::~SkillExtentionSlot()
	{
	}
	void SkillExtentionSlot::Initialize()
	{
		mr = GetComponent<MeshRenderer>();
		mr->SetMaterial(Resources::Find<Material>(L"SkillSlotExtensionMaterial"));
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mTextureRatio = GetComponent<MeshRenderer>()->GetMaterial()->GetTexture()->GetTextureRatio();
		tr = GetComponent<Transform>();
		tr->SetPosition(Vector3(-0.505, 0.0f, -0.2f)); // �̹漺 ���͸��� �´����� ���� ���� + 0.2 �� -0.2 �� �������� ������ ���� �ű�汸
		tr->SetScale(Vector3(0.02f, 1.0f, 1.0f));
		UIBase::Initialize();
	}
	void SkillExtentionSlot::Update()
	{
		UIBase::Update();
	}
	void SkillExtentionSlot::LateUpdate()
	{
		UIBase::LateUpdate();
	}
	void SkillExtentionSlot::Render()
	{
		UIBase::Render();
	}
}