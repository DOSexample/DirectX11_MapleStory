#include "jnsRutabysScene.h"
#include "CommonSceneInclude.h"
#include "jnsComputeShader.h"
#include "jnsPaintShader.h"
#include "jnsParticleSystem.h"
#include "jnsDamageControl.h"
#include "jnsAssainSkillParticle.h"
#include "jnsTomb.h"
#include "jnsYellowPortal.h"
#include "jnsSwallowEffect.h"
#include "jnsWeaponObject.h"
#include "jnsGenesisWeapon.h"
#include "jnsWeaponManager.h"

namespace jns
{
	RutabysScene::RutabysScene()
	{
	}
	RutabysScene::~RutabysScene()
	{
	}
	void RutabysScene::Initialize()
	{
		//std::shared_ptr<PaintShader> paintShader = Resources::Find<PaintShader>(L"PaintShader");
		//std::shared_ptr<Texture> paintTexture = Resources::Find<Texture>(L"PaintTexture");
		//paintShader->SetTarget(paintTexture);
		//paintShader->OnExcute();
		

		//{
		//	GameObject* player = new GameObject();
		//	player->SetName(L"Smile");
		//	AddGameObject(eLayerType::Monster, player);
		//	MeshRenderer* mr = player->AddComponent<MeshRenderer>();
		//	mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		//	mr->SetMaterial(Resources::Find<Material>(L"SpriteMaterial02"));
		//	player->GetComponent<Transform>()->SetPosition(Vector3(-200.0f, 100.0f, 1.0f));
		//	player->GetComponent<Transform>()->SetScale(Vector3(500.0f, 500.0f, 1.0f));
		//	Collider2D* cd = player->AddComponent<Collider2D>();
		//	//cd->SetSize(Vector2(1.2f, 1.2f));
		//	//player->AddComponent<PlayerScript>();
		//}
		object::Instantiate<Tomb>(jns::enums::eLayerType::Tomb, Vector3::Zero);
		object::InstantiateParticle<AssainSkillParticle>(jns::enums::eLayerType::Particle);
		//{
		//	GameObject* player = new GameObject();
		//	player->SetName(L"Particle");
		//	AddGameObject(eLayerType::Monster, player);
		//	ParticleSystem* mr = player->AddComponent<ParticleSystem>();
		//	player->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 1.0f));
		//	player->GetComponent<Transform>()->SetScale(Vector3(1500.0f, 1500.0f, 1.0f));
		//	//Collider2D* cd = player->AddComponent<Collider2D>();
		//	//cd->SetSize(Vector2(1.2f, 1.2f));
		//	//player->AddComponent<PlayerScript>();
		//}

		//ComputeShader* cs = new ComputeShader();
		//cs->Create(L"PaintCS.hlsl", "main");
		//Test for VSBinding ( uv ��ǥ ������ ���� �̹��� ��� ������ ����)
		
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Item, true);
		CollisionManager::SetLayer(eLayerType::Cursor, eLayerType::Item, true);
		CollisionManager::SetLayer(eLayerType::Cursor, eLayerType::UI, true);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Cursor, true);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Ground, true);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Portal, true);
		CollisionManager::SetLayer(eLayerType::Tomb, eLayerType::Ground, true);

#pragma region Ground
		
		// ���ٴ�
		object::InstantiateGroundCollider<Ground>(L"DownGround", Vector3(0.0f, -300.0f, 4.0f), Vector3(2500.0f, 100.0f, 1.0f));
		object::InstantiateGroundCollider<Ground>(L"LeftGround", Vector3(-1250.0f, -300.0f, 4.0f), Vector3(100.0f, 2500.0f, 1.0f));
		object::InstantiateGroundCollider<Ground>(L"RightGround", Vector3(1250.0f, -300.0f, 4.0f), Vector3(100.0f, 2500.0f, 1.0f));
		object::InstantiateGroundCollider<Ground>(L"Ladder", Vector3(446.0f, 0.0f, 4.0f), Vector3(20.0f, 430.0f, 1.0f));
		
