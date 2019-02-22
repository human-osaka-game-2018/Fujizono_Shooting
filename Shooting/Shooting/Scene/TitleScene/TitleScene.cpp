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

//������X�V����
void TitleScene::Update()
{
	//���̃V�[���̃I�u�W�F�N�g�̍X�V���s��
	m_pObjectManager->Update();
}

//�`�悷��
void TitleScene::Render()
{
	//�I�u�W�F�N�g��Render
	m_pObjectManager->Render();
}

//����������
bool TitleScene::Initialize()
{
	//�I�u�W�F�N�g��NEW���āA�I�u�܂˂�Vector�ɂ߂�
	m_pObjectManager->RegisterObject(new TitleBackground);
	m_pObjectManager->RegisterObject(new PressEnter);

	return true;
}

//�������
void TitleScene::Finalize()
{
	m_pObjectManager->ReleaseObject();
}
