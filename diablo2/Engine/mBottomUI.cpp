#include "mBottomUI.h"

#include "../engine_source/mSceneManager.h"
#include "../engine_source/mMeshRenderer.h"
#include "../engine_source/mTexture.h"
#include "mInven.h"
namespace m
{
	BottomUI::BottomUI(Camera* camera)
		: bBelt(false)
	{
		SetCamera(camera);

		SetState(RenderUpdate);

		SET_MESH(this, L"RectMesh");
		SET_MATERIAL(this, L"bottomUi");

		MAKE_GET_TEX(this, tex);
		SET_SCALE_TEX_SIZE_WITH_RAT(this, tex, 1.f);
		SET_POS_XYZ(this, 0.f, -RESOL_H_HEI + 104.f * Texture::GetHeiRatio() / 2.f, -1.f);

		Scene* curScene = SceneManager::GetActiveScene();
		curScene->AddGameObject(eLayerType::UI, this);

		for (int i = 0; i < 4; ++i)
		{
			Inven* pocket = new Inven();
			pocket->SetState(eState::RenderUpdate);
			pocket->SetCamera(GetCamera());
			SET_SCALE_XYZ(pocket, 30.f * Texture::GetWidRatio()
						  , 31.f* Texture::GetHeiRatio(), 0.f);
			SET_POS_XYZ(pocket
				, GET_POS(this).x + 23.f * Texture::GetWidRatio() + (GET_SCALE(pocket).x / 2.f) + (30.f * i) * Texture::GetWidRatio()
				, GET_POS(this).y - GET_SCALE(pocket).y / 2.f - 14.f * Texture::GetHeiRatio()
				, -1.f);
			curScene->AddGameObject(eLayerType::UI, pocket);
			pockets.push_back(pocket);
		}

		for (int i = 0; i < 8; ++i)
		{
			Inven* pocket = new Inven();
			pocket->SetState(eState::NoRenderNoUpdate);
			pocket->SetCamera(GetCamera());
			SET_SCALE_XYZ(pocket, 30.f * Texture::GetWidRatio()
						  , 31.f * Texture::GetHeiRatio(), 0.f);
			SET_POS_XYZ(pocket
						, GET_POS(this).x + 23.f * Texture::GetWidRatio() + (GET_SCALE(pocket).x / 2.f) + (30 * (i % 4)) * Texture::GetWidRatio()
						, GET_POS(this).y - GET_SCALE(pocket).y / 2.f - 14.f * Texture::GetHeiRatio() + (GET_SCALE(pocket).y * (i / 4 + 1))
						, -1.f);
			curScene->AddGameObject(eLayerType::UI, pocket);
			exPockets.push_back(pocket);
		}
	}
	BottomUI::~BottomUI()
	{
	}
	void BottomUI::Initialize()
	{
		UI::Initialize();
	}
	void BottomUI::Update()
	{
		UI::Update();
		for (int i = 0; i < pockets.size(); ++i)
		{
			bool hover = false;
			if (pockets[i]->GetHover())
			{
				hover = true;
			}
			if(!hover) for (int i = 0; i < exPockets.size(); ++i) exPockets[i]->SetState(NoRenderNoUpdate);
			if(hover) for (int i = 0; i < exPockets.size(); ++i) exPockets[i]->SetState(RenderUpdate);
		}
	}
	void BottomUI::LateUpdate()
	{
		UI::LateUpdate();
	}
	void BottomUI::Render()
	{
		UI::Render();
	}
}