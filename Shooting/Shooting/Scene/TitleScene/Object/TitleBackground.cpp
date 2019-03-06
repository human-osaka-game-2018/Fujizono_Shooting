#include "TitleBackground.h"
#include "../../../GameLib/GameLib.h"

TitleBackground::TitleBackground()
{
	Initialize();
}

TitleBackground::~TitleBackground()
{
	Release();
}

//初期化する
void TitleBackground::Initialize()
{
	const char* m_TexturePath = "../Graphics/Title_BG.jpg";
	float WINDOW_WIDTH = static_cast<float>(WINDOW->GetWidth());
	float WINDOW_HEIGHT = static_cast<float>(WINDOW->GetHeight());

	if (!m_texture.Load(m_TexturePath))
	{
		MessageBox(NULL, TEXT("画像の読み込みエラー"), TEXT("エラー"), MB_ICONWARNING);
	}

	// テクスチャーサイズから画像サイズのUVを取得(画像が2の累乗であれば1.0fになる)
	// テクスチャが2の累乗でないときに効果を発揮する
	float u = static_cast<float>(m_texture.GetSrcWidth()) / static_cast<float>(m_texture.GetWidth());
	float v = static_cast<float>(m_texture.GetSrcHeight()) / static_cast<float>(m_texture.GetHeight());

	HELPER_2D->SetVerticesFromLeftTopType(m_vertices, 0.f, 0.f, WINDOW_WIDTH, WINDOW_HEIGHT, u, v);
}

//解放する
void TitleBackground::Release()
{
	m_texture.Release();
}

void TitleBackground::Update()
{
}

void TitleBackground::Render()
{
	IDirect3DDevice9* pDevice = GameLib::Instance.GetDirect3DDevice();

	//頂点に入れるデータを設定
	pDevice->SetFVF(FVF_SIMPLE_TEX_2D);

	//テクスチャの設定
	pDevice->SetTexture(0, m_texture.GetD3DTexture());

	//描画
	pDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, m_vertices, sizeof(Simple2DVertex));
}
