#pragma once

#include "../../../GameLib/ObjectManager/Object2DBase.h"
#include "../../../GameLib/DirectX/DirectX.h"
#include "../../../GameLib/2DHelper/2DHelper.h"
#include "../../../GameLib/Texture/Texture.h"


/**
* @brief タイトルの背景関係の処理をまとめたクラス
*/
class TitleBackground : public Object2DBase
{
public:

	TitleBackground();
	~TitleBackground();

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
	const char* m_TexturePath = "../Graphics/Title_BG.jpg";
};

