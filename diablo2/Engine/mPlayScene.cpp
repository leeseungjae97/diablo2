#include "mPlayScene.h"

#include "..\engine_source\mGameObject.h"
#include "..\engine_source\mMeshRenderer.h"
#include "..\engine_source\mTransform.h"
#include "..\engine_source\mResources.h"
#include "..\engine_source\mCamera.h"
#include "..\engine_source\mSceneManager.h"
#include "..\engine_source\mRenderer.h"

#include "mCameraScript.h"
#include "mBackground.h"
#include "mPlayer.h"
#include "mTile.h"

namespace m
{
	PlayScene::PlayScene()
	{}
	PlayScene::~PlayScene()
	{}
	void PlayScene::Initialize()
	{
		GameObject* camera = new GameObject();
		//camera->SetName(L"Camera");
		AddGameObject(eLayerType::Player, camera);

		float TILE_SIZE_X = 160.f;
		float TILE_SIZE_Y = 80.f;

		float z = 5;

		for (int y = 0; y < 5; ++y)
		{
			for (int x = 0; x < 5; ++x)
			{
				float fX = (float)(TILE_SIZE_X * (x - y)) / 2.f;
				float fY = (float)(TILE_SIZE_Y * (x + y)) / 2.f;

				//float fX = (float)(TILE_SIZE_X * (x - y));
				//float fY = (float)(TILE_SIZE_Y * (x + y)); 

				Tile* tile = new Tile(Vector2(x, y));

				AddGameObject(eLayerType::Player, tile);
				tile->GetComponent<MeshRenderer>()->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
				tile->GetComponent<MeshRenderer>()->SetMaterial(Resources::Find<Material>(L"testTile"));
				tile->GetComponent<Transform>()->SetScale(Vector3(TILE_SIZE_X /** Texture::GetWidRatio()*/, TILE_SIZE_Y /** Texture::GetHeiRatio()*/, 0.f));
				tile->GetComponent<Transform>()->SetPosition(Vector3(fX, fY, z -= 0.01f));
				tiles.push_back(tile);
			}
		}

		Vector3 cenVec = tiles[12]->GetComponent<Transform>()->GetPosition();

		camera->GetComponent<Transform>()->SetPosition(Vector3(cenVec.x, cenVec.y, -1.f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		cameraComp->TurnLayerMask(eLayerType::UI, false);
		camera->AddComponent<CameraScript>();

		Player* player = new Player(Vector3(0.f, 0.f, z - 0.01f));
		player->SetCamera(cameraComp);
		AddGameObject(eLayerType::Player, player);
		player->AddComponent<MeshRenderer>();
		player->GetComponent<MeshRenderer>()->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		player->GetComponent<MeshRenderer>()->SetMaterial(Resources::Find<Material>(L"testAmazon"));
		player->GetComponent<Transform>()->SetScale(Vector3(31.f, 80.f, 0.f));


		GameObject* uiCamera = new GameObject();
		uiCamera->GetComponent<Transform>()->SetPosition(Vector3(0.0f, 0.0f, -1.f));
		Camera* cameraComp2 = uiCamera->AddComponent<Camera>();
		cameraComp2->TurnLayerMask(eLayerType::Player, false);

		AddGameObject(eLayerType::Player, uiCamera);

		GameObject* uiBottomBar = new GameObject();
		AddGameObject(eLayerType::UI, uiBottomBar);
		uiBottomBar->AddComponent<MeshRenderer>();
		uiBottomBar->GetComponent<MeshRenderer>()->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		uiBottomBar->GetComponent<MeshRenderer>()->SetMaterial(Resources::Find<Material>(L"bottomUi"));
		uiBottomBar->GetComponent<Transform>()->SetScale(Vector3(470.f * Texture::GetWidRatio()
			, 104.f * Texture::GetHeiRatio(), 0.f));
		uiBottomBar->GetComponent<Transform>()->SetPosition(Vector3(-470.f * Texture::GetWidRatio() / 2.f
			, -450 + 104.f * Texture::GetHeiRatio(), -1.f));

		GameObject* uiMp = new GameObject();
		AddGameObject(eLayerType::UI, uiMp);
		uiMp->AddComponent<MeshRenderer>();
		uiMp->GetComponent<MeshRenderer>()->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		uiMp->GetComponent<MeshRenderer>()->SetMaterial(Resources::Find<Material>(L"mpUi"));
		uiMp->GetComponent<Transform>()->SetScale(Vector3(128.f * Texture::GetWidRatio()
													, 104.f * Texture::GetHeiRatio(), 0.f));
		uiMp->GetComponent<Transform>()->SetPosition(Vector3(800.f - 117.f * Texture::GetWidRatio()
			, -450.f + 104.f * Texture::GetHeiRatio(), -1.f));


		GameObject* uiHp = new GameObject();
		AddGameObject(eLayerType::UI, uiHp);
		uiHp->AddComponent<MeshRenderer>();
		uiHp->GetComponent<MeshRenderer>()->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		uiHp->GetComponent<MeshRenderer>()->SetMaterial(Resources::Find<Material>(L"hpUi"));
		uiHp->GetComponent<Transform>()->SetScale(Vector3(128.f * Texture::GetWidRatio()
			, 104.f * Texture::GetHeiRatio(), 0.f));
		uiHp->GetComponent<Transform>()->SetPosition(Vector3(-800.f
			, -450.f + 104.f * Texture::GetHeiRatio(), -1.f));

		//GameObject* uiShortCutItemsExBar = new GameObject();
	}
	void PlayScene::Update()
	{
		Scene::Update();
		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"MainMenuScene");
		}
		if (Input::GetKeyDown(eKeyCode::M))
		{

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