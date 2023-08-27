#pragma once
#include "mButton.h"
#include "mTrappingColor.h"

namespace m
{
	class SkillButton :
		public Button
	{
	public:
		SkillButton(int indexX, int indexY, float startX
					, float startY, float intervalX
					, float intervalY, int _skillIndex);
		virtual ~SkillButton();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render() override;

		int GetSkillIndex() { return skillIndex; }

		void SetColor(Vector4 color) { if(mTC) mTC->SetColor(color); }
	private:
		int indexX;
		int indexY;
		float startX;
		float startY;
		float intervalX;
		float intervalY;
		int skillIndex;

		TrappingColor* mTC;
	};
}