#pragma endregion

		// �κ��丮
		Inventory* minven = object::InstantiateNOmove<Inventory>(eLayerType::UI);
		InventoryBG* minvenBG = object::InstantiateNOmove<InventoryBG>(eLayerType::UI);
		minvenBG->GetComponent<Transform>()->SetParent(minven->GetComponent<Transform>());

		// ��ųâ
		SkillUIBG* skillUIBG = object::InstantiateNOmove<SkillUIBG>(eLayerType::UI);
		object::InstantiateNOmove<SkillBox>(eLayerType::UI)->SetSkillUIBG(skillUIBG);
		object::InstantiateNOmove<SkillBox>(eLayerType::UI)->SetSkillUIBG(skillUIBG);
		object::InstantiateNOmove<SkillBox>(eLayerType::UI)->SetSkillUIBG(skillUIBG);
		object::InstantiateNOmove<SkillBox>(eLayerType::UI)->SetSkillUIBG(skillUIBG);
		object::InstantiateNOmove<SkillBox>(eLayerType::UI)->SetSkillUIBG(skillUIBG);
		object::InstantiateNOmove<SkillBox>(eLayerType::UI)->SetSkillUIBG(skillUIBG);
		object::InstantiateNOmove<SkillBox>(eLayerType::UI)->SetSkillUIBG(skillUIBG);
		object::InstantiateNOmove<SkillBox>(eLayerType::UI)->SetSkillUIBG(skillUIBG);
		
		object::InstantiateSkillBTN<SkillUIBTN>(eLayerType::UI, SkillUIBTN::eSkillUIBTN::One)->SetSkillUIBG(skillUIBG);
		object::InstantiateSkillBTN<SkillUIBTN>(eLayerType::UI, SkillUIBTN::eSkillUIBTN::Two)->SetSkillUIBG(skillUIBG);
		object::InstantiateSkillBTN<SkillUIBTN>(eLayerType::UI, SkillUIBTN::eSkillUIBTN::Three)->SetSkillUIBG(skillUIBG);
		object::InstantiateSkillBTN<SkillUIBTN>(eLayerType::UI, SkillUIBTN::eSkillUIBTN::Four)->SetSkillUIBG(skillUIBG);
		object::InstantiateSkillBTN<SkillUIBTN>(eLayerType::UI, SkillUIBTN::eSkillUIBTN::Five)->SetSkillUIBG(skillUIBG);

		// �÷��̾� ����
		GameObject* player = object::Instantiate<Player>(eLayerType::Player, Vector3(0.0f, 200.0f, 0.0f));
		PlayerScript* playerScript = player->GetComponent<PlayerScript>();
		playerScript->SetInventoryScript(minvenBG->GetComponent<InventoryScript>());
		SceneManager::SetPlayer(player);
		WeaponObject* weapon = object::Instantiate<WeaponObject>(eLayerType::MapEffect, Vector3::Zero);
		WeaponManager::AddWeapon(L"Genesis_Thief_Weapon", object::Instantiate<GenesisWeapon>(eLayerType::MapEffect, Vector3::Zero));
		weapon->GetComponent<Transform>()->SetParent(player->GetComponent<Transform>());
		weapon->SetPlayerScript(playerScript);
		// �÷��̾� �ϴ� ���� �� ��ų�� ���� ����


		// �׽�Ʈ ��ų
		JumpSkill* jump1 = object::InstantiateSkill<JumpSkill>(Vector3::Zero);
		JumpSkill* jump2 =  object::InstantiateSkill<JumpSkill>(Vector3::Zero);
		
		GameObject* obj1 = object::InstantiateSkill<AssainHit01>(Vector3::Zero);
		GameObject* obj2 = object::InstantiateSkill<AssainHit02>(Vector3::Zero);
		
		SkillManager::AddSkill(L"Normal_Assain_First_Attack", obj1);
		SkillManager::AddSkill(L"Normal_Assain_Second_Attack", obj2);
		SkillManager::AddSkill(L"Rogue_SkillflashJump_01", jump1);
		SkillManager::AddSkill(L"Rogue_SkillflashJump_02", jump2);

		// �׽�Ʈ ����
//		object::Instantiate<BloodyQueen>(eLayerType::Monster, Vector3(150.0f, -50.0f, 1.0f));



		// ��Ż
		object::InstantiatePortal<Portal>(L"RutaMob", Vector3(-1800.0f, 200.0f, 1.0f), Vector3(-763.0f, -190.0f, 0.0f));
		object::InstantiateDirPortal<YellowPortal>(L"RutaMob", Vector3(-2400.0f, 200.0f, 1.0f), Vector3(-1000.0f, -190.0f, 0.0f), 1);
		object::InstantiateDirPortal<YellowPortal>(L"RutaMob", Vector3(2400.0f, 200.0f, 1.0f), Vector3(1000.0f, -190.0f, 0.0f), -1);

		////object::InstantiateUIandBG<RutabysMain>(eLayerType::BG);
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(0.0f,   -141.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(-200.5f,-170.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(-450.0f,-190.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(-600.5f,-160.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(-850.0f, -180.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(-1000.0f,-130.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(-1200.0f,-160.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(-1450.5f,-150.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(-1600.0f,-130.0f, 4.9f));
		//object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(-1850.5f,-250.0f, 4.9f));
																		 
		//object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(0.0f, -201.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(250.5f, -150.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(400.0f, -140.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(600.5f, -200.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(850.5f, -180.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(1000.5f, -150.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(1200.0f, -160.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(1450.5f, -130.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(1600.0f, -120.0f, 4.9f));
		object::Instantiate<Smoke>(eLayerType::MapEffect, Vector3(1850.5f, -140.0f, 4.9f));
	

		// NoMove BackGround
		mBGInstance = object::InstantiateBG<BGInstance>(eLayerType::BG, BGInstance::eBGType::RutabysMain);
		//CreateInventory();
		CreatePlayerUI();
		PlayScene::Initialize();
	}
	void RutabysScene::Update()
	{
		PlayScene::Update();
	}
	void RutabysScene::LateUpdate()
	{
		PlayScene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::P))
		{
			SceneManager::LoadScene(L"RutabysMob");
		}
	}
	void RutabysScene::Render()
	{
		PlayScene::Render();
	}
	void RutabysScene::OnEnter()
	{
		PlayScene::OnEnter();
	}
	void RutabysScene::OnExit()
	{
		PlayScene::OnExit();
	}
}