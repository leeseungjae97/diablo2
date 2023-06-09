#pragma once
#include "_Engine.h"
#include "mGraphicDevice_Dx11.h"
#include "mShader.h"
#include "mMesh.h"
#include "mConstantBuffer.h"
#include "mCamera.h"

using namespace m::math;
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
		Matrix View;
		Matrix Projection;
	};
	CBUFFER(GridCB, CBSLOT_GRID)
	{
		Vector4 CameraPosition;
		Vector2 CameraScale;
		Vector2 Resolution;
	};
	//CBUFFER(AnimatorCB, CBSLOT_ANIMATOR)
	//{
	//	Vector2 leftTop;
	//	Vector2 size;
	//	Vector2 offset;
	//	Vector2 atlasSize;

	//	UINT type;
	//};

	extern m::graphics::ConstantBuffer* constantBuffers[(UINT)eCBType::END];

	extern Microsoft::WRL::ComPtr<ID3D11SamplerState> samplerState[];
	extern Microsoft::WRL::ComPtr<ID3D11RasterizerState> rasterizerStates[];
	extern Microsoft::WRL::ComPtr<ID3D11DepthStencilState> depthStencilStates[];
	extern Microsoft::WRL::ComPtr<ID3D11BlendState> blendStates[];

	extern m::Camera* mainCamera;
	extern std::vector<m::Camera*> cameras;
	extern std::vector<DebugMesh> debugMeshs;

	void Initialize();
	void Render();
	void Release();

	void PushDebugMeshAttribute(DebugMesh& mesh);
}
