#include "../GameLib/GameLib.h"
#include "../Scene/TitleScene/TitleScene.h"

const int WindowWidth = 640;
const int WindowHeight = 480;

// �G���g���[�|�C���g
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// GameLib�̏�����
	GameLib::Instance.Initialize(L"Shooting", WindowWidth, WindowHeight, false);

	// �V�X�e���V�[���֑J�ڂ���
	SCENEMANAGER->ChangeScene(new TitleScene);

	GameLib::Instance.MainLoop();

	// DirectXLib�̉��
	GameLib::Instance.Release();

	return 0;
}
