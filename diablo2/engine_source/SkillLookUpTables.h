#pragma once

namespace m
{
	enum class eSkillFunctionType
	{
		Straight,
		MultiStraight,
		Fall,
		MutiFall,
		Buff,
		Passive,
		None,
		END,
	};
	enum class eColdSkillType
	{
		iceBolt,
		frozenArmor,
		frostNova,
		iceBlast,
		shiverArmor,
		clacialSpike,
		blizzard,
		chillingArmor,
		frozenOrb,
		coldMastery,
		END
	};
	enum class eLightningSkillType
	{
		chargedBolt,
		staticField,
		telekinesis,
		nove,
		lightning,
		chainLightning,
		teleport,
		thunderStorm,
		energyShield,
		lightningMastery,
		END
	};
	enum class eFireSkillType
	{
		fireBolt,
		warmth,
		inferno,
		blaze,
		fireBall,
		fireWall,
		enchant,
		meteor,
		fireMastery,
		hydra,
		END
	};
	enum class eSkillType
	{
		iceBolt,
		frozenArmor,
		frostNova,
		iceBlast,
		shiverArmor,
		clacialSpike,
		blizzard,
		chillingArmor,
		frozenOrb,
		coldMastery,

		chargedBolt,
		staticField,
		telekinesis,
		nove,
		lightning,
		chainLightning,
		teleport,
		thunderStorm,
		energyShield,
		lightningMastery,

		fireBolt,
		warmth,
		inferno,
		blaze,
		fireBall,
		fireWall,
		enchant,
		meteor,
		fireMastery,
		hydra,

		normalAttack,


