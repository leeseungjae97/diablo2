#pragma once
#include "mResource.h"
#include "mGraphics.h"
#include "mStructedBuffer.h"

namespace m::graphics
{
    class ComputeShader :
        public Resource
    {
	public:
		ComputeShader(int x, int y, int z);
		ComputeShader();
		virtual ~ComputeShader();

		bool Create(const std::wstring& name, const std::string& methodName);
		virtual HRESULT Load(const std::wstring& path) { return S_FALSE; };

		virtual void OnExcute();

		virtual void Binds();
		virtual void Clear();

	protected:
		Microsoft::WRL::ComPtr<ID3DBlob> mCSBlob;
		Microsoft::WRL::ComPtr<ID3D11ComputeShader> mCS;

		UINT mThreadGroupCountX;
		UINT mThreadGroupCountY;
		UINT mThreadGroupCountZ;

		UINT mGroupX;
		UINT mGroupY;
		UINT mGroupZ;
    };
}

