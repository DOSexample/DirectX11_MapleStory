#pragma once
#include "jnsScript.h"
#include "jnsInput.h"
#include "jnsRigidbody.h"
#include "jnsScene.h"

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
			Jump,
			Prone,
			Attack,
			Hitted,
			Die,
			End,
		};

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;

		virtual void OnCollisionEnter(Collider2D* other) override;
		virtual void OnCollisionStay(Collider2D* other) override;
		virtual void OnCollisionExit(Collider2D* other) override;


		void bindConstantBuffer();

	public:
		void Idle();
		void Move();
		void Jump();
		void Prone();
		void Attack();
		void Hitted();
		void Die();

		void CompleteAssasinHit1();
		void CompleteAnimation();
		void CompletePronStab();
		
		void AnimatorControl();
		void SetInventoryScript(InventoryScript* script) { mInventoryScript = script; }

		void Clear();
		void CheckPlayerIsGrounded();

		
	private:
		struct PlayerInfo
		{
			int mJumpCnt;
			float mJumpTime;
			float mJumpForce;
			bool isGrounded;
			bool isPlayed;
			bool isRight;
			float mDeathTime;
			float mHittedTime;
			float mMoveSpeed;
			int LeftRight;     // 왼쪽일때 -1 오른쪽일때 1값이 들어가도록
		};

		RigidBody* mRb;
		PlayerInfo mPlayerInfo;
		ePlayerState mPlayerState;
		ePlayerState mPrevPlayerState = ePlayerState::End;
		InventoryScript* mInventoryScript;
		Animator* at;
		Scene* mPreveScene;
		Scene* mActveScene;
		bool isAnimationDone;
		eKeyCode mClicked;
		int checktime;
		int i = 0;
		bool isDone;
	};
}
