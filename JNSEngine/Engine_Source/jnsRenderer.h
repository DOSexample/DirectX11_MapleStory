#pragma once
#include "JNSEngine.h"
#include "jnsGraphicDevice_Dx11.h"
#include "jnsMesh.h"
#include "jnsShader.h"
#include "jnsConstantBuffer.h"

using namespace jns::math;
using namespace jns::graphics;
namespace renderer
{
	struct Vertex
	{
		Vector3 pos;
		Vector4 color;
		Vector2 uv;
	};

	CBUFFER(TransformCB, CBSLOT_TRANSFORM)
	{
		Matrix mWorld;
		Matrix mView;
		Matrix mProjection;
	};

	extern Vertex vertexes[];
	extern jns::graphics::ConstantBuffer* constantBuffer[(UINT)eCBType::End];

	void Initialize();
	void Release();


}
