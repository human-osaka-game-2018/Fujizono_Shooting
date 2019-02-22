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

//����������
bool PressEnter::Initialize()
{
	DEBUGFONT->Initialize(50);

	return true;
}

//�������
void PressEnter::Finalize()
{
	DEBUGFONT->Finalize();
}

//�X�V����
void PressEnter::Update()
{
	//�t���[���o�߂ŐF����ς���
	frameCount++;
	if (frameCount > 60)
	{
		//�J���[�����l�B������A�t���[���J�E���g��0�ɖ߂�
		(regulateColor <= static_cast<DWORD>(0x02ffffff)) ? frameCount = 0 : frameCount;

		regulateColor -= static_cast<DWORD>(0x03000000);
	}

	if (DIRECT_INPUT->KeyboardIsReleased(DIK_RETURN))
	{
		SCENEMANAGER->ChangeScene(new GameScene);
	}
}


//�`�悷��
void PressEnter::Render()
{
	/*char s[100];
	sprintf_s(s, 100, "PRESS ENTER");*/
	DEBUGFONT->DrawText(185, 400, regulateColor, "PRESS ENTER");
}
