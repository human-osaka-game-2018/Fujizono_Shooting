#pragma once

#include "Object.h"
#include "../2DHelper/2DHelper.h"
#include "../Texture/Texture.h"

/**
* @brief ２Dオブジェクトの基底となるクラス
*/
class Object2DBase : public Object
{
public:

	Object2DBase();
	virtual ~Object2DBase();

	/**
	* @brief 初期化を行う関数
	*/
	virtual void Initialize();

	/**
	* @brief 解放を行う関数
	*/
	virtual void Release();

	/**
	* @brief 操作の更新を行う関数
	*/
	virtual void Update();

	/**
	* @brief 描画を行う関数
	*/
	virtual void Render();

protected:

	Texture         m_texture;
	Simple2DVertex  m_vertices[4]; //!< 矩形の4頂点
	bool m_canRender = true;       //!<　描画できるかどうか
};