		// Monster
		DiabloLightning,
		END
	};
	std::wstring wsSkillIconNames[(int)eSkillType::END] = {
		L"iceBoltIcon",
		L"frozenArmorIcon",
		L"frostNovaIcon",
		L"iceBlastIcon",
		L"shiverArmorIcon",
		L"clacialSpikeIcon",
		L"blizzardIcon",
		L"chillingArmorIcon",
		L"frozenOrbIcon",
		L"coldMasteryIcon",

		L"chargedBoltIcon",
		L"staticFieldIcon",
		L"telekinesisIcon",
		L"noveIcon",
		L"lightningIcon",
		L"chainLightningIcon",
		L"teleportIcon",
		L"thunderStormIcon",
		L"energyShieldIcon",
		L"lightningMasteryIcon",

		L"fireBoltIcon",
		L"warmthIcon",
		L"infernoIcon",
		L"blazeIcon",
		L"fireBallIcon",
		L"fireWallIcon",
		L"enchantIcon",
		L"meteorIcon",
		L"fireMasteryIcon",
		L"hydraIcon",

		L"normalAttackIcon"
	};
	std::wstring wsSkillClickIconNames[(int)eSkillType::END] = {
		L"iceBoltClickIcon",
		L"frozenArmorClickIcon",
		L"frostNovaClickIcon",
		L"iceBlastClickIcon",
		L"shiverArmorClickIcon",
		L"clacialSpikeClickIcon",
		L"blizzardClickIcon",
		L"chillingArmorClickIcon",
		L"frozenOrbClickIcon",
		L"coldMasteryClickIcon",

		L"chargedBoltClickIcon",
		L"staticFieldClickIcon",
		L"telekinesisClickIcon",
		L"noveClickIcon",
		L"lightningClickIcon",
		L"chainLightningClickIcon",
		L"teleportClickIcon",
		L"thunderStormClickIcon",
		L"energyShieldClickIcon",
		L"lightningMasteryClickIcon",

		L"fireBoltClickIcon",
		L"warmthClickIcon",
		L"infernoClickIcon",
		L"blazeClickIcon",
		L"fireBallClickIcon",
		L"fireWallClickIcon",
		L"enchantClickIcon",
		L"meteorClickIcon",
		L"fireMasteryClickIcon",
		L"hydraClickIcon",

		L"normalAttackClickIcon"
	};
	eSkillFunctionType skillFunctionTypes[(int)eSkillType::END] = {
		eSkillFunctionType::Straight,// L"iceBoltIcon",
		eSkillFunctionType::Straight,// L"frozenArmorIcon",
		eSkillFunctionType::Straight,// L"frostNovaIcon",
		eSkillFunctionType::Straight,// L"iceBlastIcon",
		eSkillFunctionType::Buff,// L"shiverArmorIcon",
		eSkillFunctionType::Straight,// L"clacialSpikeIcon",
		eSkillFunctionType::MutiFall,// L"blizzardIcon",
		eSkillFunctionType::Buff,// L"chillingArmorIcon",
		eSkillFunctionType::Straight,// L"frozenOrbIcon",
		eSkillFunctionType::Passive,// L"coldMasteryIcon",

		eSkillFunctionType::Straight,// L"chargedBoltIcon",
		eSkillFunctionType::Straight,// L"staticFieldIcon",
		eSkillFunctionType::Straight,// L"telekinesisIcon",
		eSkillFunctionType::Straight,// L"noveIcon",
		eSkillFunctionType::Straight,// L"lightningIcon",
		eSkillFunctionType::Straight,// L"chainLightningIcon",
		eSkillFunctionType::Straight,// L"teleportIcon",
		eSkillFunctionType::Straight,// L"thunderStormIcon",
		eSkillFunctionType::Straight,// L"energyShieldIcon",
		eSkillFunctionType::Passive,// L"lightningMasteryIcon",

		eSkillFunctionType::Straight,// L"fireBoltIcon",
		eSkillFunctionType::Passive,// L"warmthIcon",
		eSkillFunctionType::Straight,// L"infernoIcon",
		eSkillFunctionType::Straight,// L"blazeIcon",
		eSkillFunctionType::Straight,// L"fireBallIcon",
		eSkillFunctionType::Straight,// L"fireWallIcon",
		eSkillFunctionType::Buff,// L"enchantIcon",
		eSkillFunctionType::Straight,// L"meteorIcon",
		eSkillFunctionType::Passive,// L"fireMasteryIcon",
		eSkillFunctionType::Straight,// L"hydraIcon",

		//Monster
		eSkillFunctionType::MultiStraight,// L"diabloLightning",

		eSkillFunctionType::None,// L"normalAttackIcon"
	};
	int SkillDamageCofTable[(int)eSkillType::END] = {
		10,// L"iceBolt",
		0,// L"frozenArmor",
		10,// L"frostNova",
		10,// L"iceBlast",
		0,// L"shiverArmor",
		10,// L"clacialSpike",
		10,// L"blizzard",
		0,// L"chillingArmor",
		10,// L"frozenOrb",
		0,// L"coldMastery",

		10,// L"chargedBolt",
		10,// L"staticField",
		10,// L"telekinesis",
		10,// L"nove",
		10,// L"lightning",
		10,// L"chainLightning",
		0,// L"teleport",
		10,// L"thunderStorm",
		0,// L"energyShield",
		0,// L"lightningMastery",

		10,// L"fireBolt",
		0,// L"warmth",
		10,// L"inferno",
		10,// L"blaze",
		10,// L"fireBall",
		10,// L"fireWall",
		0,// L"enchant",
		10,// L"meteor",
		0,// L"fireMastery",
		10,// L"hydra",

		//Monster
		5,// L"diabloLightning",

		0,// L"normalAttack"
	};
	std::wstring skillAnimNames[(int)eSkillType::END] = {
		L"iceBolt", // L"iceBoltClickIcon",
		L"frozenArmor", // L"frozenArmorClickIcon",
		L"frostNova", // L"frostNovaClickIcon",
		L"iceBlast", // L"iceBlastClickIcon",
		L"shiverArmor", // L"shiverArmorClickIcon",
		L"clacialSpike", // L"clacialSpikeClickIcon",
		L"blizzard", // L"blizzardClickIcon",
		L"chillingArmor", // L"chillingArmorClickIcon",
		L"frozenOrb", // L"frozenOrbClickIcon",
		L"coldMastery", // L"coldMasteryClickIcon",
		// 
		L"chargedBolt",// L"chargedBoltClickIcon",
		L"staticField",// L"staticFieldClickIcon",
		L"telekinesis",// L"telekinesisClickIcon",
		L"nove",// L"noveClickIcon",
		L"lightning",// L"lightningClickIcon",
		L"chainLightning",// L"chainLightningClickIcon",
		L"teleport",// L"teleportClickIcon",
		L"thunderStorm",// L"thunderStormClickIcon",
		L"energyShield",// L"energyShieldClickIcon",
		L"lightningMastery",// L"lightningMasteryClickIcon",
		// 
		L"fireBolt", // L"fireBoltClickIcon",
		L"warmth", // L"warmthClickIcon",
		L"inferno", // L"infernoClickIcon",
		L"blaze", // L"blazeClickIcon",
		L"fireBall", // L"fireBallClickIcon",
		L"fireWall", // L"fireWallClickIcon",
		L"enchant", // L"enchantClickIcon",
		L"meteor", // L"meteorClickIcon",
		L"fireMastery", // L"fireMasteryClickIcon",
		L"hydra", // L"hydraClickIcon",
		// 

		L"",// L"normalAttackClickIcon"

		// Monster
		L"diabloLightning",
	};
	int iColdSkillIndex[(int)eColdSkillType::END][2] = {
		{1,0},// L"iceBoltIcon",
		{2,0},// L"frozenArmorIcon",
		{0,1},// L"frostNovaIcon",
		{1,1},// L"iceBlastIcon",
		{2,2},// L"shiverArmorIcon",
		{1,3},// L"clacialSpikeIcon"
		{0,4},// L"blizzardIcon",
		{2,4},// L"chillingArmorIcon
		{0,5},// L"frozenOrbIcon",
		{1,5},// L"coldMasteryIcon",
	};
	int iLightSkillIndex[(int)eLightningSkillType::END][2] = {
		{1,0},// L"chargedBoltIcon",
		{0,1},// L"staticFieldIcon",
		{2,1},// L"telekinesisIcon",
		{0,2},// L"noveIcon",
		{1,2},// L"lightningIcon",
		{1,3},// L"chainLightningIcon",
		{2,3},// L"teleportIcon",
		{0,4},// L"thunderStormIcon",
		{2,4},// L"energyShieldIcon",
		{1,5},// L"lightningMasteryIcon",
	};
	int iFireSkillIndex[(int)eFireSkillType::END][2] = {
		{1,0},// L"fireBoltIcon",
		{2,0},// L"warmthIcon",
		{0,1},// L"infernoIcon",
		{0,2},// L"blazeIcon",
		{1,2},// L"fireBallIcon",
		{0,3},// L"fireWallIcon",
		{2,3},// L"enchantIcon",
		{1,4},// L"meteorIcon",
		{1,5},// L"fireMasteryIcon",
		{2,5},// L"hydraIcon",
	};
	
