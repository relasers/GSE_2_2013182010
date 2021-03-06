#pragma once
#include "stdafx.h"
#include "Renderer.h"
#include "PhysicVector.h"

#define LIFE_CHARACTER 100
#define LIFE_BUILDING 500
#define LIFE_BULLET 15
#define LIFE_ARROW 10

#define SPEED_CHARACTER 300
#define SPEED_BUILDING 0
#define SPEED_BULLET 600
#define SPEED_ARROW 100

#define SIZE_CHARACTER 30
#define SIZE_BUILDING 100
#define SIZE_BULLET 4
#define SIZE_ARROW 4

#define LEVEL_GROUND_CHARACTER 0.5
#define LEVEL_AIR_CHARACTER 0.2
#define LEVEL_BUILDING 0.3
#define LEVEL_BULLET 0.4
#define LEVEL_ARROW 0.4

#define COLOR_RED_CHARACTER {1,0,0,1}
#define COLOR_RED_BUILDING {1,0.6942f,0.3978f,1}
#define COLOR_RED_BULLET {1,0,0,1}
#define COLOR_RED_ARROW {0.5,0,2,0.7,1}

#define COLOR_BLUE_CHARACTER {0,0,1,1}
#define COLOR_BLUE_BUILDING {1,0.6942f,0.3978f,1}
#define COLOR_BLUE_BULLET {0,0,1,1}
#define COLOR_BLUE_ARROW {1,1,0,1}

const string Texture_Building[2] = 
{
	{ "./Textures/Barn-Sheet.png" },
	{ "./Textures/Outpost2-Sheet.png" }
};

const string Texture_Unit[2] =
{
	{ "./Textures/Crinoid-Sheet.png" },
	{ "./Textures/TheGeminiXii-Sheet.png" }
};

const string Texture_Particle[2] =
{
	{ "./Textures/Flame.png" },
	{ "./Textures/Snow.png" }
};



const int Sprite_Building_Seq[2] = {
	{ 8 },	// Barn
	{ 10 }		// OutPost
};

const int Sprite_Unit_Seq[2] = {
	{ 5 },		// Crinoid
	{ 9 }		// Gemini
};


const Color Color_TEAM[2] = {
	{ 1,0,0,1 },	// RED TEAM
	{ 0,0,1,1 }		// BLUE TEAM
};

const Color Color_Character[2] = {
	{ 1,0.7f,0.7f,1 },	// RED TEAM
	{ 0.7f,0.7f,1,1 }		// BLUE TEAM
};

//{ 1,0.6942f,0.3978f,1 }
const Color Color_Building[2] = {
	{ 1,0.7f,0.7f,1 },	// RED TEAM
	{ 0.7f,0.7f,1,1 }		// BLUE TEAM
};

const Color Color_Bullet[2] = {
	//{ 1,0,0,1 },	// RED TEAM
	//{ 0,0,1,1 }		// BLUE TEAM
	{ 1,1,1,1 },	// RED TEAM
	{ 1,1,1,1 }		// BLUE TEAM
};

const Color Color_Arrow[2] = {
	{ 0.5f,0.2f,0.7f,1 },	// RED TEAM
	{ 1,1,0,1 }		// BLUE TEAM
};

const Vector3f Position_Building[6] = {
	{ -CLIENT_WIDTH*0.25,CLIENT_HEIGHT*0.25,0 },
	{ 0,CLIENT_HEIGHT*0.35,0 },
	{ CLIENT_WIDTH*0.25,CLIENT_HEIGHT*0.25,0 },	// RED TEAM
	{ -CLIENT_WIDTH*0.25,-CLIENT_HEIGHT*0.35,0 },
	{ 0,-CLIENT_HEIGHT*0.45,0 },
	{ CLIENT_WIDTH*0.25,-CLIENT_HEIGHT*0.35,0 }
};


enum class OBJECT_TYPE;
enum class TEAM_TYPE;
enum class DEPTH_TYPE;

class CGameObject
{
protected:
	Renderer *m_Renderer = nullptr;
	GLuint m_texCharacter;
	GLuint m_texParticle;

	void* m_parent = nullptr;
	Vector3f m_Position{0,0,0};
	Vector3f m_Direction{ 0,0,0 };

	float m_Speed{ 0 };
	float m_Size{0};
	Color m_Color{0,0,0,1};
	OBJECT_TYPE m_Type;
	TEAM_TYPE m_Team;
	DEPTH_TYPE m_DepthType;

	// 렌더링 순서 정의
	float m_RenderingLevel{0};

	float m_maxlife{ 1 };
	float m_life{ 1 };
	float m_lifetime{ 0 };

	float m_shootTimer = 0;

	float m_frametick;
	float m_particletick = 0.0f;
	float m_changedir_tick = 0.0f;

	float m_maxframe;
public:
	CGameObject();
	CGameObject(Renderer *Renderer);
	CGameObject(Renderer *Renderer, Vector3f position, Vector3f direction, OBJECT_TYPE type);
	CGameObject(Renderer *Renderer, Vector3f position, Vector3f direction, float speed, float size, Color color, OBJECT_TYPE type);
	~CGameObject();

	void SetPosition(Vector3f position) { m_Position = position; };
	void SetDirection(Vector3f direction) { m_Direction = direction; };

	void SetColor(Color color) { m_Color = color; };
	void SetSize(float size) { m_Size = size; }
	void SetParentPointer(void* parent) { m_parent = parent; };

	// 텍스쳐 이름으로 텍스쳐 셋하기
	void SetTexture(char* texture);

	void SetLife(float life) { m_life = life; }
	float GetLife() const { return m_life; }
	Vector3f GetPosition() const { return m_Position; }
	Vector3f GetDirection() const { return m_Direction; }

	bool LifeCheck();

	float GetShootTimer() const { return m_shootTimer; };
	void SetShootTimer(float timer) { m_shootTimer = timer; };

	float GetChangeDirTimer() const { return m_changedir_tick; };
	void SetChangeDirTimer(float timer) { m_changedir_tick = timer; };

	

	void SetTeam(TEAM_TYPE type);
	TEAM_TYPE GetTeam() const { return m_Team; }
	DEPTH_TYPE GetDepthType() const { return m_DepthType; }
	virtual bool Render();
	virtual bool Update(float fTimeElapsed);

	void SetTexturePtr(GLuint texture) { m_texCharacter = texture; }
};