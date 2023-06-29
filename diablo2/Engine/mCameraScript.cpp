//#include "mCameraScript.h"
//#include "mTransform.h"
//#include "mTime.h"
//#include "mGameObject.h"
//#include "mInput.h"
//
//namespace m
//{
//	void CameraScript::Update()
//	{
//		Transform* tr = GetOwner()->GetComponent<Transform>();
//		Vector3 pos = tr->GetPosition();
//
//		if (Input::GetKey(eKeyCode::W))
//		{
//			pos.z += 5.0f * Time::DeltaTime();
//			tr->SetPosition(pos);
//		}
//		else if (Input::GetKey(eKeyCode::S))
//		{
//			pos.z -= 5.0f * Time::DeltaTime();
//			tr->SetPosition(pos);
//		}
//		else if (Input::GetKey(eKeyCode::A))
//		{
//			pos.x -= 100.0f * Time::DeltaTime();
//			tr->SetPosition(pos);
//		}
//		else if (Input::GetKey(eKeyCode::D))
//		{
//			pos.x += 100.0f * Time::DeltaTime();
//			tr->SetPosition(pos);
//		}
//		else if (Input::GetKey(eKeyCode::Q))
//		{
//			pos.y -= 100.0f * Time::DeltaTime();
//			tr->SetPosition(pos);
//		}
//		else if (Input::GetKey(eKeyCode::E))
//		{
//			pos.y += 100.0f * Time::DeltaTime();
//			tr->SetPosition(pos);
//		}
//	}
//}