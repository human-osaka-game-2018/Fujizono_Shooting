#include "PressEnter.h"
#include "../../../GameLib/GameLib.h"
#include "../../GameScene/GameScene.h"


PressEnter::PressEnter()
{
	Initialize();
}

PressEnter::~PressEnter()
{
	Finalize();
}

//初期化する
bool PressEnter::Initialize()
{
	DEBUGFONT->Initialize(50);

	return true;
}

//解放する
void PressEnter::Finalize()
{
	DEBUGFONT->Finalize();
}

//更新する
void PressEnter::Update()
{
	//フレーム経過で色情報を変える
	frameCount++;
	if (frameCount > 60)
	{
		//カラーが一定値達したら、フレームカウントを0に戻す
		(regulateColor <= static_cast<DWORD>(0x02ffffff)) ? frameCount = 0 : frameCount;

		regulateColor -= static_cast<DWORD>(0x03000000);
	}

	if (DIRECT_INPUT->KeyboardIsReleased(DIK_RETURN))
	{
		SCENEMANAGER->ChangeScene(new GameScene);
	}
}


//描画する
void PressEnter::Render()
{
	/*char s[100];
	sprintf_s(s, 100, "PRESS ENTER");*/
	DEBUGFONT->DrawText(185, 400, regulateColor, "PRESS ENTER");
}
