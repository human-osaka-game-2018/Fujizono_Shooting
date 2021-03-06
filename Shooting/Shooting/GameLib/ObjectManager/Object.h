#pragma once

/**
* @brief Objectの基底クラス
*/
class Object
{
public:

	Object();
	virtual ~Object();

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

	bool m_canRender = true; //!<　描画できるかどうか
};
