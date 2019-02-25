#include "PressEnter.h"
#include "../../../GameLib/GameLib.h"
#include "../../GameScene/GameScene.h"


PressEnter::PressEnter()
{
	Initialize();
}

PressEnter::~PressEnter()
{
	Release();
}

//初期化する
bool PressEnter::Initialize()
{
	DEBUGFONT->Initialize(m_FontSize);

	return true;
}

//解放する
void PressEnter::Release()
{
	DEBUGFONT->Release();
}

//更新する
void PressEnter::Update()
{
	//フレーム経過で色情報を変える
	m_frameCount++;

	if (m_frameCount > m_ChangeColorTime)
	{

		//カラーが一定値達したら、フレームカウントを0に戻す
		if (m_Color <= static_cast<DWORD>(0x02ffffff))
		{
			m_frameCount = 0;
		}

		m_Color -= static_cast<DWORD>(0x03000000);
	}

	if (DIRECT_INPUT->KeyboardIsReleased(DIK_RETURN))
	{
		SCENEMANAGER->ChangeScene(new GameScene);
	}
}

//描画する
void PressEnter::Render()
{
	DEBUGFONT->DrawText(m_Text_x, m_Text_y, m_Color, m_PressEnter);
}
