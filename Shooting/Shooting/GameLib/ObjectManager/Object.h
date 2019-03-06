#pragma once

/**
* @brief Object�̊��N���X
*/
class Object
{
public:

	Object();
	virtual ~Object();

	/**
	* @brief ���������s���֐�
	*/
	virtual void Initialize();

	/**
	* @brief ������s���֐�
	*/
	virtual void Release();

	/**
	* @brief ����̍X�V���s���֐�
	*/
	virtual void Update();

	/**
	* @brief �`����s���֐�
	*/
	virtual void Render();

protected:

	bool m_canRender = true; //!<�@�`��ł��邩�ǂ���
};
