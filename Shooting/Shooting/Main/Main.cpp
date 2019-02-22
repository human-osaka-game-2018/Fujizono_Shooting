#include "../GameLib/GameLib.h"
#include "../Scene/TitleScene/TitleScene.h"

// エントリーポイント
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// GameLibの初期化
	GameLib::Instance.Initialize(L"Shooting", 640, 480, false);

	// システムシーンへ遷移する
	SCENEMANAGER->ChangeScene(new TitleScene);

	GameLib::Instance.MainLoop();

	// DirectXLibの解放
	GameLib::Instance.Finalize();

	return 0;
}
