#pragma once

#include "../../../GameLib/ObjectManager/Object2DBase.h"
#include "../../../GameLib/DirectX/DirectX.h"
#include "../../../GameLib/2DHelper/2DHelper.h"
#include "../../../GameLib/Texture/Texture.h"


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
	* @return 初期化が上手くできていないとFALSE
	*/
	bool Initialize();

	/**
	* @brief 解放する関数
	*/
	void Finalize();

	/**
	* @brief 操作関数
	* @param タイトルメニューの何番のステップか
	*/
	void Update();

	/**
	* @brief 描画関数
	*/
	void Render();

private:
	DWORD regulateColor = static_cast<DWORD>(0xffffffff);
	int frameCount = 0;     //!< フレームを数えるための変数
};

