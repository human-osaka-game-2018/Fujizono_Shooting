#include "TitleScene.h"
#include "Object/TitleBackground.h"
#include "Object/PressEnter.h"


TitleScene::TitleScene()
{
}

TitleScene::~TitleScene()
{
	Finalize();
}

//操作を更新する
void TitleScene::Update()
{
	//このシーンのオブジェクトの更新を行う
	m_pObjectManager->Update();
}

//描画する
void TitleScene::Render()
{
	//オブジェクトのRender
	m_pObjectManager->Render();
}

//初期化する
bool TitleScene::Initialize()
{
	//オブジェクトをNEWして、オブまねのVectorにつめる
	m_pObjectManager->RegisterObject(new TitleBackground);
	m_pObjectManager->RegisterObject(new PressEnter);

	return true;
}

//解放する
void TitleScene::Finalize()
{
	m_pObjectManager->ReleaseObject();
}
