#pragma once
#include "stdafx.h"
#include "SolidCube.h"
#include "BackGround.h"
#include "Effect.h"
#include "Sound.h"

class CSolidCube;

class CSceneMgr
{
private:
	CBackGround*		m_pBackGround;
	CClimate*			m_pClimate;

	Sound*				m_pSound;

	int					m_Sound_BGM;
	int					m_Sound_Explosion;

	float				m_ShakeFactor;


	GLuint				m_texcharacter[2];

	GLuint				m_texbuilding[2];

	GLuint				m_texParticle[2];
	GLuint				m_texExplode;

	vector<CSolidCube*> Character;
	vector<CSolidCube*> Building;
	vector<CSolidCube*> Bullet;
	vector<CSolidCube*> Arrow;
	vector<CEffect*> Explode;

	Renderer *g_Renderer = NULL;

	float placement_tick = 0; // ���� ��ġ ��� ƽ
	float spawn_tick = 0; // ���� ��ȯ ��� ƽ
	float counter = 0;
public:
	CSceneMgr();
	~CSceneMgr();

	void Initialize();
	void BuildObjects();
	void ReleaseObjects();

	void Update(const double TimeElapsed);
	void Render();

	void Input_Key(unsigned char key, int x, int y);
	void Input_SpecialKey(int key, int x, int y);
	void Input_MouseButton(int button, int state, int x, int y);
};

