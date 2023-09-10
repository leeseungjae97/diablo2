#include "mFallScript.h"

#include "mSkill.h"
#include "mMonster.h"

namespace m
{
	FallScript::FallScript(eAccessorySkillType type)
		: mACType(type)
		, bSkillFire(false)
		, bArrival(false)
	{
	}
	FallScript::~FallScript()
	{
	}
	void FallScript::Initialize()
	{
		mAnimator = GET_COMP(GetOwner(), Animator);
		
		Skill* dSkill = dynamic_cast<Skill*>(GetOwner());
		if (nullptr == dSkill) mType = eSkillType::normalAttack;
		else mType = dSkill->GetSkillType();

		eSkillCrashType crashType;
		if (mACType == eAccessorySkillType::END)
		{
			crashType = skillCrashTypes[(int)mType];
			SHARED_MAT mat = RESOURCE_FIND(Material, skillAnimNames[(int)mType]);
			mAnimator->Create(
				skillAnimNames[(int)mType] + L"anim"
				, mat->GetTexture()
				, Vector2::Zero
				, skillSizes[(int)mType]
				, skillAnimLength[(int)mType]
				, Vector2::Zero
				, 0.03f
			);
			
			SHARED_MAT crashMat = RESOURCE_FIND(Material, crashNames[(int)crashType]);
			mAnimator->Create(
				crashNames[(int)crashType] + L"anim"
				, crashMat->GetTexture()
				, Vector2::Zero
				, crashSizes[(int)crashType]
				, crashLength[(int)crashType]
				, Vector2::Zero
				, 0.03f
			);
		}
		else
		{
			
			SHARED_MAT mat = RESOURCE_FIND(Material, accessorySkillNames[(int)mACType]);
			mAnimator->Create(
				accessorySkillNames[(int)mACType] + L"anim"
				, mat->GetTexture()
				, Vector2::Zero
				, accessorySkillAnimSize[(int)mACType]
				, accessorySkillAnimLength[(int)mACType]
				, Vector2::Zero
				, 0.03f
			);
			
			crashType = accessorySkillCrashTypes[(int)mACType];
			if (crashType != eSkillCrashType::END)
			{
				SHARED_MAT crashMat = RESOURCE_FIND(Material, crashNames[(int)crashType]);
				mAnimator->Create(
					crashNames[(int)crashType] + L"anim"
					, crashMat->GetTexture()
					, Vector2::Zero
					, crashSizes[(int)crashType]
					, crashLength[(int)crashType]
					, Vector2::Zero
					, 0.03f
				);
			}
		}
		if (crashType != eSkillCrashType::END)
		{
			mAnimator->StartEvent(crashNames[(int)crashType] + L"anim") = [this]()
			{
				Vector3 mPos = GET_POS(GetOwner());
				mPos.y -= 45.f;
				mPos.x += 20.f;
				SET_POS_VEC(GetOwner(), mPos);
			};
			mAnimator->EndEvent(crashNames[(int)crashType] + L"anim") = [this]()
			{
				Collider2D* col = GetOwner()->GetComponent<Collider2D>();
				if (col->GetOnStay())
				{
					for (Collider2D* otherCol : col->GetCollidereds())
					{
						if (otherCol->GetColliderFunctionType() == eColliderFunctionType::HitArea)
						{
							Monster* monster = dynamic_cast<Monster*>(otherCol->GetOwner());
							if (nullptr != monster)
								monster->Hit(10);
						}
					}
				}
				GetOwner()->SetState(GameObject::eState::Delete);
			};
		}
		
		SHARED_MAT noneMat = RESOURCE_FIND(Material, L"noneRect");
		mAnimator->Create(
			L"noneRectAnim"
			, noneMat->GetTexture()
			, Vector2::Zero
			, Vector2(20.f, 20.f)
			, 1
			, Vector2::Zero
			, 0.03f
		);

		mAnimator->PlayAnimation(L"noneRectAnim", false);
		GetOwner()->CopyAnimator(4, mAnimator);
	}
	void FallScript::OnCollisionEnter(Collider2D* other)
	{
	}
	void FallScript::OnCollisionStay(Collider2D* other)
	{
	}
	void FallScript::OnCollisionExit(Collider2D* other)
	{
	}
	void FallScript::Update()
	{
		if (bArrival)
		{
			if (mACType == eAccessorySkillType::END)
			{
				eSkillCrashType crashType = skillCrashTypes[(int)mType];
				if (crashType == eSkillCrashType::END)
				{
					GetOwner()->ReleaseCopyAnimator();
					GetOwner()->SetState(GameObject::eState::Delete);
				}
				if (crashType != eSkillCrashType::END
					&&
					mAnimator->GetActiveAnimation()->GetKey() != crashNames[(int)crashType] + L"anim")
				{
					SET_SCALE_XYZ(GetOwner()
								  , crashSizes[(int)crashType].x
								  , crashSizes[(int)crashType].y
								  , GET_POS(GetOwner()).z
					);
					Collider2D* col = GetOwner()->GetComponent<Collider2D>();
					col->Resize();
					mAnimator->PlayAnimation(crashNames[(int)crashType] + L"anim", false);
					GetOwner()->PlayCopyAnimator(skillAnimNames[(int)mType] + L"anim", false);
				}	
			}
			else
			{
				eSkillCrashType crashType = accessorySkillCrashTypes[(int)mACType];
				if (crashType == eSkillCrashType::END)
				{
					GetOwner()->ReleaseCopyAnimator();
					GetOwner()->SetState(GameObject::eState::Delete);
				}
				if (crashType != eSkillCrashType::END
					&&
					mAnimator->GetActiveAnimation()->GetKey() != crashNames[(int)crashType] + L"anim")
				{
					SET_SCALE_XYZ(GetOwner()
								  , crashSizes[(int)crashType].x
								  , crashSizes[(int)crashType].y
								  , GET_POS(GetOwner()).z
					);
					Collider2D* col = GetOwner()->GetComponent<Collider2D>();
					col->Resize();
					mAnimator->PlayAnimation(crashNames[(int)crashType] + L"anim", false);
					GetOwner()->PlayCopyAnimator(skillAnimNames[(int)mType] + L"anim", false);
				}
			}
			bArrival = false;
		}
		if (bSkillFire)
		{
			bSkillFire = false;
			if (mACType == eAccessorySkillType::END)
			{
				mAnimator->PlayAnimation(skillAnimNames[(int)mType] + L"anim", true);
			}	
			else
			{
				mAnimator->PlayAnimation(accessorySkillNames[(int)mACType] + L"anim", true);
			}
				
		}
		
	}
	void FallScript::LateUpdate()
	{
	}
	void FallScript::Render()
	{
	}
}	