#pragma once

#include "../../GameLib/SceneManager/SceneBase/SceneBase.h"

/**
* @brief �^�C�g���V�[���̃N���X
*/
class TitleScene : public SceneBase
{
public:

	TitleScene();
	~TitleScene();

	/**
	* @brief �������֐�
	*/
	bool Initialize();

	/**
	* @brief ����֐�
	*/
	void Finalize();

	/**
	* @brief ����֐�
	*/
	void Update();

	/**
	* @brief �`��֐�
	*/
	void Render();

};
