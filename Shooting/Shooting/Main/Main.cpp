#include "../GameLib/GameLib.h"
#include "../Scene/TitleScene/TitleScene.h"

const int WindowWidth = 640;
const int WindowHeight = 480;

// エントリーポイント
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// GameLibの初期化
	GameLib::Instance.Initialize(L"Shooting", WindowWidth, WindowHeight, false);

	// システムシーンへ遷移する
	SCENEMANAGER->ChangeScene(new TitleScene);

	GameLib::Instance.MainLoop();

	// DirectXLibの解放
	GameLib::Instance.Release();

	return 0;
}
