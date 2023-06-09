#include "mScene.h"
#include "mRenderer.h"

namespace m
{
	Scene::Scene()
	{
		mLayers.resize((int)eLayerType::End);
	}
	Scene::~Scene()
	{

	}

	void Scene::Initialize()
	{
		// 여기서 초기 게임 맵데이터를 세팅해줘야 한다.
		for (Layer& layer : mLayers)
		{
			layer.Initialize();
		}
	}

	void Scene::Update()
	{
		for (Layer& layer : mLayers)
		{
			layer.Update();
		}
	}
	void Scene::LateUpdate()
	{
		for (Layer& layer : mLayers)
		{
			layer.LateUpdate();
		}
	}
	void Scene::Render()
	{
		for (Layer& layer : mLayers)
		{
			layer.Render();
		}
	}
	void Scene::AddGameObject(eLayerType type, GameObject* gameObj)
	{
		mLayers[(int)type].AddGameObject(gameObj);
	}
	Layer& Scene::GetGameObjects(eLayerType type)
	{
		return mLayers[(int)type];
	}
	void Scene::OnExit()
	{}
	void Scene::OnEnter()
	{
		renderer::mainCamera = GetSceneMainCamera();
	}
}