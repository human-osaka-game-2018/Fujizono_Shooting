#pragma once

#include <windows.h>

#include <dinput.h>

/**
* @brief ���̓f�o�C�X�̊��N���X
*/
class InputBase
{
public:
	InputBase(HWND hWnd) :m_HWND(hWnd) {};

	virtual ~InputBase()
	{
		m_pDInputDev->Release();
	}

	/**
	* @brief ���̓f�o�C�X�̏�Ԃ̎擾,���̌�ڍׂȐU�蕪�����s��,���b�Z�[�W���[�v�̎n�܂�ŌĂ�
	*/
	virtual VOID UpdataInputState() = 0;

	/**
	* @brief ���͏�Ԃ̏ڍׂȐU�蕪�����s�����ߓ��͏�Ԃ̕ۑ����s��,���b�Z�[�W���[�v�̏I���ŌĂ�
	*/
	virtual VOID StorePrevInputState() = 0;

	/**
	* @brief �����̃L�[�������ꂽ�u�Ԃ���Ԃ�
	* @param key ���ʂ������L�[�̔ԍ�,�}�E�X�̏ꍇDIM�񋓑�,�L�[�{�[�h�̏ꍇDIK�萔
	* @return �����ꂽ�u�Ԃ̏ꍇTRUE,�����łȂ����FALSE
	*/
	virtual BOOL IsPressed(INT key) const = 0;

	/**
	* @brief �����̃L�[��������Ă��邩��Ԃ�
	* @param key ���ʂ������L�[�̔ԍ�,�}�E�X�̏ꍇDIM�񋓑�,�L�[�{�[�h�̏ꍇDIK�萔
	* @return ������Ă���ꍇTRUE,�����łȂ����FALSE
	*/
	virtual BOOL IsHeld(INT key) const = 0;

	/**
	* @brief �����̃L�[���͂Ȃ��ꂽ�u�Ԃ���Ԃ�
	* @param key ���ʂ������L�[�̔ԍ�,�}�E�X�̏ꍇDIM�񋓑�,�L�[�{�[�h�̏ꍇDIK�萔
	* @return �͂Ȃ��ꂽ�u�Ԃ̏ꍇTRUE,�����łȂ����FALSE
	*/
	virtual BOOL IsReleased(INT key) const = 0;

	/**
	* @brief �����̃L�[���͂Ȃ���Ă��邩��Ԃ�
	* @param key ���ʂ������L�[�̔ԍ�,�}�E�X�̏ꍇDIM�񋓑�,�L�[�{�[�h�̏ꍇDIK�萔
	* @return �͂Ȃ���Ă���ꍇTRUE,�����łȂ����FALSE
	*/
	virtual BOOL IsNeutral(INT key) const = 0;

	/**
	* @brief �������͂��ꂽ��Ԃ�
	* @return ���͂���Ă�����TRUE
	*/
	virtual BOOL AnyKeyIsPressed() const = 0;

protected:
	enum INPUT_DETAIL
	{
		IND_PRESS,										//�����ꂽ�u�Ԃ̃t���[������TRUE
		IND_HOLD,										//�����ꑱ�����Ă����TRUE
		IND_RELEASE,									//�����ꂽ�u�Ԃ̃t���[������TRUE
		IND_NEUTRAL,									//�O��ƌ��݂̃t���[���ŉ�����Ă��Ȃ���TRUE
		IND_MAX
	};

	virtual VOID AcquireInputState() = 0;
	virtual VOID CheckInputStateDetatils() = 0;

	inline BOOL IsInputted(const BYTE& rKey) const
	{
		return (rKey & 0x80);
	}

	const HWND m_HWND = nullptr;

	LPDIRECTINPUTDEVICE8 m_pDInputDev = nullptr;
};
