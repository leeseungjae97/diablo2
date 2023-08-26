#pragma once

#include "_Engine.h"
#include "../engine_source/SkillLookUpTables.h"

namespace m
{
	class Player;
	class InvenItem;
	class PlayerInfo
	{
	public:
		static int skillPoint;
		static float hp;
		static float hpCapacity;
		static float hpPercent;
		static float mp;
		static int learnedSkill[3][10];

		static Player* player;

		static void CalHpPercent();
		static void Initialize();

		static eSkillType GetSkill(int num);
		static void SetSkill(int num, eSkillType type);

		static eSkillType SetColdSkillType(eColdSkillType type);
		static eSkillType SetFireSkillType(eFireSkillType type);
		static eSkillType SetLightningSkillType(eLightningSkillType type);
	private:

		static eSkillType skillTypes[2];
		
	};
}

