#include "mMonsterHand.h"

#include "MoveAbleObjectAnimLookUpTables.h"
#include "mGameObject.h"
#include "mMonster.h"
#include "mShadowObject.h"
#include "SkillAnimLookUpTables.h"

#include "../engine_source/mSceneManager.h"

namespace m
{
	MonsterHand::MonsterHand(Monster* parent, eMonsterType type, bool fh)
		: Hand(parent, fh)
		, mMonsterType(type)
		, mOwner(parent)
	{
		//Transform* fr = GET_COMP(this, Transform);
		//fr->SetParent(GET_COMP(parent, Transform));

		//ADD_COMP(this, Animator);
		//ADD_COMP(this, MeshRenderer);

		SET_MESH(this, L"RectMesh");
		SET_MATERIAL(this, L"AnimationMaterial");

		//mHandScript = ADD_COMP(this, HandScript);
		mHandScript = AddComponent<HandScript>(
			monsterHandSizes[(int)mMonsterType]
			, monsterOffsets[(int)mMonsterType]
			, monsterHandLength[(int)mMonsterType]
			, (int)MDDiablo::eAnimationType::End
			, fh ? monsterRHandNames[(int)mMonsterType] : monsterLHandNames[(int)mMonsterType]
			);
		fh ? mHandScript->RightHand() : mHandScript->LeftHand();

		SET_SCALE_XYZ(this,
			100.f, 100.f, 1.f);

		mShadow = new ShadowObject(this);
		SceneManager::GetActiveScene()->AddGameObject(eLayerType::Shadow, mShadow);
	}

	MonsterHand::~MonsterHand()
	{
		//if (mShadow)
		//	mShadow->SetState(eState::Delete);
	}

	void MonsterHand::Update()
	{
		Hand::Update();
		if (mShadow && nullptr == mShadow->GetCamera()) mShadow->SetCamera(GetCamera());
		mShadow->SetShadowOffset(monsterOffsets[(int)mMonsterType][mHandScript->GetHandDirection()]);

		if (mOwner->GetBattleState() == eBattleState::ToDead)
		{
			SetState(Delete);
			return;
		}

		Vector3 pos = GET_POS(mOwner);
		
		pos.y += mOwner->GetCenterPosY();
		
		int direction = mHandScript->GetHandDirection();

		if(mHandScript->GetRightHand())
		{
			if (direction == (int)ePathSixteenDirection::Left
				|| direction == (int)ePathSixteenDirection::LeftUp1
				|| direction == (int)ePathSixteenDirection::LeftUp2
				|| direction == (int)ePathSixteenDirection::LeftUp3
				|| direction == (int)ePathSixteenDirection::RightDown1
				|| direction == (int)ePathSixteenDirection::RightDown2
				|| direction == (int)ePathSixteenDirection::RightDown3
				|| direction == (int)ePathSixteenDirection::Up)
			{
				//if (pos.z == 1.f) pos.z += 0.00001f;
				pos.z += 0.0001f;
			}
			else
			{
				//if (pos.z > 1.f) pos.z -= 0.00001f;;
				pos.z -= 0.0001f;;
			}
		}

		SET_POS_VEC(this, pos);
	}

	void MonsterHand::LateUpdate()
	{
		Hand::LateUpdate();
	}

	void MonsterHand::Render()
	{
		Hand::Render();
	}

	void MonsterHand::Initialize()
	{
		Hand::Initialize();
	}

	void MonsterHand::SetDirection(int direction)
	{
		mHandScript->SetHandDirection(direction);
	}

	void MonsterHand::SetAniType(int aniType)
	{
		mHandScript->SetHandAnimation(aniType);
	}
}
