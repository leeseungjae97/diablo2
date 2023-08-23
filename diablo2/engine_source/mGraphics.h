#pragma once
#include <wrl.h>
#include <d3d11.h>
#include <d3dcompiler.h>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dcompiler.lib")

#include "mEnums.h"
#include "mMath.h"
#include "mCamera.h"

#define CB_GETBINDSLOT(name) __CBUFFERBINDSLOT__##name##__
#define CBUFFER(name, slot) static const int CB_GETBINDSLOT(name) = slot; struct alignas(16) name 

#define CBSLOT_TRANSFORM		0
#define CBSLOT_GRID				2
#define CBSLOT_ANIMATOR			3
#define CBSLOT_UV				4
#define CBSLOT_PARTICLE			5
#define CBSLOT_NOISE			6
#define CBSLOT_TILE				7
enum class eShaderStage
{
	VS,
	HS,
	DS,
	GS,
	PS,
	CS,
	END,
};

enum class eSamplerType
{
	Point,
	Anisotropic,
	End,
};

enum class eCBType
{
	Transform,
	Material,
	Grid,
	Animator,
	UVControl,
	Particle,
	Noise,
	Tile,
	END,
};
enum class eRSType
{
	SolidBack,
	SolidFront,
	SolidNone,
	WireframeNone,
	End,
};

enum class eDSType
{
	Less,
	LessEqua,
	Greater,
	NoWrite,
	None,
	End,
};

enum class eBSType
{
	Default,
	AlphaBlend,
	OneOne,
	End,
};
enum class eRenderingMode
{
	Opaque,
	CutOut,
	Transparent,
	End,
};
enum class eViewType
{
	None,
	SRV,
	UAV,
	End,
};

struct GpuBuffer
{
	Microsoft::WRL::ComPtr<ID3D11Buffer> buffer;
	D3D11_BUFFER_DESC desc;

	GpuBuffer()
		: buffer(nullptr)
		, desc{}
	{

	}
	virtual ~GpuBuffer() = default;
};
struct LightAttribute
{
	m::math::Vector4 color;
	m::math::Vector4 position;
	m::math::Vector4 direction;

	m::enums::eLightType type;
	float radius;
	float angle;
	int pad;
};
struct DebugMesh
{
	m::enums::eColliderType type;
	m::math::Vector3 position;
	m::math::Vector3 rotation;
	m::math::Vector3 scale;
	m::math::Matrix view;
	m::math::Matrix projection;
	m::enums::eColor color;

	bool visible;
	float radius;
	float duration;
	float time;
};
struct PathFinderSharedData
{
	m::math::Vector2 startCoord;
	m::math::Vector2 targetCoord;
	float searchSize;
};
struct FoundedPath
{
	m::math::Vector2 foundPaths;
};
struct ComputeTile
{
	m::math::Vector4 tilePosition;
	m::math::Vector2 tileSize;
	m::math::Vector2 tileCoord;

	m::math::Vector2 parentCoord;
	m::math::Vector2 ttt;

	//bool isWall;
	//bool onMonster;
	//bool isWall1;
	//bool onMonster2;

	//UINT willOnMonsterCount;

	//bool inClose;
	//bool inOpen;

	//int G;
	//int H;

	//UINT openIndex;
	//UINT closedIndex;
	//UINT pathIndex;
};
struct ComputeTileSharedData
{
	m::math::Vector4 mousePos;
	m::math::Vector4 playerPos;
	UINT tileCount;
	UINT monsterCount;
	bool hoverUI;
};
struct PathfindingTile
{

};
struct ComputedTileCoord
{
	m::math::Vector2 mouseHoverTileCoord = m::math::Vector2(-1.f, -1.f);
	m::math::Vector2 playerStandTileCoord = m::math::Vector2(-1.f, -1.f);
};
struct ComputeMonster
{
	m::math::Vector4 monsterPos;
	m::math::Vector2 monsterNextCoord;
	UINT monsterCount;
};
struct ComputedMonsterCoord
{
	m::math::Vector2 monsterStandTileCoord = m::math::Vector2(-1.f, -1.f);
};
struct Vertex
{
	m::math::Vector3 pos;
	m::math::Vector4 color;
	m::math::Vector2 uv;
};
struct Particle
{
	m::math::Vector4 position;
	m::math::Vector4 direction;

	float alpha;
	float alpha2;
	float alpha3;
	float endTime;
	float time;
	float speed;
	UINT active;
};
struct ParticleShared
{
	UINT sharedActiveCount;
};