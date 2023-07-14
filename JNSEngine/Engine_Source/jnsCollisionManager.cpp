#include "jnsCollisionManager.h"
#include "jnsGameObject.h"
#include "jnsScene.h"
#include "jnsSceneManager.h"
#include "jnsLayer.h"
#include "jnsCollider2D.h"

namespace jns
{
	std::bitset<LAYER_MAX> CollisionManager::mMatrix[LAYER_MAX] = {};
	std::map<UINT64, bool>CollisionManager::mCollisionMap = {};

	void CollisionManager::Initialize()
	{
	}
	void CollisionManager::Update()
	{
		for (UINT column = 0; column < (UINT)eLayerType::End; column++)
		{
			for (UINT row = 0; row < (UINT)eLayerType::End; row++)
			{
				if (mMatrix[column][row] == true)
				{
					LayerCollision((eLayerType)column, (eLayerType)row);
				}
			}
		}
	}
	void CollisionManager::LayerCollision(eLayerType left, eLayerType right)
	{
		Scene* activeScene = SceneManager::GetActiveScene();

		const std::vector<GameObject*>& lefts
			= activeScene->GetLayer(left).GetGameObjects();
		const std::vector<GameObject*>& rights
			= activeScene->GetLayer(right).GetGameObjects();

		for (GameObject* leftObj : lefts)
		{
			Collider2D* leftCol = leftObj->GetComponent<Collider2D>();

			if (leftCol == nullptr)
				continue;
			if (leftObj->GetState()
				!= GameObject::eState::Active)
				continue;

			for (GameObject* rightObj : rights)
			{
				Collider2D* rightCol = rightObj->GetComponent<Collider2D>();
				if (rightCol == nullptr)
					continue;
				if (leftObj == rightObj)
					continue;
				if (rightObj->GetState()
					!= GameObject::eState::Active)
					continue;

				ColliderCollision(leftCol, rightCol);
			}
		}


	}
	void CollisionManager::ColliderCollision(Collider2D* left, Collider2D* right)
	{	
		// �� �浹ü�� ID bool���� Ȯ��
		ColliderID id = {};
		id.left = left->GetColliderID();
		id.right= right->GetColliderID();

		// �浹 ������ �����´�
		std::map<UINT64, bool>::iterator iter
			= mCollisionMap.find(id.id);

		if (iter == mCollisionMap.end())
		{
			mCollisionMap.insert(std::make_pair(id.id, false));
			iter = mCollisionMap.find(id.id);
		}

		if (Intersect(left, right))
		{
			// �浹
			if (iter->second == false)
			{
				// �����浹
				left->OnCollisionEnter(right);
				right->OnCollisionEnter(left);
			}
			else
			{
				// �浹 ��
				left->OnCollisionStay(right);
				right->OnCollisionStay(left);
			}
		}
		else
		{
			// �浹 X
			if (iter->second == true)
			{
				// �浹�ϰ� �ִٰ� ������
				left->OnCollisionExit(right);
				right->OnCollisionExit(left);
			}
		}
	
	}
	bool CollisionManager::Intersect(Collider2D* left, Collider2D* right)
	{		
		if (left == nullptr || right == nullptr)
			return false;


		const Vector3& leftColCenterPos = left->GetPosition();
		const Vector3& righColCentertPos = right->GetPosition();

		Vector3 colPosDiff = leftColCenterPos - righColCentertPos;

		Vector3 leftColR = left->GetOwner()->GetComponent<Transform>()->Right();
		Vector3 leftColUp = left->GetOwner()->GetComponent<Transform>()->Up();
		Vector3 rightColR = right->GetOwner()->GetComponent<Transform>()->Right();
		Vector3 rightColUp = right->GetOwner()->GetComponent<Transform>()->Up();
		
		Vector3 leftColLocalScale = left->GetOwner()->GetComponent<Transform>()->GetScale();
		Vector3 rightColLocalScale = right->GetOwner()->GetComponent<Transform>()->GetScale();
		
		leftColR *= leftColLocalScale.x / 2;
		leftColUp *= leftColLocalScale.y / 2;
		rightColR *= rightColLocalScale.x / 2;
		rightColUp *= rightColLocalScale.y / 2;
		//CheckSplitShaft(collisionInfo.leftColRight, colPosDiff, collisionInfo);
		//CheckSplitShaft(collisionInfo.rightColRight, colPosDiff, collisionInfo);
		//CheckSplitShaft(collisionInfo.leftColUp, colPosDiff, collisionInfo);
		//CheckSplitShaft(collisionInfo.rightColUp, colPosDiff, collisionInfo);
		// �׸� �׸� �浹
		// �и��� �̷�
		std::vector<Vector3> checkPos = {};
		checkPos.push_back(leftColR);
		checkPos.push_back(leftColUp);
		checkPos.push_back(rightColR);
		checkPos.push_back(rightColUp);

		for (int i = 0; i < 4; i++)
		{
			float colDistance = abs((checkPos[i].Dot(colPosDiff)));

			if (colDistance > abs(checkPos[i].Dot(leftColR))
				+ abs(checkPos[i].Dot(leftColUp))
				+ abs(checkPos[i].Dot(rightColR))
				+ abs(checkPos[i].Dot(rightColUp)))
				return false;
		}
		
		

		// To do... (����)
		// �и����� ��ƴ� �Ͻôºе���
		// �� - �� �浹

		//math::

		return true;
	}
	void CollisionManager::SetLayer(eLayerType left, eLayerType right, bool enable)
	{
		UINT row = -1;
		UINT col = -1;

		UINT mLeft = (UINT)left;
		UINT mRight = (UINT)right;

		if (mLeft <= mRight)
		{
			row = mLeft;
			col = mRight;
		}
		else
		{
			row = mRight;
			col = mLeft;
		}

		mMatrix[col][row] = enable; 

	}
	void CollisionManager::Clear()
	{
		mMatrix->reset();
		mCollisionMap.clear();
	}




}