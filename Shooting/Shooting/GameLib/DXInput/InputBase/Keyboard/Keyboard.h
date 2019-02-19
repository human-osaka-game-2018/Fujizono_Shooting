#pragma once

#include <windows.h>

#include <dinput.h>

#include "../InputBase.h"

/**
* @brief �L�[�{�[�h�N���X,���N���X��InputBase���Q�Ƃ��ĉ�����
*/
class Keyboard :public InputBase
{
public:
	Keyboard(HWND hWnd, LPDIRECTINPUT8 pDXInput) : InputBase(hWnd)
	{
		Create(pDXInput);
	};

	~Keyboard() {};

	inline VOID UpdataInputState()		//���C�����[�v�̎n�܂�ŗp����
	{
		AcquireInputState();
		CheckInputStateDetatils();
	}

	inline VOID StorePrevInputState()	//���C�����[�v�̏I���ŗp����
	{
		memcpy(m_prevDiks, m_diks, sizeof(BYTE) * 256);
	}

	inline BOOL IsPressed(INT key) const
	{
		return (m_details[key] == IND_PRESS);
	}

	inline BOOL IsHeld(INT key) const
	{
		return (m_details[key] == IND_HOLD);
	}

	inline BOOL IsReleased(INT key) const
	{
		return (m_details[key] == IND_RELEASE);
	}

	inline BOOL IsNeutral(INT key) const
	{
		return (m_details[key] == IND_NEUTRAL);
	}

	inline BOOL AnyKeyIsPressed() const
	{
		const INT KEY_MAX = 256;
		for (INT i = 0; i < KEY_MAX; ++i)
		{
			if (IsPressed(i)) return TRUE;
		}

		return FALSE;
	}

private:
	VOID Create(LPDIRECTINPUT8 pDXInput);

	inline VOID AcquireInputState()
	{
		*m_pDInputDev;

		m_pDInputDev->Acquire();		//�L�[�{�[�h�̏�Ԃ��擾���錠���̎擾

		m_pDInputDev->GetDeviceState(	//�L�[�{�[�h�̏�Ԃ��擾
			sizeof(BYTE) * 256,
			m_diks);
	}

	VOID CheckInputStateDetatils();		//AcquireInputState()��ǂ񂾌�ɗp����

	BYTE m_diks[256];					//���݂̂̃t���[���ŃL�[��������Ă����ꍇ��ʃr�b�g������
	BYTE m_prevDiks[256];				//�O��̃t���[���ŃL�[��������Ă����ꍇ��ʃr�b�g������

	INPUT_DETAIL m_details[256];
};
