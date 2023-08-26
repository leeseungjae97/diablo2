#include "mSkillStatus.h"

#include "../engine_source/mMeshRenderer.h"
#include "../engine_source/mTransform.h"
#include "../engine_source/mSceneManager.h"
#include "../engine_source/SkillLookUpTables.h"

#include "mButton.h"
#include "mSkillButton.h"
#include "mPlayerInfo.h"


namespace m
{
	SkillStatus::SkillStatus(Camera* camera)
		: coldBtn(nullptr)
		, fireBtn(nullptr)
		, lightBtn(nullptr)
		, skillTreeSelectNum(0)
	{
		SetCamera(camera);
		Transform* tr = GetComponent<Transform>();

		tr->SetPosition(Vector3(400.f * Texture::GetWidRatio() / 2.f
			, 450.f - 555.f * Texture::GetHeiRatio() / 2.f, -1.f));
		tr->SetScale(Vector3(400.f * Texture::GetWidRatio()
			, 555.f * Texture::GetHeiRatio(), 0.f));

		MeshRenderer* mr = GetComponent<MeshRenderer>();
		mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		mr->SetMaterial(Resources::Find<Material>(L"skillPanelCold"));

		skillP1 = Resources::Find<Material>(L"skillPanelCold");
		skillP2 = Resources::Find<Material>(L"skillPanelLight");
		skillP3 = Resources::Find<Material>(L"skillPanelFire");

		Scene* curScene = SceneManager::GetActiveScene();
		curScene->AddGameObject(eLayerType::UI, this);

		coldBtn = new Button();
		coldBtn->SetCamera(GetCamera());
		// x 230 , y 170
		coldBtn->GetComponent<MeshRenderer>()->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		coldBtn->GetComponent<MeshRenderer>()->SetMaterial(Resources::Find<Material>(L"noneRect"));
		coldBtn->GetComponent<Transform>()->SetScale(Vector3(91.f * Texture::GetWidRatio(), 110.f * Texture::GetHeiRatio(), 0.f));
		coldBtn->GetComponent<Transform>()->SetPosition(Vector3(tr->GetPosition().x + 30.f * Texture::GetWidRatio() + 91.f * Texture::GetWidRatio() / 2.f, 450.f - 170.f - 110.f * Texture::GetHeiRatio(), -1.0f));
		//coldBtn->SetClickFunction([](SkillStatus* ss) { ; });
		buttons.push_back(coldBtn);
		curScene->AddGameObject(eLayerType::UI, coldBtn);

		lightBtn = new Button();
		lightBtn->SetCamera(GetCamera());
		// x 230 , y 385
		lightBtn->GetComponent<MeshRenderer>()->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		lightBtn->GetComponent<MeshRenderer>()->SetMaterial(Resources::Find<Material>(L"noneRect"));
		lightBtn->GetComponent<Transform>()->SetScale(Vector3(91.f * Texture::GetWidRatio(), 110.f * Texture::GetHeiRatio(), 0.f));
		lightBtn->GetComponent<Transform>()->SetPosition(Vector3(tr->GetPosition().x + 30.f * Texture::GetWidRatio() + 91.f * Texture::GetWidRatio() / 2.f, 450.f - 170.f - 110.f * Texture::GetHeiRatio() * 2, -1.0f));
		buttons.push_back(lightBtn);
		curScene->AddGameObject(eLayerType::UI, lightBtn);

		fireBtn = new Button();
		fireBtn->SetCamera(GetCamera());
		// x 230 , y 278
		fireBtn->GetComponent<MeshRenderer>()->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		fireBtn->GetComponent<MeshRenderer>()->SetMaterial(Resources::Find<Material>(L"noneRect"));
		fireBtn->GetComponent<Transform>()->SetScale(Vector3(91.f * Texture::GetWidRatio(), 110.f * Texture::GetHeiRatio(), 0.f));
		fireBtn->GetComponent<Transform>()->SetPosition(Vector3(tr->GetPosition().x + 30.f * Texture::GetWidRatio() + 91.f * Texture::GetWidRatio() / 2.f, 450.f - 170.f - 110.f * Texture::GetHeiRatio() * 3, -1.0f));
		buttons.push_back(fireBtn);
		curScene->AddGameObject(eLayerType::UI, fireBtn);

		float startX = (48.f / 2.f + 15.f);
		float startY = (555.f / 2.f - 76.f);

		float intervalX = 68.f;
		float intervalY = 68.f;

		float scaleX = 48.f * Texture::GetWidRatio();
		float scaleY = 48.f * Texture::GetHeiRatio();

		for (int i = 0 ; i < (int)eColdSkillType::END; ++i)
		{
			int iX = iColdSkillIndex[i][0];
			int iY = iColdSkillIndex[i][1];
			std::wstring skillName = wsColdSkillNames[i];
			std::wstring clickSkillName = wsColdSkillClickNames[i];
			SkillButton* skill = new SkillButton(iX, iY, startX, startY, intervalX, intervalY, i);
			skill->SetCamera(GetCamera());
			skill->GetComponent<Transform>()->SetScale(Vector3(scaleX, scaleY, 0.f));
			skill->GetComponent<TrappingColor>()->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			skill->GetComponent<TrappingColor>()->SetMaterial(Resources::Find<Material>(skillName));
			skill->SetClickMaterial(Resources::Find<Material>(clickSkillName));
			skill->SetNormalMaterial(Resources::Find<Material>(skillName));
			skill->SetState(NoRenderUpdate);
			coldSkills.push_back(skill);
			curScene->AddGameObject(eLayerType::UI, skill);
		}
		for (int i = 0; i < (int)eLightningSkillType::END; ++i)
		{
			int iX = iLightSkillIndex[i][0];
			int iY = iLightSkillIndex[i][1];
			std::wstring skillName = wsLightningSkillNames[i];
			std::wstring clickSkillName = wsLightningSkillClickNames[i];
			SkillButton* skill = new SkillButton(iX, iY, startX, startY, intervalX, intervalY, i);
			skill->SetCamera(GetCamera());
			skill->GetComponent<Transform>()->SetScale(Vector3(scaleX, scaleY, 0.f));
			skill->GetComponent<TrappingColor>()->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			skill->GetComponent<TrappingColor>()->SetMaterial(Resources::Find<Material>(skillName));
			skill->SetClickMaterial(Resources::Find<Material>(clickSkillName));
			skill->SetNormalMaterial(Resources::Find<Material>(skillName));
			skill->SetState(NoRenderUpdate);
			lightSkills.push_back(skill);
			curScene->AddGameObject(eLayerType::UI, skill);
		}
		for (int i = 0; i < (int)eFireSkillType::END; ++i)
		{
			int iX = iFireSkillIndex[i][0];
			int iY = iFireSkillIndex[i][1];
			std::wstring skillName = wsFireSkillNames[i];
			std::wstring clickSkillName = wsFireSkillClickNames[i];
			SkillButton* skill = new SkillButton(iX, iY, startX, startY, intervalX, intervalY, i);
			skill->SetCamera(GetCamera());
			skill->GetComponent<Transform>()->SetScale(Vector3(scaleX, scaleY, 0.f));
			skill->GetComponent<TrappingColor>()->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			skill->GetComponent<TrappingColor>()->SetMaterial(Resources::Find<Material>(skillName));
			skill->SetClickMaterial(Resources::Find<Material>(clickSkillName));
			skill->SetNormalMaterial(Resources::Find<Material>(skillName));
			skill->SetState(NoRenderUpdate);
			fireSkills.push_back(skill);
			curScene->AddGameObject(eLayerType::UI, skill);
		}
		skills = coldSkills;
		GetSkillTree(iColdAdjacencyMatrix);

	}
	SkillStatus::~SkillStatus()
	{}
	void SkillStatus::Initialize()
	{
		UI::Initialize();
	}
	void SkillStatus::Update()
	{
		UI::Update();
		if (buttons[0]->GetState() != GetState())
		{
			for (Button* btn : buttons)
				btn->SetState(GetState());
		}
		if (coldBtn->GetClick())
		{
			GetComponent<MeshRenderer>()->SetMaterial(skillP1);
			for (SkillButton* btn : skills) btn->SetState(NoRenderUpdate);
			skills = coldSkills;
			skillTreeSelectNum = 0;
			GetSkillTree(iColdAdjacencyMatrix);
		}
		
		if (lightBtn->GetClick())
		{
			GetComponent<MeshRenderer>()->SetMaterial(skillP2);
			for (SkillButton* btn : skills) btn->SetState(NoRenderUpdate);
			skills = lightSkills;
			skillTreeSelectNum = 1;
			GetSkillTree(iLightAdjacencyMatrix);
		}

		if (fireBtn->GetClick())
		{
			GetComponent<MeshRenderer>()->SetMaterial(skillP3);
			for (SkillButton* btn : skills) btn->SetState(NoRenderUpdate);
			skills = fireSkills;
			skillTreeSelectNum = 2;
			GetSkillTree(iFireAdjacencyMatrix);
		}

		bool noAntec = true;
		for (int i = 0; i < 10; ++i)
		{
			SkillButton* btn = skills[i];
			noAntec = true;
			for (int j = 0; j < 10; ++j)
			{
				if (skillTree[i][j] > PlayerInfo::learnedSkill[skillTreeSelectNum][j]) noAntec = false;
			}

			btn->SetState(GetState());

			if (noAntec)
			{
				btn->SetCanClick(true);
			}	
		}
		for (SkillButton* btn : skills)
		{
			if (PlayerInfo::learnedSkill[skillTreeSelectNum][btn->GetSkillIndex()] != 0)
			{
				btn->SetCanClick(false);
			}
		}
		if (PlayerInfo::skillPoint != 0)
		{
			for (SkillButton* btn : skills)
			{
				if (btn->GetOneClick())
				{
					PlayerInfo::learnedSkill[skillTreeSelectNum][btn->GetSkillIndex()]++;
					PlayerInfo::skillPoint--;
				}
			}
		}
	}
	void SkillStatus::LateUpdate()
	{
		UI::LateUpdate();
	}
	void SkillStatus::Render()
	{
		UI::Render();
	}
	void SkillStatus::GetSkillTree(int(*_skillTree)[10])
	{
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				skillTree[i][j] = _skillTree[i][j];
			}
		}		
	}
}