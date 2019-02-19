#include "SceneBase.h"
#include "../../GameLib.h"

SceneBase::SceneBase()
	: m_pObjectManager(GameLib::Instance.GetObjectManager())
{
}

SceneBase::~SceneBase()
{
}
