#include "jnsCameraScript.h"
#include "jnsTransform.h"
#include "jnsGameObject.h"
#include "jnsTime.h"
#include "jnsInput.h"
#include "jnsSceneManager.h"
#include "jnsCamera.h"
#include "jnsCameraObject.h"

namespace jns
{
	void CameraScript::Initialize()
	{
		playerPrevPos = Vector3::Zero;
		cameraPrevPos = Vector3::Zero;
		setYCord = 200.0f;
	}
	void CameraScript::Update()
	{
		cameratr = GetOwner()->GetComponent<Transform>();
		//comp = GetOwner()->;

		if (FollowTarget())
		{

		}
		else
		{
			pos = cameratr->GetPosition();
		}

		

		if (Input::GetKey(eKeyCode::W))
		{
			pos.y += 255.0f * Time::DeltaTime();
			cameratr->SetPosition(pos);
		}
		else if (Input::GetKey(eKeyCode::S))
		{
			pos.y -= 255.0f * Time::DeltaTime();
			cameratr->SetPosition(pos);
		}
		else if (Input::GetKey(eKeyCode::A))
		{
			pos.x -= 255.0f * Time::DeltaTime();
			cameratr->SetPosition(pos);
		}
		else if (Input::GetKey(eKeyCode::D))
		{
			pos.x += 255.0f * Time::DeltaTime();
			cameratr->SetPosition(pos);
		}
		else if (Input::GetKey(eKeyCode::Q))
		{
			pos.z -= 255.0f * Time::DeltaTime();
			cameratr->SetPosition(pos);
		}
		else if (Input::GetKey(eKeyCode::E))
		{
			pos.z += 255.0f * Time::DeltaTime();
			cameratr->SetPosition(pos);
		}
	}

	bool CameraScript::FollowTarget()
	{
		GameObject* mCamera = this->GetOwner();
		CameraObject* mMainCamera = dynamic_cast<CameraObject*>(mCamera);
		GameObject* checkTarget = mMainCamera->GetFollowTarget();
		
		if (checkTarget == nullptr)
			return false;
		

		// �÷��̾� �ֽ� ��ġ�� �ҷ��´�.
		Transform* followTR = checkTarget->GetComponent<Transform>();
		Vector3 playerPos = followTR->GetPosition();
		float followSpeed = 4.0f;

		// ī�޶� ��ġ ���� ������ ��Ų��.
		Vector3 targetCameraPos = playerPos + Vector3(0.0f, setYCord, -10.0f);
		Vector3 interpolatedCameraPos = Vector3::Lerp(cameraPrevPos, targetCameraPos, followSpeed * Time::DeltaTime());
		

		// ī�޶� z���� �ٽ� -10���� �ٲ��ش�. UIī�޶�� ȥ������ ���߸��� �ȵǱ� ������.
		interpolatedCameraPos.z = -10.0f;

		// ī�޶� ���� ���� ��Ų ��ġ�� �̵� ��Ų��.
		cameratr->SetPosition(interpolatedCameraPos);


		playerPrevPos = playerPos;
		cameraPrevPos = interpolatedCameraPos;

		return true;
	}
}

