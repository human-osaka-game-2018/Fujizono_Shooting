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

//����������
bool GameBackground::Initialize()
{

	const float TextureTopLeft_x = 128.f;
	const float TextureTopLeft_y = 0.0f;
	const float TextureWidth = 384.f;
	const float TextureHeight = static_cast<float>(WINDOW->GetHeight());
	const char* TexturePath = "../Graphics/Game_BG.png";

	// �e�N�X�`���[�T�C�Y����摜�T�C�Y��UV���擾(�摜��2�̗ݏ�ł����1.0f�ɂȂ�)
	// �e�N�X�`����2�̗ݏ�łȂ��Ƃ��Ɍ��ʂ𔭊�����
	float u = static_cast<float>(m_texture.GetSrcWidth()) / static_cast<float>(m_texture.GetWidth());
	float v = static_cast<float>(m_texture.GetSrcHeight()) / static_cast<float>(m_texture.GetHeight());

	if (!m_texture.Load(TexturePath))
	{
		return false;
	}

	HELPER_2D->SetVerticesFromLeftTopType(m_vertices, TextureTopLeft_x, TextureTopLeft_y, TextureWidth, TextureHeight, u, v);

	return true;
}

//�������
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

	//���_�ɓ����f�[�^��ݒ�
	pDevice->SetFVF(FVF_SIMPLE_TEX_2D);

	//�e�N�X�`���̐ݒ�
	pDevice->SetTexture(0, m_texture.GetD3DTexture());

	//�`��
	pDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, m_vertices, sizeof(Simple2DVertex));
}
