#pragma once

#include "GameLib/ObjectManager/Object2DBase.h"
#include "GameLib/DirectX/DirectX.h"
#include "GameLib/2DHelper/2DHelper.h"
#include "GameLib/Texture/Texture.h"
#include "Object/Missile.h"

class Player : public Object2DBase
{
public:

	Player();
	~Player();

	/**
	* @brief ����������֐�
	* @return ����������肭�ł��Ă��Ȃ���FALSE
	*/
	bool Initialize();

	/**
	* @brief �������֐�
	*/
	void Release();

	/**
	* @brief ����֐�
	*/
	void Update();

	/**
	* @brief �`��֐�
	*/
	void Render();

private:
	
	Missile m_missile;

	//�@�e�̔��˂𐧌����邽�߂̃J�E���g
	int m_limitCount = 0;

	bool m_missileFlag = false;
	float m_missile_x = 0;
	float m_missile_y = 0;
};
