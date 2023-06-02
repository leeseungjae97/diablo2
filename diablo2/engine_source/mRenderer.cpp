#include "mRenderer.h"



namespace m::renderer
{
	vector<Vertex> vertexes;
	vector<UINT> indexes;

	// error blob
	//ID3DBlob* errorBlob = nullptr;

	m::Mesh* mesh = nullptr;
	m::Shader* shader = nullptr;

	// Input layout
	ID3D11InputLayout* triangleLayout = nullptr;
	ID3D11Buffer* triangleConstantBuffer = nullptr;

	// Vertex Buffer
	//ID3D11Buffer* triangleBuffer = nullptr;

	// Constant Buffer


	// Index Buffer
	//ID3D11Buffer* triangleIndexBuffer = nullptr;

	// Vertex Shader code -> Binary Code
	//ID3DBlob* triangleVSBlob = nullptr;

	// Vertex Shader
	//ID3D11VertexShader* triangleVSShader = nullptr;

	// Pixel Shader code -> Binary Code
	//ID3DBlob* trianglePSBlob = nullptr;

	// Pixel Shader
	//ID3D11PixelShader* trianglePSShader = nullptr;

	

	void SetupState()
	{

	}

	void LoadBuffer()
	{
		mesh = new m::Mesh();
		mesh->CreateVertexBuffer(vertexes.data(), 4);

		mesh->CreateIndexBuffer(indexes.data(), indexes.size());

		D3D11_BUFFER_DESC triangleCSDesc = {};
		triangleCSDesc.ByteWidth = sizeof(Vector4);
		triangleCSDesc.BindFlags = D3D11_BIND_FLAG::D3D11_BIND_CONSTANT_BUFFER;
		triangleCSDesc.Usage = D3D11_USAGE::D3D11_USAGE_DYNAMIC;
		triangleCSDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;

		m::graphics::GetDevice()->CreateBuffer(&triangleConstantBuffer, &triangleCSDesc, nullptr);
	}

	void LoadShader()
	{
		//m::graphics::GetDevice()->CreateShader();
		shader = new m::Shader();
		shader->Create(eShaderStage::VS, L"TriangleVS.hlsl", "main");
		shader->Create(eShaderStage::PS, L"TrianglePS.hlsl", "main");
	}

	void Initialize()
	{
		// triangle
		vertexes.resize(3);
		
		vertexes[0].pos = Vector3(0.0f, 0.5f, 0.0f);
		vertexes[0].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);

		vertexes[1].pos = Vector3(0.5f, -0.5f, 0.0f);
		vertexes[1].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

		vertexes[2].pos = Vector3(-0.5f, -0.5f, 0.0f);
		vertexes[2].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);

		indexes.push_back(0);
		indexes.push_back(1);
		indexes.push_back(2);

		// rhombus
		//vertexes.resize(4);
		//
		//vertexes[0].pos = Vector3(0.0f, 0.1f, 0.0f);
		//vertexes[0].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);

		//vertexes[1].pos = Vector3(0.1f, -0.1f, 0.0f);
		//vertexes[1].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

		//vertexes[2].pos = Vector3(-0.1f, -0.1f, 0.0f);
		//vertexes[2].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);
		//
		//vertexes[3].pos = Vector3(0.0f, -0.3f, 0.0f);
		//vertexes[3].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);

		//indexes.push_back(3);
		//indexes.push_back(2);
		//indexes.push_back(1);

		//indexes.push_back(0);
		//indexes.push_back(1);
		//indexes.push_back(2);
		 
		// rect
		//vertexes.resize(4);

		//vertexes[0].pos = Vector3(-0.1f, 0.1f, 0.0f);
		//vertexes[0].color = Vector4(1.0f, 0.0f, 0.0f, 1.0f);

		//vertexes[1].pos = Vector3(0.1f, 0.1f, 0.0f);
		//vertexes[1].color = Vector4(0.0f, 1.0f, 0.0f, 1.0f);

		//vertexes[2].pos = Vector3(0.1f, -0.1f, 0.0f);
		//vertexes[2].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);

		//vertexes[3].pos = Vector3(-0.1f, -0.1f, 0.0f);
		//vertexes[3].color = Vector4(0.0f, 0.0f, 1.0f, 1.0f);

		//indexes.push_back(0);
		//indexes.push_back(2);
		//indexes.push_back(3);

		//indexes.push_back(0);
		//indexes.push_back(1);
		//indexes.push_back(2);


		// circle, polygon
		/*Vertex center = {
			Vector3(0.0f, 0.0f, 0.0f) ,
			Vector4(0.0f, 1.0f, 0.0f, 1.0f)
		};

		vertexes.push_back(center);


		int iSlice = 80;
		float fRadius = 0.5f;
		float fTheta = (3.14159f * 2.f) / (float)iSlice;


		for (float i = 0; i < iSlice; i++)
		{
			Vertex circleLine = {
				Vector3(fRadius * cosf(fTheta * i)
					, fRadius * sinf(fTheta * i)
					, 0.0f),
				Vector4(0.0f, 1.0f, 0.0f, 1.f)
			};
			circleLine.pos.x -= (fRadius * cosf(fTheta * i)) / 2;
			vertexes.push_back(circleLine);
		}

		int j = 0;
		for (int i = vertexes.size() - 1; i >= 0; --i)
		{
			j++;
			indexes.push_back(i + 1);
			if (j == 2)
			{
				j = 0;
				indexes.push_back(1);
				i++;
			}
		}
		indexes.push_back(1);*/

		SetupState();
		LoadBuffer();
		LoadShader();
	}
	void Release()
	{
		if (triangleLayout != nullptr)
			triangleLayout->Release();

		if (triangleConstantBuffer != nullptr)
			triangleConstantBuffer->Release();

	}
}



