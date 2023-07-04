#include "jnsRutabysScene.h"
#include "CommonSceneInclude.h"

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
		//Test for VSBinding ( uv ��ǥ ������ ���� �̹��� ��� ������ ����)
		{

			GameObject* player = new GameObject();
			player->SetName(L"Zelda");
			AddGameObject(eLayerType::Player, player);
			MeshRenderer* mr = player->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"SpriteMaterial"));
			player->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 1.0001f));
			//player->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 1.0f, 1.0001f));
			//player->AddComponent<ExpBarMoveScript>();
		}

		//Test for PS Binding ( uv ��ǥ ������ ���� �̹��� ���� ���� wrap ����(SamplerState) 
		{
			GameObject* player = new GameObject();
			player->SetName(L"Smile");
			AddGameObject(eLayerType::Player, player);
			MeshRenderer* mr = player->AddComponent<MeshRenderer>();
			mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			mr->SetMaterial(Resources::Find<Material>(L"SpriteMaterial02"));
			player->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
			player->GetComponent<Transform>()->SetRotation(Vector3(0.0f, 0.0f, 0.0f));
			player->GetComponent<Transform>()->SetScale(Vector3(1.0f, 1.0f, 1.0f));
			player->AddComponent<testScript>();
			//player->AddComponent<CameraScript>();
		}

		// NoMove BackGround
		object::InstantiateUIandBG<RutabysMain>(eLayerType::BG);

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
			SceneManager::LoadScene(L"RutabysBoss");
		}
	}
	void RutabysScene::Render()
	{
		PlayScene::Render();
	}
}