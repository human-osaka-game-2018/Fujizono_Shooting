#include "GameBackground.h"
#include "../../../GameLib/GameLib.h"

GameBackground::GameBackground()
{
	Initialize();
}

GameBackground::~GameBackground()
{
	Release();
}

//初期化する
bool GameBackground::Initialize()
{

	const float TextureTopLeft_x = 128.f;
	const float TextureTopLeft_y = 0.0f;
	const float TextureWidth = 384.f;
	const float TextureHeight = static_cast<float>(WINDOW->GetHeight());
	const char* TexturePath = "../Graphics/Game_BG.png";

	// テクスチャーサイズから画像サイズのUVを取得(画像が2の累乗であれば1.0fになる)
	// テクスチャが2の累乗でないときに効果を発揮する
	float u = static_cast<float>(m_texture.GetSrcWidth()) / static_cast<float>(m_texture.GetWidth());
	float v = static_cast<float>(m_texture.GetSrcHeight()) / static_cast<float>(m_texture.GetHeight());

	if (!m_texture.Load(TexturePath))
	{
		return false;
	}

	HELPER_2D->SetVerticesFromLeftTopType(m_vertices, TextureTopLeft_x, TextureTopLeft_y, TextureWidth, TextureHeight, u, v);

	return true;
}

//解放する
void GameBackground::Release()
{
	m_texture.Release();
}

void GameBackground::Update()
{
}

void GameBackground::Render()
{
	IDirect3DDevice9* pDevice = GameLib::Instance.GetDirect3DDevice();

	//頂点に入れるデータを設定
	pDevice->SetFVF(FVF_SIMPLE_TEX_2D);

	//テクスチャの設定
	pDevice->SetTexture(0, m_texture.GetD3DTexture());

	//描画
	pDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, m_vertices, sizeof(Simple2DVertex));
}
