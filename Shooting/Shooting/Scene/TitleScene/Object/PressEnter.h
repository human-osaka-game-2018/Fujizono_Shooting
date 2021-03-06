﻿#pragma once

#include "GameLib/ObjectManager/Object2DBase.h"
#include "GameLib/DirectX/DirectX.h"
#include "GameLib/2DHelper/2DHelper.h"
#include "GameLib/Texture/Texture.h"


/**
* @brief タイトルメニュー（PRESS　ENTER）の処理をまとめたクラス
*/
class PressEnter : public Object2DBase
{
public:

	PressEnter();
	~PressEnter();


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

private:
	const int m_FontSize = 50;
	DWORD m_Color = static_cast<DWORD>(0xffffffff);
	int m_frameCount = 0;     //!< フレームを数えるための変数
	const int m_ChangeColorTime = 60;
	const char* m_PressEnter = "PRESS ENTER";
	const int m_Text_x = 185;
	const int m_Text_y = 400;
};

