#include "mPlayScene.h"

#include "..\engine_source\mGameObject.h"
#include "..\engine_source\mMeshRenderer.h"
#include "..\engine_source\mTransform.h"
#include "..\engine_source\mResources.h"
#include "..\engine_source\mCamera.h"
#include "..\engine_source\mSceneManager.h"
#include "..\engine_source\mRenderer.h"
#include "..\engine_source\mApplication.h"
#include "..\engine_source\mCollisionManager.h"
#include "..\engine_source\mAnimator.h"
#include "..\engine_source\AnimLookUpTables.h"
#include "..\engine_source\mFontWrapper.h"
#include "..\engine_source\mComputeShader.h"

#include "mAstar.h"
#include "mCameraScript.h"
#include "mBackground.h"
#include "mPlayer.h"
#include "mMonster.h"
#include "mTile.h"
#include "mButton.h"
#include "mInventory.h"
#include "mInvenItem.h"
#include "mGridScript.h"
#include "mSkillUp.h"
#include "mCollider2D.h"
#include "mPlayerScript.h"
#include "mMonsterScript.h"
#include "mBottomUI.h"
#include "mUVUI.h"

extern m::Application application;
namespace m
{
	PlayScene::PlayScene()
	{

	}
	PlayScene::~PlayScene()
	{}
	void PlayScene::Initialize()
	{
		Scene::Initialize();

		//ComputeShader* cs = new ComputeShader();
		//cs->Create(L"PaintCS.hlsl", "main");

		SHARED_TEX tex;

		camera = new GameObject();
		//camera->SetName(L"Camera");
		AddGameObject(eLayerType::Player, camera);
		SET_POS_XYZ(camera, 0.f, 0.f, -10.f);
		Camera* cameraComp = ADD_COMP(camera, Camera);
		SetSceneMainCamera(cameraComp);
		
		float TILE_SIZE_X = 160.f;
		float TILE_SIZE_Y = 80.f;

		for (int y = 0; y < 10; ++y)
		{
			for (int x = 0; x < 10; ++x)
			{
				float fX = (float)(TILE_SIZE_X * (x - y)) / 2.f;
				float fY = (float)(TILE_SIZE_Y * (x + y)) / 2.f;
				Tile* tile = new Tile(Vector2(x, y));

				AddGameObject(eLayerType::Tile, tile);
				SET_MAIN_CAMERA(tile);
				SET_MESH(tile, L"RectMesh");
				if ((y == 2 && x == 2) 
					|| (y == 2 && x == 3)
					|| (y == 2 && x == 4)
					|| (y == 2 && x == 5)
					|| (y == 2 && x == 6)
					)
				{
					tile->SetIsWall(true);
				}
				else
				{
					tile->SetIsWall(false);
				}
				SET_MATERIAL(tile, L"testTile");
				
				
				SET_SCALE_XYZ(tile, TILE_SIZE_X, TILE_SIZE_Y, 0.f);
				SET_POS_XYZ(tile, fX, fY, 1.0f);
				tiles.push_back(tile);
			}
		}
		srand((unsigned int)time(NULL));
		int randPos = rand() % tiles.size();

		Astar* a = new Astar();
		a->SetTiles(tiles);
		a->SetXLength(10);
		a->SetYLength(10);
		a->Initialize();

		GetSceneMainCamera()->DisableLayerMasks();
		GetSceneMainCamera()->TurnLayerMask(eLayerType::Player, true);
		GetSceneMainCamera()->TurnLayerMask(eLayerType::Tile, true);
		GetSceneMainCamera()->TurnLayerMask(eLayerType::Monster, true);
		camera->AddComponent<CameraScript>();
		renderer::cameras.push_back(GetSceneMainCamera());
		//camera->AddComponent<GridScript>();

		Vector3 randTilePos = GET_POS(tiles[randPos]);
		Player* player = new Player(randTilePos);
		SET_MAIN_CAMERA(player);
		AddGameObject(eLayerType::Player, player);
		SET_MESH(player, L"RectMesh");
		SET_MATERIAL(player, L"AnimationMaterial");
		SET_SCALE_XYZ(player, 48.f, 74.f, 1.f);
		ADD_COMP(player, Animator);
		player->SetTile(tiles);

		randTilePos = GET_POS(tiles[randPos + 1]);
		Monster* monster = new Monster(randTilePos);

		SET_MAIN_CAMERA(monster);
		AddGameObject(eLayerType::Monster, monster);
		SET_MESH(monster, L"RectMesh");
		SET_MATERIAL(monster, L"AnimationMaterial");
		SET_SCALE_XYZ(monster, 80.f, 100.f, 1.f);
		ADD_COMP(monster, Animator);

		MonsterScript<DiabloSt>* ms = ADD_COMP(monster, MonsterScript<DiabloSt>);
		ms->SetMonster(monster);
		ms->SetPlayer(player);
		
		PlayerScript* ps = ADD_COMP(player, PlayerScript);
		ps->SetPlayer(player);
		ps->SetMonster(monster);

		GetSceneMainCamera()->SetFollowObject(player);
		//GameObject* child = new GameObject();
		//child->SetCamera(cameraComp);
		//AddGameObject(eLayerType::Player, child);
		//child->AddComponent<MeshRenderer>();
		//child->GetComponent<MeshRenderer>()->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		//child->GetComponent<MeshRenderer>()->SetMaterial(Resources::Find<Material>(L"testAmazon"));

		//child->GetComponent<Transform>()->SetScale(Vector3(31.f, 80.f, 0.f));
		//child->GetComponent<Transform>()->SetPosition(Vector3(1.f, 0.f, -1.f));
		//child->GetComponent<Transform>()->SetParent(player->GetComponent<Transform>());

		//float radian = math::DegreeToRadian(90.f);
		//player->GetComponent<Transform>()->SetRotation(0.f, 0.f, radian);

		GameObject* light = new GameObject();
		light->SetName(L"Smile");
		AddGameObject(eLayerType::Light, light);
		Light* lightComp = light->AddComponent<Light>();
		lightComp->SetType(eLightType::Directional);
		lightComp->SetColor(Vector4(1.0f, 1.0f, 1.0f, 1.0f));

		GameObject* uiCamera = new GameObject();
		SET_POS_XYZ(uiCamera, 0.0f, 0.0f, -1.f);
		Camera* cameraComp2 = ADD_COMP(uiCamera, Camera);
		cameraComp2->TurnLayerMask(eLayerType::Player, false);

		AddGameObject(eLayerType::UI, uiCamera);


		inventory = new Inventory(cameraComp2);
		inventory->SetState(GameObject::NoRenderUpdate);

		skillUp = new SkillUp(cameraComp2);
		skillUp->SetState(GameObject::NoRenderUpdate);

		uiBottomBar = new BottomUI(cameraComp2);

		//AddGameObject(eLayerType::UI, uiBottomBar);
		//SET_MESH(uiBottomBar, L"RectMesh");
		//SET_MATERIAL(uiBottomBar, L"bottomUi");
		//GET_TEX(uiBottomBar, tex);
		//SET_SCALE_TEX_SIZE_WITH_RAT(uiBottomBar, tex, 0.f);
		//SET_POS_XYZ(uiBottomBar, 0.f, -RESOL_H_HEI + 104.f * Texture::GetHeiRatio() / 2.f, -1.f);

		UI* uiMp = new UI();
		AddGameObject(eLayerType::UI, uiMp);
		uiMp->SetCamera(cameraComp2);
		SET_MESH(uiMp, L"RectMesh");
		SET_MATERIAL(uiMp, L"mpUi");
		GET_TEX(uiMp, tex);
		SET_SCALE_TEX_SIZE_WITH_RAT(uiMp, tex, 0.f);
		SET_POS_XYZ(uiMp, RESOL_H_WID - 117.f * Texture::GetWidRatio() / 2.f
					, -RESOL_H_HEI + 104.f * Texture::GetHeiRatio() / 2.f, -1.f);

	
		UVUI* mp = new UVUI();
		AddGameObject(eLayerType::UI, mp);
		mp->SetCamera(cameraComp2);
		SET_MESH(mp, L"RectMesh");
		SET_MATERIAL(mp, L"mp");
		GET_TEX(mp, tex);
		SET_SCALE_TEX_SIZE_WITH_RAT(mp, tex, 0.f);
		SET_POS_XYZ(mp, RESOL_H_WID - 140.f * Texture::GetWidRatio() / 2.f
					, -RESOL_H_HEI + 105.f * Texture::GetHeiRatio() / 2.f, -1.f);


		UI* mpOverlapHands = new UI();
		AddGameObject(eLayerType::UI, mpOverlapHands);
		SET_MESH(mpOverlapHands, L"RectMesh");
		SET_MATERIAL(mpOverlapHands, L"mpOverlapHands");
		GET_TEX(mpOverlapHands, tex);
		SET_SCALE_TEX_SIZE_WITH_RAT(mpOverlapHands, tex, 0.f);
		SET_POS_XYZ(mpOverlapHands, RESOL_H_WID - 135.f * Texture::GetWidRatio() / 2.f
					, -RESOL_H_HEI + 105.f * Texture::GetHeiRatio() / 2.f, -1.f);
		
		UI* uiHp = new UI();
		AddGameObject(eLayerType::UI, uiHp);
		uiHp->SetCamera(cameraComp2);
		SET_MESH(uiHp, L"RectMesh");
		SET_MATERIAL(uiHp, L"hpUi");
		GET_TEX(uiHp, tex);
		SET_SCALE_TEX_SIZE_WITH_RAT(uiHp, tex, 0.f);
		SET_POS_XYZ(uiHp, -RESOL_H_WID + 117.f * Texture::GetWidRatio() / 2.f
					, -RESOL_H_HEI + 105.f * Texture::GetHeiRatio() / 2.f, -1.f);

		UVUI* hp = new UVUI();
		AddGameObject(eLayerType::UI, hp);
		hp->SetCamera(cameraComp2);
		hp->SetName(L"hp");
		SET_MESH(hp, L"RectMesh");
		SET_MATERIAL(hp, L"hp");
		GET_TEX(hp, tex);
		SET_SCALE_TEX_SIZE_WITH_RAT(hp, tex, 0.f);
		SET_POS_XYZ(hp, -RESOL_H_WID + 138.f * Texture::GetWidRatio() / 2.f
					, -RESOL_H_HEI + 105.f * Texture::GetHeiRatio() / 2.f, -1.f);

		player->SetHpUI(hp);

		UI* hpOverlapHands = new UI();
		AddGameObject(eLayerType::UI, hpOverlapHands);
		hpOverlapHands->SetCamera(cameraComp2);
		SET_MESH(hpOverlapHands, L"RectMesh");
		SET_MATERIAL(hpOverlapHands, L"hpOverlapHands");
		GET_TEX(hpOverlapHands, tex);
		SET_SCALE_TEX_SIZE_WITH_RAT(hpOverlapHands, tex, 0.f);
		SET_POS_XYZ(hpOverlapHands, RESOL_H_WID + 137.f * Texture::GetWidRatio() / 2.f
					, -RESOL_H_HEI + 97.f * Texture::GetHeiRatio() / 2.f, -1.f);

		Button* skillShortCut1 = new Button();
		AddGameObject(eLayerType::UI, skillShortCut1);
		skillShortCut1->SetCamera(cameraComp2);

		SET_MESH(skillShortCut1, L"RectMesh");
		SET_MATERIAL(skillShortCut1, L"frozenOrbIcon");
		GET_TEX(skillShortCut1, tex);
		SET_SCALE_TEX_SIZE_WITH_RAT(skillShortCut1, tex, 0.f);
		SET_POS_XYZ(skillShortCut1, -470.f - tex->GetWidth() * Texture::GetWidRatio() / 2.f
					, -RESOL_H_HEI + tex->GetHeight() * Texture::GetHeiRatio() / 2.f, -1.f);
		skillShortCut1->SetClickMaterial(RESOURCE_FIND(Material, L"frozenOrbClickIcon"));
		skillShortCut1->SetNormalMaterial(RESOURCE_FIND(Material, L"frozenOrbIcon"));

		Button* skillShortCut2 = new Button();
		AddGameObject(eLayerType::UI, skillShortCut2);
		skillShortCut2->SetCamera(cameraComp2);

		SET_MESH(skillShortCut2, L"RectMesh");
		SET_MATERIAL(skillShortCut2, L"thunderStormIcon");
		GET_TEX(skillShortCut2, tex);
		SET_SCALE_TEX_SIZE_WITH_RAT(skillShortCut2, tex, 0.f);
		SET_POS_XYZ(skillShortCut2, 470.f + tex->GetWidth() * Texture::GetWidRatio() / 2.f
					, -RESOL_H_HEI + tex->GetHeight() * Texture::GetHeiRatio() / 2.f, -1.f);
		skillShortCut2->SetClickMaterial(RESOURCE_FIND(Material, L"thunderStormClickIcon"));
		skillShortCut2->SetNormalMaterial(RESOURCE_FIND(Material, L"thunderStormIcon"));

		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Player, true);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Monster, true);
		CollisionManager::SetLayer(eLayerType::Item, eLayerType::Item, true);
	}
	void PlayScene::Update()
	{
		Scene::Update();

		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"MainMenuScene");
		}
		if (Input::GetKeyDown(eKeyCode::I) && nullptr != inventory)
		{
			inventory->SetState(inventory->GetState() != GameObject::eState::RenderUpdate ? GameObject::eState::RenderUpdate : GameObject::eState::NoRenderUpdate);
		}
		if (Input::GetKeyDown(eKeyCode::T) && nullptr != skillUp)
		{
			skillUp->SetState(skillUp->GetState() != GameObject::eState::RenderUpdate ? GameObject::eState::RenderUpdate : GameObject::eState::NoRenderUpdate);
		}
	}
	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void PlayScene::Render()
	{
		Scene::Render();
	}
}