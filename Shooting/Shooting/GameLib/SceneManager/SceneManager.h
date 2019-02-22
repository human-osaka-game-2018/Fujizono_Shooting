#pragma once

#include "SceneBase\SceneBase.h"

/**
* シーンを管理するクラス
*/
class SceneManager
{
public:
	SceneManager(void);
	~SceneManager(void);

	/**初期化を行う関数*/
	void Initialize(void);
	/**解放を行う関数*/
	void Release(void);
	/**操作の更新を行う関数*/
	void Update(void);
	/**描画を行う関数*/
	void Render(void);

	/**シーンの遷移を行う関数*/
	bool ChangeScene(SceneBase* pScene);

private:

	SceneBase* m_pScene;
};
