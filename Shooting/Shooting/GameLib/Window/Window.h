#pragma once

#include <Windows.h>

/**
* @brief �E�B���h�E�֌W�̏������܂Ƃ߂��N���X
*/
class Window
{
public:

	Window();
	~Window();

	/**
	* @brief �E�B���h�E�������s���֐�
	* @param �E�B���h�E�̖��O
	* @param �E�B���h�E�̉���
	* @param �E�B���h�E�̏c��
	*/
	bool Create(const wchar_t* pName, int width, int height);

	/**
	* @brief ���b�Z�[�W�̍X�V
	*/
	bool UpdateMessage();

	/**
	* @brief �I���ʒm�����Ă��邩
	*/
	bool IsQuitMessage() { return m_isQuitMessage; }

	/**
	* @brief�E�B���h�E�n���h���̎擾
	*/
	HWND GetHandle() { return m_hWnd; }

	/**
	* @brief �E�B���h�E�̉����擾
	*/
	int GetWidth(void) const { return m_width; }

	/**
	* @brief �E�B���h�E�̏c���擾
	*/
	int GetHeight(void) const { return m_height; }

private:

	/** �E�B���h�E�n���h�� */
	HWND m_hWnd;

	/** �E�B���h�E���t���X�N���[���� */
	bool m_isWindowMode;

	/** �I���ʒm�����Ă��邩 */
	bool m_isQuitMessage;

	/** �E�B���h�E�̉��� */
	int  m_width;

	/** �E�B���h�E�̏c�� */
	int  m_height;
};