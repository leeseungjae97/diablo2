#include "mCollider2D.h"
#include "mGameObject.h"
#include "mRenderer.h"
#include "mGraphics.h"
#include "mMeshRenderer.h"

namespace m
{
	UINT Collider2D::mColliderNumber = 0;
	Collider2D::Collider2D()
		: Component(eComponentType::Collider2D)
		, mTransform(nullptr)
		, mSize(Vector3::One)
		, mCenter(Vector2::Zero)
		, mScale(Vector3::One)
		, mType(eColliderType::Rect)
		, mColor(eColor::Green)
		, bOnEnter(false)
		, bOnStay(false)
		, bOnExit(false)
		, intersectColliderNumber(0)
	{
		mColliderNumber++;
		mColliderID = mColliderNumber;
	}
	Collider2D::~Collider2D()
	{}
	void Collider2D::Initialize()
	{
	}
	void Collider2D::Update()
	{}
	void Collider2D::LateUpdate()
	{
		Component::LateUpdate();

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector3 scale = tr->GetScale();
		if (mScale == Vector3::One)
		{
			if (mType == eColliderType::Circle)
			{
				scale.x = scale.y;
			}
			scale.x *= mSize.x;
			scale.y *= mSize.y;
			mScale = scale;
		}
	
		mRotation = tr->GetRotation();
		

		Vector3 pos = tr->GetPosition();
		pos.x += mCenter.x;
		pos.y += mCenter.y;

		mPosition = pos;

		Camera* camera = GetOwner()->GetCamera();

		DebugMesh debugMesh = {};
		debugMesh.position = pos;
		debugMesh.scale = mScale;
		debugMesh.rotation = mRotation;
		debugMesh.type = mType;
		debugMesh.view = camera->GetPrivateViewMatrix();
		debugMesh.projection = camera->GetPrivateProjectionMatrix();
		debugMesh.color = mColor;
		GetOwner()->GetState() != GameObject::RenderUpdate ? debugMesh.visible = false : debugMesh.visible = true;

		renderer::PushDebugMeshAttribute(debugMesh);
	}
	void Collider2D::Render()
	{}

	void Collider2D::OnCollisionEnter(Collider2D* other)
	{
		if (std::find(exceptTypes.begin(), exceptTypes.end(), other->GetOwner()->GetLayerType()) != exceptTypes.end()) 
			return;

		collideredObjects.push_back(other->GetOwner());
		intersectColliderNumber++;
		collideredObjectPos = other->GetOwner()->GetComponent<Transform>()->GetPosition();
		bOnEnter = true;
		bOnStay = bOnExit = false;
		const std::vector<Script*>& scripts
			= GetOwner()->GetScripts();

		for (Script* script : scripts)
		{
			script->OnCollisionEnter(other);
		}
	}
	void Collider2D::OnCollisionStay(Collider2D* other)
	{
		if (std::find(exceptTypes.begin(), exceptTypes.end(), other->GetOwner()->GetLayerType()) != exceptTypes.end())
			return;

		collideredObjectPos = other->GetOwner()->GetComponent<Transform>()->GetPosition();
		bOnStay = true;
		bOnEnter = bOnExit = false;
		const std::vector<Script*>& scripts
			= GetOwner()->GetScripts();

		for (Script* script : scripts)
		{
			script->OnCollisionStay(other);
		}
	}
	void Collider2D::OnCollisionExit(Collider2D* other)
	{
		if (std::find(exceptTypes.begin(), exceptTypes.end(), other->GetOwner()->GetLayerType()) != exceptTypes.end())
			return;

		std::erase(collideredObjects, other->GetOwner());

		intersectColliderNumber--;
		bOnExit = true;
		bOnStay = bOnEnter = false;
		const std::vector<Script*>& scripts
			= GetOwner()->GetScripts();

		for (Script* script : scripts)
		{
			script->OnCollisionExit(other);
		}
	}
}