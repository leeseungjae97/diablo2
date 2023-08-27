#include "mSkillShortCutButton.h"

#include "../engine_source/mMeshRenderer.h"
#include "../engine_source/mSceneManager.h"
#include "../engine_source/mTexture.h"

#include "mPlayerInfo.h"

namespace m
{
	SkillShortCutButton::SkillShortCutButton(int skillIndex)
		: mSkillType(eSkillType::normalAttack)
		, mSkillIndex(skillIndex)
	{
		//SetClickMaterial(RESOURCE_FIND(Material, L"normalAttackClickIcon"));
		SetNormalMaterial(RESOURCE_FIND(Material, L"normalAttackIcon"));

		for(int i = 0 ; i < 10; ++i)
		{
			if (skillFunctionTypes[i] == eSkillFunctionType::Buff
				|| skillFunctionTypes[i] == eSkillFunctionType::Passive) continue;
			skillMats.push_back(RESOURCE_FIND(Material, wsColdSkillNames[i]));
		}
		for (int i = 0; i < 10; ++i)
		{
			if (skillFunctionTypes[i + 9] == eSkillFunctionType::Buff
				|| skillFunctionTypes[i + 9] == eSkillFunctionType::Passive) continue;
			skillMats.push_back(RESOURCE_FIND(Material, wsLightningSkillNames[i]));
		}
		for (int i = 0; i < 10; ++i)
		{
			if (skillFunctionTypes[i + 18] == eSkillFunctionType::Buff
				|| skillFunctionTypes[i + 18] == eSkillFunctionType::Passive) continue;
			skillMats.push_back(RESOURCE_FIND(Material, wsFireSkillNames[i]));
		}
		SetSkillBtnPos();
		Scene* curScene = SceneManager::GetActiveScene();
		for (int i = 0; i < skillMats.size(); ++i)
		{
			Button* mBtn = new Button();
			mBtn->SetCamera(GetCamera());
			curScene->AddGameObject(eLayerType::UI, mBtn);
			SET_MESH(mBtn, L"RectMesh");
			SET_MATERIAL_D(mBtn, skillMats[i]);
			MAKE_GET_TEX(mBtn, tex);
			SET_SCALE_TEX_SIZE_WITH_RAT(mBtn, tex, 1.f);
			SET_POS_XYZ(mBtn, skillMatPos[i].x, skillMatPos[i].y, -1.f);

		}
		//mDMS = ADD_COMP(this, DrawMaterials);
		//mDMS->SetMaterials(skillMats);
		
	}
	SkillShortCutButton::~SkillShortCutButton()
	{
	}
	void SkillShortCutButton::Initialize()
	{
		Button::Initialize();
	}
	void SkillShortCutButton::Update()
	{
		Button::Update();
	
		if (PlayerInfo::GetSkill(mSkillIndex) != mSkillType)
		{
			mSkillType = PlayerInfo::GetSkill(mSkillIndex);
			
			SetClickMaterial(RESOURCE_FIND(Material, wsSkillClickIconNames[(int)mSkillType]));
			//SetNormalMaterial(RESOURCE_FIND(Material, wsSkillIconNames[(int)mSkillType]));
		}
	}
	void SkillShortCutButton::LateUpdate()
	{
		Button::LateUpdate();
	}
	void SkillShortCutButton::Render()
	{
		Button::Render();
	}

	void SkillShortCutButton::SetSkillBtnPos()
	{
		//콜드 - 파이어 - 라이트닝 순
		//배운 스킬의 나열은 밑에서부터
		//라이트닝을 배우지 않았다면 파이어가 첫번째 열, 파이어를 배우지 않았다면 콜드가 첫번째 열
		bool learnSkill = false;
		int yPos = 1;
		int xPos = 1;
		Vector3 pos = GET_POS(this);
		for (int i = 2; i >= 0; --i)
		{
			learnSkill = false;
			for (int j = 0; j < 10; ++j)
			{
				if (PlayerInfo::learnedSkill[i][j] > 0)
				{
					Vector2 storePos;
					learnSkill = true;

					//storePos.x = (xPos * 30.f) + pos.x;
					//storePos.y = (yPos * 30.f) + pos.y;
					storePos.x = 30.f * xPos;
					storePos.y = 30.f * yPos;
					++xPos;
					skillMatPos.push_back(storePos);
				}else
				{
					skillMatPos.push_back(Vector2(0.f, 0.f));
				}
			}
			xPos = 1;
			if (learnSkill) ++yPos;
		}
	}
}