	std::wstring wsColdSkillNames[(int)eColdSkillType::END] = {
		L"iceBoltIcon",
		L"frozenArmorIcon",
		L"frostNovaIcon",
		L"iceBlastIcon",
		L"shiverArmorIcon",
		L"clacialSpikeIcon",
		L"blizzardIcon",
		L"chillingArmorIcon",
		L"frozenOrbIcon",
		L"coldMasteryIcon",
	};
	std::wstring wsLightningSkillNames[(int)eLightningSkillType::END] = {
		L"chargedBoltIcon",
		L"staticFieldIcon",
		L"telekinesisIcon",
		L"noveIcon",
		L"lightningIcon",
		L"chainLightningIcon",
		L"teleportIcon",
		L"thunderStormIcon",
		L"energyShieldIcon",
		L"lightningMasteryIcon",
	};

	std::wstring wsFireSkillNames[(int)eFireSkillType::END] = {
		L"fireBoltIcon",
		L"warmthIcon",
		L"infernoIcon",
		L"blazeIcon",
		L"fireBallIcon",
		L"fireWallIcon",
		L"enchantIcon",
		L"meteorIcon",
		L"fireMasteryIcon",
		L"hydraIcon",
	};



	std::wstring wsColdSkillClickNames[(int)eColdSkillType::END] = {
		L"iceBoltClickIcon",
		L"frozenArmorClickIcon",
		L"frostNovaClickIcon",
		L"iceBlastClickIcon",
		L"shiverArmorClickIcon",
		L"clacialSpikeClickIcon",
		L"blizzardClickIcon",
		L"chillingArmorClickIcon",
		L"frozenOrbClickIcon",
		L"coldMasteryClickIcon",
	};

