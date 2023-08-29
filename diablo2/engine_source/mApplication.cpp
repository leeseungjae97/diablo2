#include "mApplication.h"
#include "mInput.h"
#include "mTime.h"
#include "mRenderer.h"
#include "mScene.h"
#include "mSceneManager.h"
#include "mMouseManager.h"
#include "mCollisionManager.h"

#include "../Engine/mPlayerInfo.h"
#include "../Engine/mPlayer.h"

#include "../editor_source/guiEditor.h"

#include "mGameObject.h"
//#include "mFontWrapper.h"

namespace m
{
	Application::Application()
		: graphicDevice(nullptr)
		, mHwnd(NULL)
		, mWidth(-1)
		, mHeight(-1)
	{

	}

	Application::~Application()
	{}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
		Destroy();
	}

	void Application::Initialize()
	{
		Time::Initiailize();
		Input::Initialize();
		//FontWrapper::Initialize();
		renderer::Initialize();
		SceneManager::Initialize();
		//gui::Editor::Initialize();
	}

	void Application::Update()
	{
		Time::Update();
		Input::Update();
		// Scene -> Layer -> Entity
		SceneManager::Update();
		MouseManager::Update();
		CollisionManager::Update();
	}

	void Application::LateUpdate()
	{
		SceneManager::LateUpdate();
	}

	void Application::Render()
	{
		Time::Render();
		graphicDevice->ClearTarget();
		graphicDevice->UpdateViewPort();

		//HDC hdc2 = GetDC(mHwnd);
		//DrawText(hdc2, szFloat, iLen, &rt, DT_WORDBREAK);

//#define FONT_RGBA(r, g, b, a) (((((BYTE)a << 24) | (BYTE)b << 16) | (BYTE)g << 8) | (BYTE)r)
//		FontWrapper::DrawFont(L"TEST", 10, 10, 100, FONT_RGBA(255, 0, 255, 255));
		//SceneManager::Render();
		renderer::Render();
	}
	void Application::Destroy()
	{
		SceneManager::Destroy();
	}
	void Application::Present()
	{
		//m::graphics::GetDevice()->DrawStringText(L"testestestestestestes");
		graphicDevice->Present();

		//wchar_t szFloat[100] = {};
		//Vector3 pp = Vector3::Zero;
		//if(PlayerInfo::player)
		//pp = GET_POS(PlayerInfo::player);
		//Vector2 coord = Vector2(0.f, 0.f);

		//if(TileManager::playerStandTile)
		//	coord = TileManager::playerStandTile->GetCoord();

		//swprintf_s(szFloat, 100, L"player pos : %f.0, %f.0\n player coord : %f.0, %f.0", pp.x, pp.y, coord.x, coord.y);
		//size_t iLen = wcsnlen_s(szFloat, 100);
		//RECT rt = { 50, 100, 400, 200 };
		//HDC hdc = GetDC(mHwnd);
		//DrawText(hdc, szFloat, iLen, &rt, DT_WORDBREAK);
	}

	void Application::SetWindow(HWND hwnd, UINT width, UINT height)
	{
		if (graphicDevice == nullptr)
		{
			mHwnd = hwnd;
			mWidth = width;
			mHeight = height;

			graphicDevice = std::make_unique<m::graphics::GraphicDevice_DX11>();
			m::graphics::GetDevice() = graphicDevice.get();
		}

		RECT rt = { 0, 0, (LONG)width , (LONG)height };
		AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, false);

		//SetWindowPos(mHwnd, nullptr, 2570, 1440 - 1080, rt.right - rt.left, rt.bottom - rt.top, 0);
		SetWindowPos(mHwnd, nullptr, 0, 0, rt.right - rt.left, rt.bottom - rt.top, 0);
		ShowWindow(mHwnd, true);
		UpdateWindow(mHwnd);
	}

	//void Application::SetViewport(UINT width, UINT height)
	//{
	//	mViewport.x = 0.f;
	//	mViewport.y = 0.f;
	//	mViewport.height = height;
	//	mViewport.width = width;
	//	mViewport.maxDepth = 1000.f;
	//	mViewport.minDepth = -1.f;
	//}

}
