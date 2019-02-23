#pragma once

#include "../../ObjectManager/ObjectManager.h"

/**
* �V�[���̊��N���X
*/
class SceneBase
{
public:

	SceneBase();
	virtual ~SceneBase();

	/**�������֐�*/
	virtual bool Initialize() = 0;
	/**����֐�*/
	virtual void Release() = 0;
	/**����֐�*/
	virtual void Update() = 0;
	/**�`��֐�*/
	virtual void Render() = 0;
protected:

	ObjectManager* m_pObjectManager;	    //!< ObjectManager�N���X�̃C���X�^���X�ւ̃|�C���^
};
