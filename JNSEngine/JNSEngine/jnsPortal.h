#pragma once
#include "jnsPortalBase.h"

namespace jns
{
	class Portal : public PortalBase
	{
	public:
		Portal(std::wstring name, Vector3 setpos);
		~Portal();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();

	private:
	};

}
