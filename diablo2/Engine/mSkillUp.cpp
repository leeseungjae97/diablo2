#include "mSkillUp.h"

#include "..\engine_source\mMeshRenderer.h"
#include "..\engine_source\mTransform.h"
#include "..\engine_source\mSceneManager.h"
#include "..\engine_source\SkillLookUpTables.h"

#include "mButton.h"
#include "mSkillButton.h"
#include "mPlayerInfo.h"


namespace m
{
	SkillUp::SkillUp(Camera* camera)
		: coldBtn(nullptr)
		, fireBtn(nullptr)
		, lightBtn(nullptr)
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
		//coldBtn->SetClickFunction([](SkillUp* ss) { ; });
		buttons.push_back(coldBtn);
		curScene->AddGameObject(eLayerType::UI, coldBtn);


		fireBtn = new Button();
		fireBtn->SetCamera(GetCamera());
		// x 230 , y 278
		fireBtn->GetComponent<MeshRenderer>()->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		fireBtn->GetComponent<MeshRenderer>()->SetMaterial(Resources::Find<Material>(L"noneRect"));
		fireBtn->GetComponent<Transform>()->SetScale(Vector3(91.f * Texture::GetWidRatio(), 110.f * Texture::GetHeiRatio(), 0.f));
		fireBtn->GetComponent<Transform>()->SetPosition(Vector3(tr->GetPosition().x + 30.f * Texture::GetWidRatio() + 91.f * Texture::GetWidRatio() / 2.f, 450.f - 170.f - 110.f * Texture::GetHeiRatio() * 2, -1.0f));
		buttons.push_back(fireBtn);
		curScene->AddGameObject(eLayerType::UI, fireBtn);

		lightBtn = new Button();
		lightBtn->SetCamera(GetCamera());
		// x 230 , y 385
		lightBtn->GetComponent<MeshRenderer>()->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		lightBtn->GetComponent<MeshRenderer>()->SetMaterial(Resources::Find<Material>(L"noneRect"));
		lightBtn->GetComponent<Transform>()->SetScale(Vector3(91.f * Texture::GetWidRatio(), 110.f * Texture::GetHeiRatio(), 0.f));
		lightBtn->GetComponent<Transform>()->SetPosition(Vector3(tr->GetPosition().x + 30.f * Texture::GetWidRatio() + 91.f * Texture::GetWidRatio() / 2.f, 450.f - 170.f - 110.f * Texture::GetHeiRatio() * 3, -1.0f));
		buttons.push_back(lightBtn);
		curScene->AddGameObject(eLayerType::UI, lightBtn);

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
			skill->GetComponent<Transform>()->SetScale(Vector3(scaleX, scaleY, 0.f));
			skill->GetComponent<MeshRenderer>()->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			skill->GetComponent<MeshRenderer>()->SetMaterial(Resources::Find<Material>(skillName));
			skill->SetClickMaterial(Resources::Find<Material>(clickSkillName));
			skill->SetNormalMaterial(Resources::Find<Material>(skillName));
			skill->SetState(Invisible);
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
			skill->GetComponent<Transform>()->SetScale(Vector3(scaleX, scaleY, 0.f));
			skill->GetComponent<MeshRenderer>()->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			skill->GetComponent<MeshRenderer>()->SetMaterial(Resources::Find<Material>(skillName));
			skill->SetClickMaterial(Resources::Find<Material>(clickSkillName));
			skill->SetNormalMaterial(Resources::Find<Material>(skillName));
			skill->SetState(Invisible);
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
			skill->GetComponent<Transform>()->SetScale(Vector3(scaleX, scaleY, 0.f));
			skill->GetComponent<MeshRenderer>()->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
			skill->GetComponent<MeshRenderer>()->SetMaterial(Resources::Find<Material>(skillName));
			skill->SetClickMaterial(Resources::Find<Material>(clickSkillName));
			skill->SetNormalMaterial(Resources::Find<Material>(skillName));
			skill->SetState(Invisible);
			fireSkills.push_back(skill);
			curScene->AddGameObject(eLayerType::UI, skill);
		}
		skills = coldSkills;
		learnSkills = PlayerInfo::learnedColdSkill;
	}
	SkillUp::~SkillUp()
	{}
	void SkillUp::Initialize()
	{
		UI::Initialize();
	}
	void SkillUp::Update()
	{
		UI::Update();
		if (buttons[0]->GetState() != GetState())
		{
			for (Button* btn : buttons)
			{
				btn->SetState(GetState());
				for (int i = 0; i < 10; ++i)
				{
					Button* btn = skills[i];
					if (learnSkills[i] == 0) btn->SetState(Invisible);
					else btn->SetState(Active);
				}
			}
		}
		if (skills.size() != 0 && PlayerInfo::skillPoint != 0)
		{
			for (SkillButton* btn : skills)
			{
				if (btn->GetClick())
				{
					btn->GetSkillIndex();
					PlayerInfo::skillPoint--;
				}
			}
		}

		if (coldBtn->GetClick())
		{
			GetComponent<MeshRenderer>()->SetMaterial(skillP1);
			for (SkillButton* btn : skills) btn->SetState(Invisible);
			skills = coldSkills;
			learnSkills = PlayerInfo::learnedColdSkill;
			for (int i = 0; i < 10; ++i)
			{
				Button* btn = skills[i];
				if (learnSkills[i] == 0) btn->SetState(Invisible);
				else btn->SetState(Active);
			}			
		}
		if (fireBtn->GetClick())
		{
			GetComponent<MeshRenderer>()->SetMaterial(skillP2);
			for (SkillButton* btn : skills) btn->SetState(Invisible);
			skills = fireSkills;
			learnSkills = PlayerInfo::learnedFireSkill;
			for (int i = 0; i < 10; ++i)
			{
				Button* btn = skills[i];
				if (learnSkills[i] == 0) btn->SetState(Invisible);
				else btn->SetState(Active);
			}
		}
		if (lightBtn->GetClick())
		{
			GetComponent<MeshRenderer>()->SetMaterial(skillP3);
			for (SkillButton* btn : skills) btn->SetState(Invisible);
			skills = lightSkills;
			learnSkills = PlayerInfo::learnedLightSkill;
			for (int i = 0; i < 10; ++i)
			{
				Button* btn = skills[i];
				if (learnSkills[i] == 0) btn->SetState(Invisible);
				else btn->SetState(Active);
			}
		}

		
	}
	void SkillUp::LateUpdate()
	{
		UI::LateUpdate();
	}
	void SkillUp::Render()
	{
		UI::Render();
	}
}