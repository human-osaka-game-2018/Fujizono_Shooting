#include "GameScene.h"
#include "Object/GameBackground.h"
#include "Player/Player.h"

GameScene::GameScene()
{
}

GameScene::~GameScene()
{
	Release();
}

void GameScene::Update()
{
	//このシーンのオブジェクトの更新を行う
	m_pObjectManager->Update();
}

//描画する
void GameScene::Render()
{
	//オブジェクトのRender
	m_pObjectManager->Render();
}

//初期化する
bool GameScene::Initialize()
{
	//オブジェクトをNEWして、オブまねのVectorにつめる
	m_pObjectManager->RegisterObject(new GameBackground);
	m_pObjectManager->RegisterObject(new Player);

	return true;
}

//解放する
void GameScene::Release()
{
	m_pObjectManager->ReleaseObject();
}
