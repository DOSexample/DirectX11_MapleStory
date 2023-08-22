#include "jnsRutabysBossScene.h"
#include "CommonSceneInclude.h"
#include "jnsMirror.h"
#include "jnsHeart.h"
#include "jnsDarkPaper.h"
namespace jns
{
	RutabysBossScene::RutabysBossScene()
	{
	}
	RutabysBossScene::~RutabysBossScene()
	{
	}
	void RutabysBossScene::Initialize()
	{
		mBGInstance = object::InstantiateBG<BGInstance>(eLayerType::BG, BGInstance::eBGType::RutabysQueenBoss);
		object::InstantiateGroundCollider<Ground>(L"DownGround", Vector3(0.0f, -450.0f, 4.0f), Vector3(5000.0f, 110.0f, 1.0f));
		object::InstantiateGroundCollider<Ground>(L"LeftGround", Vector3(-1250.0f, -300.0f, 4.0f), Vector3(100.0f, 2500.0f, 1.0f));
		object::InstantiateGroundCollider<Ground>(L"RightGround", Vector3(1250.0f, -300.0f, 4.0f), Vector3(100.0f, 2500.0f, 1.0f));
		
		object::Instantiate<Heart>(eLayerType::Monster, Vector3::Zero);
		object::Instantiate<Heart>(eLayerType::Monster, Vector3::Zero);
		object::Instantiate<Heart>(eLayerType::Monster, Vector3::Zero);
		object::Instantiate<Heart>(eLayerType::Monster, Vector3::Zero);
		object::Instantiate<Heart>(eLayerType::Monster, Vector3::Zero);
		object::Instantiate<Heart>(eLayerType::Monster, Vector3::Zero);
		object::Instantiate<Heart>(eLayerType::Monster, Vector3::Zero);
		object::Instantiate<Heart>(eLayerType::Monster, Vector3::Zero);
		object::Instantiate<Heart>(eLayerType::Monster, Vector3::Zero);
		object::Instantiate<Heart>(eLayerType::Monster, Vector3::Zero);
		object::Instantiate<Heart>(eLayerType::Monster, Vector3::Zero);
		object::Instantiate<Heart>(eLayerType::Monster, Vector3::Zero);
		object::Instantiate<Heart>(eLayerType::Monster, Vector3::Zero);
		object::Instantiate<Heart>(eLayerType::Monster, Vector3::Zero);
		object::Instantiate<Heart>(eLayerType::Monster, Vector3::Zero);
		object::Instantiate<Heart>(eLayerType::Monster, Vector3::Zero);
		object::Instantiate<Heart>(eLayerType::Monster, Vector3::Zero);
		object::Instantiate<Heart>(eLayerType::Monster, Vector3::Zero);

		object::Instantiate<DarkPaper>(eLayerType::BG, Vector3::Zero);
		// ����
		GameObject* obj = object::Instantiate<BloodyQueen>(eLayerType::Monster, Vector3(150.0f, -130.0f, 3.0f));
		BloodyQueenScript* bqScript = obj->GetComponent<BloodyQueenScript>();
		Mirror* mirror = object::Instantiate<Mirror>(eLayerType::Monster, Vector3(-150.0f, -300.0f, 2.0f));
		bqScript->SetMirror(mirror);
		//player = object::Instantiate<Player>(eLayerType::Player, Vector3(0.0f, 0.0f, 1.0001f));
		CreatePlayerUI();
		PlayScene::Initialize();
	}
	void RutabysBossScene::Update()
	{
		PlayScene::Update();
	}
	void RutabysBossScene::LateUpdate()
	{
		PlayScene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::P))
		{
			SceneManager::LoadScene(L"Login");
		}
	}
	void RutabysBossScene::Render()
	{
		PlayScene::Render();
	}
	void RutabysBossScene::OnEnter()
	{
		PlayScene::OnEnter();
	}
	void RutabysBossScene::OnExit()
	{
		PlayScene::OnExit();
	}
}