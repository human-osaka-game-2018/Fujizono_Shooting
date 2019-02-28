#include "Player.h"
#include "GameLib/GameLib.h"

namespace {
	const float TextureTopLeft_x = 304.f;
	const float TextureTopLeft_y = 400.f;
	const float TextureWidth = 32.f;
	const float TextureHeight = 32.f;
	const float MovementLeftMax = 128.f;
	const float MovementRightMax = 480.f;
	const float MovementUpMax = 0.f;
	const float MovementDownMax = 448.f;
	const float limitTime = 3.0f;
	const float MovementSpeed = 5.0f;
}

Player::Player()
{
	Initialize();
}

Player::~Player()
{
	Release();
}

//初期化する
bool Player::Initialize()
{
	m_missile.Initialize();
	
    const char* TexturePath = "../Graphics/Player.png";

	if (!m_texture.Load(TexturePath))
	{
		return false;
	}

	HELPER_2D->SetVerticesFromLeftTopType(m_vertices, TextureTopLeft_x, TextureTopLeft_y, TextureWidth, TextureHeight);

	return true;
}

//解放する
void Player::Release()
{
	m_texture.Release();
	m_missile.Release();
}

void Player::Update()
{
	if (DIRECT_INPUT->KeyboardIsHeld(DIK_UP))
	{
		m_vertices->y -= MovementSpeed;

		if (m_vertices->y < MovementUpMax)
		{
			m_vertices->y = MovementUpMax;
		}
	}

	if (DIRECT_INPUT->KeyboardIsHeld(DIK_DOWN))
	{
		m_vertices->y += MovementSpeed;

		if (m_vertices->y > MovementDownMax)
		{
			m_vertices->y = MovementDownMax;
		}
	}
	
	if (DIRECT_INPUT->KeyboardIsHeld(DIK_LEFT))
	{
		m_vertices->x -= MovementSpeed;

		if (m_vertices->x < MovementLeftMax)
		{
			m_vertices->x = MovementLeftMax;
		}
	}
	
	if (DIRECT_INPUT->KeyboardIsHeld(DIK_RIGHT))
	{
		m_vertices->x += MovementSpeed;

		if (m_vertices->x > MovementRightMax)
		{
			m_vertices->x = MovementRightMax;
		}
	}

	++m_limitCount;

	m_missileFlag = false;

	if (DIRECT_INPUT->KeyboardIsHeld(DIK_Z))
	{
		if (m_limitCount > limitTime)
		{
			m_limitCount = 0;
			m_missileFlag = true;

			m_missile_x = m_vertices->x;
			m_missile_y = m_vertices->y;
		}
	}

	HELPER_2D->SetVerticesFromLeftTopType(m_vertices, m_vertices->x, m_vertices->y, TextureWidth, TextureHeight);

	m_missile.Update(m_missileFlag, m_missile_x, m_missile_y);
}

void Player::Render()
{
	IDirect3DDevice9* pDevice = GameLib::Instance.GetDirect3DDevice();

	//頂点に入れるデータを設定
	pDevice->SetFVF(FVF_SIMPLE_TEX_2D);

	//テクスチャの設定
	pDevice->SetTexture(0, m_texture.GetD3DTexture());

	//描画
	pDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, m_vertices, sizeof(Simple2DVertex));

	m_missile.Render();
}
