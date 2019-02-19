#pragma once

#include <windows.h>

#include <dinput.h>

#include "../InputBase.h"
#include "DIM.h"

/**
* @brief �}�E�X�N���X,���N���X��InputBase���Q�Ƃ��ĉ�����
*/
class Mouse :public InputBase
{
public:
	Mouse(HWND hWnd, LPDIRECTINPUT8 pDXInput) : InputBase(hWnd)
	{
		Create(pDXInput);
	};

	~Mouse() {};

	inline VOID UpdataInputState()						//���C�����[�v�̎n�܂�ŗp����
	{
		AcquireInputState();
		CheckInputStateDetatils();
	}

	inline VOID StorePrevInputState()					//���C�����[�v�̏I���ŗp����
	{
		memcpy(&m_prevState, &m_state, sizeof(DIMOUSESTATE));
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
		for (INT i = 0; i < DIM_MAX; ++i)
		{
			if (IsPressed(i)) return TRUE;
		}

		return FALSE;
	}

	inline VOID CursorPos(POINT* pPos) const
	{
		*pPos = m_cursorRelativePos;
	}

	inline LONG WheelScrollingFromPrev() const
	{
		return m_state.lZ;
	}

private:
	VOID Create(LPDIRECTINPUT8 pDXInput);

	inline VOID AcquireInputState()
	{
		m_pDInputDev->Acquire();						//�}�E�X�̏�Ԃ��擾���錠���̎擾

		GetCursorPos(&m_cursorRelativePos);				//�����ł͂܂��f�B�X�v���C��̐�΍��W
		ScreenToClient(m_HWND, &m_cursorRelativePos);	//�����ŃE�B���h�E��̑��΍��W�ɕϊ�

		m_pDInputDev->GetDeviceState(					//�}�E�X�̏�Ԃ��擾
			sizeof(DIMOUSESTATE),
			&m_state);
	}

	VOID CheckInputStateDetatils();						//AcquireInputState()��ǂ񂾌�ɗp����

	DIMOUSESTATE m_state;
	DIMOUSESTATE m_prevState;

	POINT m_cursorRelativePos;							//�J�[�\���̃E�B���h�E��̑��΍��W

	INPUT_DETAIL m_details[DIM_MAX];
};
