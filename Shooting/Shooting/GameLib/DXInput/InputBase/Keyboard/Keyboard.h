#pragma once

#include <windows.h>

#include <dinput.h>

#include "../InputBase.h"

/**
* @brief キーボードクラス,基底クラスのInputBaseを参照して下さい
*/
class Keyboard :public InputBase
{
public:
	Keyboard(HWND hWnd, LPDIRECTINPUT8 pDXInput) : InputBase(hWnd)
	{
		Create(pDXInput);
	};

	~Keyboard() {};

	inline VOID UpdataInputState()		//メインループの始まりで用いる
	{
		AcquireInputState();
		CheckInputStateDetatils();
	}

	inline VOID StorePrevInputState()	//メインループの終わりで用いる
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

		m_pDInputDev->Acquire();		//キーボードの状態を取得する権限の取得

		m_pDInputDev->GetDeviceState(	//キーボードの状態を取得
			sizeof(BYTE) * 256,
			m_diks);
	}

	VOID CheckInputStateDetatils();		//AcquireInputState()を読んだ後に用いる

	BYTE m_diks[256];					//現在ののフレームでキーが押されていた場合上位ビットが立つ
	BYTE m_prevDiks[256];				//前回のフレームでキーが押されていた場合上位ビットが立つ

	INPUT_DETAIL m_details[256];
};
