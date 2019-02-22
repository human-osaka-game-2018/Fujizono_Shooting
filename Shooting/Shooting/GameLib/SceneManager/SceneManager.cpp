#include "../GameLib.h"
#include "SceneManager.h"

SceneManager::SceneManager()
	: m_pScene(nullptr)
{}

SceneManager::~SceneManager()
{
	Finalize();
}

/**�V�[���Ǘ��̏�����*/
void SceneManager::Initialize()
{
	m_pScene = nullptr;
}

/**�V�[���Ǘ��̉��*/
void SceneManager::Finalize()
{
	// �Ō�͉�����ďI���
	if (m_pScene) { m_pScene->Finalize(); }
	SAFE_DELETE(m_pScene);
}

/**�V�[���̍X�V*/
void SceneManager::Update()
{
	if (m_pScene) m_pScene->Update();
}

/**�V�[���̕`��*/
void SceneManager::Render()
{
	if (m_pScene) m_pScene->Render();

}

/**�V�[���̑J��*/
bool SceneManager::ChangeScene(SceneBase* pScene)
{
	// ���݂̃V�[�����������
	if (m_pScene)
	{
		m_pScene->Finalize();
		SAFE_DELETE(m_pScene);
	}

	bool ret = true;
	// ���̃V�[��������Ώ���������
	if (pScene)
	{
		ret = pScene->Initialize();
	}
	m_pScene = pScene;
	return ret;
}