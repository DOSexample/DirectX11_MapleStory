#pragma once
#include "..\Engine_Source\jnsScene.h"


namespace jns
{
	class PlayScene : public Scene
	{
	public:
		PlayScene();
		virtual ~PlayScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

	

	protected:
		void CreateMainCamera();
		void CreateUICamera();
		void CreateGridCamera();
		void CreatePlayerUI();
		void CreateCursor();
		void CreateInventory();

	private:
		class Camera* maincameraComp;
	};
}
