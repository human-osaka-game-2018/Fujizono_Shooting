#include "Missile.h"
#include "GameLib/GameLib.h"

namespace {
	const float MissileWidth = 16.0f;
	const float MissileHeight = 32.0f;
	const float MissileDeletePos_y = -10.0f;
	const float MissileSpeed = 10.0f;
}

Missile::Missile()
{
	Initialize();
}

Missile::~Missile()
{
	Release();
}

//初期化する
void Missile::Initialize()
{
	const char* TexturePath = "../Graphics/Missile.jpg";

	if (!m_texture.Load(TexturePath))
	{
		MessageBox(NULL, TEXT("画像の読み込みエラー"), TEXT("エラー"), MB_ICONWARNING);
	}
}

//解放する
void Missile::Release()
{
	m_texture.Release();
	m_missiles.clear();
	m_missiles.shrink_to_fit();
}

void Missile::Create(float missile_x, float missile_y)
{
	MissileInfo missile(missile_x, missile_y);
	m_missiles.push_back(missile);
}

void Missile::Update()
{
	for (auto& missile : m_missiles)
	{
		missile.y -= MissileSpeed;

		HELPER_2D->SetVerticesFromLeftTopType(
			missile.vertex,
			missile.x,
			missile.y,
			MissileWidth,
			MissileHeight
		);

		if (m_missiles[0].y < MissileDeletePos_y)
		{
			m_missiles.erase(m_missiles.begin());
		}
	}
}

void Missile::Render()
{
	IDirect3DDevice9* pDevice = GameLib::Instance.GetDirect3DDevice();

	//頂点に入れるデータを設定
	pDevice->SetFVF(FVF_SIMPLE_TEX_2D);

	//テクスチャの設定
	pDevice->SetTexture(0, m_texture.GetD3DTexture());

	//描画
	for (auto& missile : m_missiles)
	{	  
	    pDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, missile.vertex, sizeof(Simple2DVertex));
	}
}

Missile::MissileInfo::MissileInfo(float x, float y)
{
	this->x = x;
	this->y = y;
}
