#include "Window.h"

// �E�C���h�E�v���V�[�W���[
static LRESULT CALLBACK WndProc(HWND hWnd, UINT uiMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uiMsg)
	{
	case WM_DESTROY:			//����{�^���ŃE�B���h�E��j��
		PostQuitMessage(0);
		break;
	case WM_KEYDOWN:
		switch ((CHAR)wParam)
		{
		case VK_ESCAPE:			//ESCAPE�L�[�ŃE�B���h�E��j��
			PostQuitMessage(0);
			break;

		}
		break;
	}
	// ����̃E�B���h�E�v���V�[�W�����Ăяo��
	return DefWindowProc(hWnd, uiMsg, wParam, lParam);
}

// �R���X�g���N�^
Window::Window(void)
	: m_hWnd(nullptr)
	, m_isQuitMessage(false)
	, m_width(0)
	, m_height(0)
{
}

// �f�X�g���N�^
Window::~Window(void)
{
}

// �E�B���h�E�̐���
bool Window::Create(const wchar_t* pName, int width, int height)
{
	WNDCLASSEX wndClass;
	// �E�C���h�E�̐ݒ�
	wndClass.cbSize = sizeof(WNDCLASSEX);
	wndClass.style = CS_HREDRAW | CS_VREDRAW;
	wndClass.lpfnWndProc = WndProc;
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hInstance = GetModuleHandle(NULL);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndClass.lpszMenuName = NULL;
	wndClass.lpszClassName = pName;
	wndClass.hIcon = LoadIcon(NULL, IDC_ARROW);
	wndClass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	RegisterClassExW(&wndClass);

	DWORD dwStyle = WS_OVERLAPPEDWINDOW;

	RECT Rect;
	Rect.left = 0;
	Rect.top = 0;
	Rect.right = width;
	Rect.bottom = height;
	// �E�B���h�E�̃X�^�C���ɍ��킹���K�؂ȃT�C�Y���擾����
	AdjustWindowRect(&Rect, dwStyle, false);

	width = Rect.right - Rect.left;
	height = Rect.bottom - Rect.top;

	// �E�C���h�E�̐���
	m_hWnd = CreateWindowW(wndClass.lpszClassName,
		pName,
		dwStyle,
		0,
		0,
		width,
		height,
		NULL,
		NULL,
		GetModuleHandle(NULL),
		NULL);
	if (m_hWnd == nullptr)
	{
		return false;
	}

	m_width = width;
	m_height = height;
	// �E�C���h�E�̕\��
	ShowWindow(m_hWnd, SW_SHOW);
	UpdateWindow(m_hWnd);

	return true;
}

// ���b�Z�[�W�̍X�V
bool Window::UpdateMessage(void)
{
	MSG msg;
	// ���b�Z�[�W�����݂��邩�m�F
	if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
	{
		// �I���ʒm�����Ă���ꍇ�͔�����
		if (msg.message == WM_QUIT)
		{
			m_isQuitMessage = true;
		}
		else
		{
			// ���b�Z�[�W���E�C���h�E�v���V�[�W���ɓ]��
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		return true;
	}
	return false;
}