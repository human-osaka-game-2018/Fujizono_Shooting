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
	//���̃V�[���̃I�u�W�F�N�g�̍X�V���s��
	m_pObjectManager->Update();
}

//�`�悷��
void GameScene::Render()
{
	//�I�u�W�F�N�g��Render
	m_pObjectManager->Render();
}

//����������
bool GameScene::Initialize()
{
	//�I�u�W�F�N�g��NEW���āA�I�u�܂˂�Vector�ɂ߂�
	m_pObjectManager->RegisterObject(new GameBackground);
	m_pObjectManager->RegisterObject(new Player);

	return true;
}

//�������
void GameScene::Release()
{
	m_pObjectManager->ReleaseObject();
}
