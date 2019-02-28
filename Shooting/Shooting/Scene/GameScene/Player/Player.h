#pragma once

#include "GameLib/ObjectManager/Object2DBase.h"
#include "GameLib/DirectX/DirectX.h"
#include "GameLib/2DHelper/2DHelper.h"
#include "GameLib/Texture/Texture.h"
#include "Object/Missile.h"

class Player : public Object2DBase
{
public:

	Player();
	~Player();

	/**
	* @brief 初期化する関数
	* @return 初期化が上手くできていないとFALSE
	*/
	bool Initialize();

	/**
	* @brief 解放する関数
	*/
	void Release();

	/**
	* @brief 操作関数
	*/
	void Update();

	/**
	* @brief 描画関数
	*/
	void Render();

private:
	
	Missile m_missile;

	//　弾の発射を制限するためのカウント
	int m_limitCount = 0;

	bool m_missileFlag = false;
	float m_missile_x = 0;
	float m_missile_y = 0;
};
