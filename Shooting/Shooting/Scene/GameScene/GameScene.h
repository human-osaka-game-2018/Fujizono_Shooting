#pragma once

#include "GameLib/SceneManager/SceneBase/SceneBase.h"

/**
* @brief �Q�[���V�[���̃N���X
*/
class GameScene : public SceneBase
{
public:

	GameScene();
	~GameScene();

	/**
	* @brief �������֐�
	*/
	bool Initialize();

	/**
	* @brief ����֐�
	*/
	void Release();

	/**
	* @brief ����֐�
	*/
	void Update();

	/**
	* @brief �`��֐�
	*/
	void Render();

};
