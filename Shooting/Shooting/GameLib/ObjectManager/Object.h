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
	virtual bool Initialize();

	/**
	* @brief ������s���֐�
	*/
	virtual void Finalize();

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