	std::wstring wsLightningSkillClickNames[(int)eLightningSkillType::END] = {
		L"chargedBoltClickIcon",
		L"staticFieldClickIcon",
		L"telekinesisClickIcon",
		L"noveClickIcon",
		L"lightningClickIcon",
		L"chainLightningClickIcon",
		L"teleportClickIcon",
		L"thunderStormClickIcon",
		L"energyShieldClickIcon",
		L"lightningMasteryClickIcon",
	};

	std::wstring wsFireSkillClickNames[(int)eFireSkillType::END] = {
		L"fireBoltClickIcon",
		L"warmthClickIcon",
		L"infernoClickIcon",
		L"blazeClickIcon",
		L"fireBallClickIcon",
		L"fireWallClickIcon",
		L"enchantClickIcon",
		L"meteorClickIcon",
		L"fireMasteryClickIcon",
		L"hydraClickIcon",
	};
	
	int iColdAdjacencyMatrix[(int)eColdSkillType::END][(int)eColdSkillType::END] = {
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},// 	L"iceBoltIcon",
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},// 	L"frozenArmorIcon",",
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},// 	L"frostNovaIcon",,
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0},// 	L"iceBlastIcon",
		{0, 1, 0, 1, 0, 0, 0, 0, 0, 0},// 	L"shiverArmorIcon",
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},// 	L"clacialSpikeIcon",
		{0, 0, 1, 0, 0, 1, 0, 0, 0, 0},// 	L"blizzardIcon",
		{0, 0, 0, 0, 1, 0, 0, 0, 0, 0},// 	L"chillingArmorIcon",
		{0, 0, 0, 0, 0, 0, 1, 0, 0, 0},//	L"frozenOrbIcon",
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},//	L"coldMasteryIcon",
	};
	int iLightAdjacencyMatrix[(int)eLightningSkillType::END][(int)eLightningSkillType::END] = {
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},// L"chargedBoltIcon",
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},// L"staticFieldIcon",
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},// L"telekinesisIcon",
		{0, 1, 0, 0, 0, 0, 0, 0, 0, 0},// L"noveIcon",
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0},// L"lightningIcon",
		{0, 0, 0, 0, 1, 0, 0, 0, 0, 0},// L"chainLightningIcon",
		{0, 0, 1, 0, 0, 0, 0, 0, 0, 0},// L"teleportIcon",
		{0, 0, 0, 1, 0, 1, 0, 0, 0, 0},// L"thunderStormIcon",
		{0, 0, 0, 0, 0, 0, 1, 0, 0, 0},// L"energyShieldIcon",
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},// L"lightningMasteryIcon",
	};
	int iFireAdjacencyMatrix[(int)eFireSkillType::END][(int)eFireSkillType::END] = {
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},//L"fireBoltIcon",
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},//L"warmthIcon",
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},//L"infernoIcon",
		{0, 0, 1, 0, 0, 0, 0, 0, 0, 0},//L"blazeIcon",
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0},//L"fireBallIcon",
		{0, 0, 0, 1, 0, 0, 0, 0, 0, 0},//L"fireWallIcon",
		{0, 1, 0, 0, 0, 0, 0, 0, 0, 0},//L"enchantIcon",
		{0, 0, 0, 0, 1, 1, 0, 0, 0, 0},//L"meteorIcon",
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},//L"fireMasteryIcon",
		{0, 0, 0, 0, 0, 0, 1, 0, 0, 0},//L"hydraIcon",
	};
	
}