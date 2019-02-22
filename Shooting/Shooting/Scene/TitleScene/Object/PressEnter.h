#pragma once

#include "../../../GameLib/ObjectManager/Object2DBase.h"
#include "../../../GameLib/DirectX/DirectX.h"
#include "../../../GameLib/2DHelper/2DHelper.h"
#include "../../../GameLib/Texture/Texture.h"


/**
* @brief �^�C�g�����j���[�iPRESS�@ENTER�j�̏������܂Ƃ߂��N���X
*/
class PressEnter : public Object2DBase
{
public:

	PressEnter();
	~PressEnter();


	/**
	* @brief ����������֐�
	* @return ����������肭�ł��Ă��Ȃ���FALSE
	*/
	bool Initialize();

	/**
	* @brief �������֐�
	*/
	void Finalize();

	/**
	* @brief ����֐�
	* @param �^�C�g�����j���[�̉��Ԃ̃X�e�b�v��
	*/
	void Update();

	/**
	* @brief �`��֐�
	*/
	void Render();

private:
	DWORD regulateColor = static_cast<DWORD>(0xffffffff);
	int frameCount = 0;     //!< �t���[���𐔂��邽�߂̕ϐ�
};

