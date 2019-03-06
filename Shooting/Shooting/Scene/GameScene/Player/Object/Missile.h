#pragma once

#include "GameLib/ObjectManager/Object2DBase.h"
#include "GameLib/DirectX/DirectX.h"
#include "GameLib/2DHelper/2DHelper.h"
#include "GameLib/Texture/Texture.h"
#include <vector>

class Missile :public Object2DBase
{
public:

	Missile();
	~Missile();

	/**
	* @brief 初期化する関数
	*/
	void Initialize();

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

	/**
	* @brief ミサイルの生成関数
	* @param 発射時点での自機のX座標
	* @param 発射時点での自機のY座標
	*/
	void Create(float missile_x, float missile_y);

private:
	
	struct MissileInfo
	{
		MissileInfo(float x, float y);

		Simple2DVertex vertex[4];
		float x = 0;
		float y = 0;
	};

	std::vector<MissileInfo> m_missiles;
};
