#include "jnsCameraScript.h"
#include "jnsTransform.h"
#include "jnsGameObject.h"
#include "jnsTime.h"
#include "jnsInput.h"
#include "jnsSceneManager.h"
#include "jnsCamera.h"

namespace jns
{
	void CameraScript::Update()
	{
		cameratr = GetOwner()->GetComponent<Transform>();
		//comp = GetOwner()->;

		if (true/*FollowTarget()*/)
		{

		}
		else
		{
		}

			pos = cameratr->GetPosition();
		

		if (Input::GetKey(eKeyCode::W))
		{
			pos.y += 5.0f * Time::DeltaTime();
			cameratr->SetPosition(pos);
		}
		else if (Input::GetKey(eKeyCode::S))
		{
			pos.y -= 5.0f * Time::DeltaTime();
			cameratr->SetPosition(pos);
		}
		else if (Input::GetKey(eKeyCode::A))
		{
			pos.x -= 5.0f * Time::DeltaTime();
			cameratr->SetPosition(pos);
		}
		else if (Input::GetKey(eKeyCode::D))
		{
			pos.x += 5.0f * Time::DeltaTime();
			cameratr->SetPosition(pos);
		}
		else if (Input::GetKey(eKeyCode::Q))
		{
			pos.z -= 5.0f * Time::DeltaTime();
			cameratr->SetPosition(pos);
		}
		else if (Input::GetKey(eKeyCode::E))
		{
			pos.z += 5.0f * Time::DeltaTime();
			cameratr->SetPosition(pos);
		}
	}

	//bool CameraScript::FollowTarget()
	//{
	//	//if (comp->GetCameraType() != jns::Camera::eCameraType::MainCamera)
	//	//	return false;

	//	//GameObject* checkTarget = comp->GetTarget();
	//	//
	//	//if (checkTarget == nullptr)
	//	//	return false;
	//	//
	//	//Transform* followTR = checkTarget->GetComponent<Transform>();
	//	//pos = followTR->GetPosition();

	//	//cameratr->SetPosition(Vector3(pos.x, pos.y, -10.0f));
	//	//return true;
	//}
}