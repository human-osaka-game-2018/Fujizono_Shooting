#pragma once

#include "Object.h"
#include <vector>

/**
* オブジェクトを管理するクラス
*/
class ObjectManager
{
public:

	ObjectManager();
	~ObjectManager();

	/**
	* @brief インスタンスを生成する関数
	*/
	void Initialize();

	/**
	* @brief インスタンスを破棄する関数
	*/
	void Release();

	/**
	* @brief オブジェクトを登録する関数
	* @param 登録したい派生クラスのポインタ
	*/
	void RegisterObject(Object*);

	/**
	* @brief オブジェクトを解放する関数
	*/
	void ReleaseObject();

	/**
	* @brief 操作関数
	*/
	void Update();

	/**
	* @brief 描画関数
	*/
	void Render();

private:

	std::vector<Object*> m_pObjectVec;
};

