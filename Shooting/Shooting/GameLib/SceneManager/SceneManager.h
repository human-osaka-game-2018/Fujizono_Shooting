#pragma once

#include "SceneBase\SceneBase.h"

/**
* �V�[�����Ǘ�����N���X
*/
class SceneManager
{
public:
	SceneManager(void);
	~SceneManager(void);

	/**���������s���֐�*/
	void Initialize(void);
	/**������s���֐�*/
	void Release(void);
	/**����̍X�V���s���֐�*/
	void Update(void);
	/**�`����s���֐�*/
	void Render(void);

	/**�V�[���̑J�ڂ��s���֐�*/
	bool ChangeScene(SceneBase* pScene);

private:

	SceneBase* m_pScene;
};
