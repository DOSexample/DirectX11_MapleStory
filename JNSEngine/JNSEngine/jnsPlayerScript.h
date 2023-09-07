#pragma once
#include "jnsScript.h"
#include "jnsInput.h"
#include "jnsRigidbody.h"
#include "jnsScene.h"
#include "jnsSkillManager.h"

namespace jns
{
	class Animator;
	class InventoryScript;
	class PlayerScript : public Script
	{
	public:
		enum class ePlayerState
		{
			Idle,
			Move,
			Ladder,
			Jump,
			Prone,
			Attack,
			Hitted,
			Die,
			Attracted,
			End,
		};

		class eKeyType
		{
		public:
			eKeyCode Attack = eKeyCode::LCTRL;
			eKeyCode Jump = eKeyCode::C;
			eKeyCode Prone = eKeyCode::DOWN;
			eKeyCode MoveL = eKeyCode::LEFT;
			eKeyCode MoveR = eKeyCode::RIGHT;
			eKeyCode Skill = eKeyCode::F;
		};

		enum class PlayerDir
		{
			Left = -1,
			Right = 1,
		};

		struct PlayerInfo
		{
			float invisibilityTime;
			int hp;
			int mp;
			int exp;
			int mJumpCnt;
			float mJumpTime;
			float mJumpForce;
			bool isGrounded;
			bool isPlayPossible;
			bool isRight;
			float mDeathTime;
			float mHittedTime;
			float mMoveSpeed;
			PlayerDir mDir;     // �����϶� -1 �������϶� 1���� ������
			PlayerDir mPrevDir;
		};

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;

		virtual void OnCollisionEnter(Collider2D* other) override;
		virtual void OnCollisionStay(Collider2D* other) override;
		virtual void OnCollisionExit(Collider2D* other) override;

		eKeyCode GetPlayerClickButton() { return mClicked; }
		PlayerDir GetPlayerDirection() { return mPlayerInfo.mDir; }
		void SetPlayerDirection(PlayerDir dir) { mPlayerInfo.mDir = dir; }
		eKeyType GetPlayerKeyType() { return mPlayerKeyType; }
		void SetPlayerState(ePlayerState state) { mPlayerState = state; }
		ePlayerState GetPlayerState() { return mPlayerState; }
		void SetInventoryScript(InventoryScript* script) { mInventoryScript = script; }
		PlayerInfo GetPlayerInfo() { return mPlayerInfo; }
		void SetPlayerHp(int hp) { mPlayerInfo.hp = hp; }
		void SetPlayerMp(int mp) { mPlayerInfo.mp = mp; }
		void SetPlayerExp(int exp) { mPlayerInfo.exp = exp; }
		void SetIsNormalHit(bool isHit) { isNormalHit = isHit; }
		bool GetIsNormalHit() { return isNormalHit; }


	private:
		void CheckAttackSkills();
		void HpLerp();
		void OpenInventory();
		void BindConstantBuffer();
		void Idle();
		void Move();
		void Ladder();
		void Jump();
		void Prone();
		void Attack();
		void Hitted();
		void Die();
		void Attarct();
		void TurnOnLightWhenIHit();
		// �ִϸ��̼� �̺�Ʈ�� ���� ��ų ���� Ÿ�̹� ����
		void CompleteAssasinHit1();
		void CompleteAssasinHit2();
		void CompleteAnimation();
		void CompletePronStab();
		void CompleteRope();
		void InstantiateAssainHit1Skill();
		void InstantiateAssainHit2Skill();
		void InstantiateJumpSkill();

		void CheckJumpCount();

		void ActiveJumpSkill();
		void PlayerControl();
		void AnimatorControl();

		void Clear();
		void GetNewPosition();
		void CheckPlayerHp();
		void CheckPlayerIsGrounded();
		void CheckIsAssainHitUsed();
		void CheckInvisibleTime();
	private:
		GameObject* monster;


		struct PlayerStatus
		{
		};

		struct PlayerSkillInfo
		{
			bool isAssainHit1Used;
		};

		eKeyType mPlayerKeyType;

		Transform* tr;
		RigidBody* mRb;
		Animator* at;
		Collider2D* cd;
		
		PlayerInfo mPlayerInfo;
		PlayerSkillInfo mPlayerSkillInfo;
		ePlayerState mPlayerState = ePlayerState::Idle;
		ePlayerState mPrevPlayerState = ePlayerState::End;
		eKeyCode mClicked;
		
		InventoryScript* mInventoryScript;
		
		Scene* mPreveScene;
		Scene* mActveScene;
		
		int checktime;
		bool isAnimationDone;
		
		bool isDone;
		bool isChangedDir;
		bool wasStand = false;

		bool isLadderMoving = false;
		bool isLadderOn = false;

		bool isTombInstantiate = false;
		//int visitedAssainAttackTime = 0;

		int mPrevHp;
		bool checkInvisibleTime;
		float angle = 0.0; 
		bool isNotSetDeadPos = true;


		float centerX;
		float centerY;

		bool isNormalHit = false;
		bool isHpLerp = false;
		int destinationHp;
	};
}
