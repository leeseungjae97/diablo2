#include "mSkill.h"

#include "../engine_source/mTileManager.h"
#include "../engine_source/mMonsterManager.h"
#include "../engine_source/mMeshRenderer.h"
#include "../engine_source/mGameObject.h"

#include "mMonster.h"
namespace m
{
	Skill::Skill(eSkillType type
		, Vector3 iniPos
		, bool useHitArea
		, bool useRange
		, bool useTilePos
		, bool useAstar
	)
		: MoveAbleObject(iniPos
			, 100.f
			, useHitArea
			, useRange
			, useTilePos
			, useAstar
		)
		, mSkillType(type)
		, bSkillFire(false)
		, bSkillCrash(false)

	{ 
	}
	Skill::~Skill()
	{
	}
	void Skill::Initialize()
	{
		GameObject::Initialize();
	}
	void Skill::Update()
	{
		GameObject::Update();
	}
	void Skill::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Skill::Render()
	{
		GameObject::Render();
	}
	void Skill::Hit(int damage)
	{
	}
}