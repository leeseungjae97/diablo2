#include "mMonster.h"

#include "../engine_source/mMeshRenderer.h"
#include "../engine_source/mTime.h"

namespace m
{
	Monster::Monster(Vector3 iniPos)
		: prevPosition(iniPos)
		, destPosition(iniPos)
		, vS(iniPos)
		, fSpeed(200.f)
		, fStartDistance(0.f)
		, fRemainDistance(0.f)
	{
		SET_POS_VEC(this, iniPos);
		ADD_COMP(this, Collider2D);
		rangeCollider = ADD_COMP(this, Collider2D);
		rangeCollider->SetType(eColliderType::Circle);
		rangeCollider->SetSize(Vector3(10.f, 10.f, 10.f));

		ADD_COMP(this, MeshRenderer);
	}
	Monster::~Monster()
	{}
	void Monster::Initialize()
	{
		GameObject::Initialize();
	}
	void Monster::Update()
	{
		GameObject::Update();

		if (GetBattleState() == Dead
			|| GetBattleState() == Attack
			|| GetBattleState() == Cast) return;

		Vector3 curPosition = GET_POS(this);

		if (rangeCollider->GetOnStay())
		{
			prevPosition = GET_POS(this);

			destPosition = rangeCollider->GetCollideredObjectPos();

			float maxX = max(destPosition.x, prevPosition.x);
			float maxY = max(destPosition.y, prevPosition.y);

			float minX = min(destPosition.x, prevPosition.x);
			float minY = min(destPosition.y, prevPosition.y);

			fStartDistance = (Vector2(maxX, maxY) - Vector2(minX, minY)).Length();

			vDirection = destPosition - curPosition;
			vDirection.Normalize();
		}
		float maxX = max(curPosition.x, prevPosition.x);
		float maxY = max(curPosition.y, prevPosition.y);

		float minX = min(curPosition.x, prevPosition.x);
		float minY = min(curPosition.y, prevPosition.y);

		fRemainDistance = (Vector2(maxX, maxY) - Vector2(minX, minY)).Length();

		if (fRemainDistance < fStartDistance)
		{
			float fMoveX = curPosition.x + (vDirection.x * fSpeed * Time::fDeltaTime());
			float fMoveY = curPosition.y + (vDirection.y * fSpeed * Time::fDeltaTime());
			SET_POS_XYZ(this, fMoveX, fMoveY, curPosition.z);
		}
	}
	void Monster::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Monster::Render()
	{
		GameObject::Render();
	}
}