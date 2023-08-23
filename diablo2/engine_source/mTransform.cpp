#include "mTransform.h"
#include "mRenderer.h"
#include "mConstantBuffer.h"
#include "mCamera.h"
#include "mGameObject.h"

namespace m
{
	Transform::Transform()
		: Component(eComponentType::Transform)
		, mPosition(Vector3::Zero)
		, mRotation(Vector3::Zero)
		, mScale(Vector3::One)
		, mFoward(Vector3::Forward)
		, mRight(Vector3::Right)
		, mUp(Vector3::Up)
	{}

	Transform::~Transform()
	{}

	void Transform::Initialize()
	{}

	void Transform::Update()
	{}

	void Transform::LateUpdate()
	{
		mWorld = Matrix::Identity;
		for(Collider2D* col : GetOwner()->GetComponents<Collider2D>())
		{
			if(col->GetColliderFunctionType() == eColliderFunctionType::TilePos)
			{
				col->SetCenter(Vector2(0.f, -mScale.y / 2.f));
				break;
			}
		}
		Matrix scale = Matrix::CreateScale(mScale);

		Matrix rotation;
		//if (mParent)
		//{
		//	rotation = Matrix::CreateRotationX(mParent->mRotation.x);
		//	rotation *= Matrix::CreateRotationY(mParent->mRotation.y);
		//	rotation *= Matrix::CreateRotationZ(mParent->mRotation.z);
		//}
		//else
		//{
		//	rotation = Matrix::CreateRotationX(mRotation.x);
		//	rotation *= Matrix::CreateRotationY(mRotation.y);
		//	rotation *= Matrix::CreateRotationZ(mRotation.z);
		//}

		rotation = Matrix::CreateRotationX(mRotation.x);
		rotation *= Matrix::CreateRotationY(mRotation.y);
		rotation *= Matrix::CreateRotationZ(mRotation.z);

		Matrix position;
		position.Translation(mPosition);

		mWorld = scale * rotation * position;

		mUp = Vector3::TransformNormal(Vector3::Up, rotation);
		mFoward = Vector3::TransformNormal(Vector3::Forward, rotation);
		mRight = Vector3::TransformNormal(Vector3::Right, rotation);

		if (mParent) { mWorld *= mParent->mWorld; }
	}

	void Transform::Render()
	{

	}

	void Transform::BindConstantBuffer()
	{
		renderer::TransformCB trCB = {};
		trCB.mWorld = mWorld;
		trCB.View = Camera::GetViewMatrix();
		trCB.Projection = Camera::GetProjectionMatrix();

		ConstantBuffer* cb = renderer::constantBuffers[(UINT)eCBType::Transform];
		
		cb->SetData(&trCB);
		cb->Bind(eShaderStage::VS);
		cb->Bind(eShaderStage::HS);
		cb->Bind(eShaderStage::DS);
		cb->Bind(eShaderStage::GS);
		cb->Bind(eShaderStage::PS);
		cb->Bind(eShaderStage::CS);
	}
}
