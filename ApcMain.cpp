//������Ⱦ��Main����
#include "Stdfx.h"
#include "ApcDevice.h"
//
static const int windowWidth = 800;
static const int windowHeight = 600;
const char* windowTitle = "AlpacaRenderer";
HDC hdc = NULL;
HDC screenHDC = NULL;
ApcDevice* device = NULL;
HWND handler = NULL;

static LRESULT OnEvent(HWND, UINT, WPARAM, LPARAM);
void CreateRenderDevice();
void CreateSystemWindow();
void Update();
void DoRender();

int main()
{
	CreateSystemWindow();
	CreateRenderDevice();
	Update();
	return 0;
}

void CreateSystemWindow()
{
	WNDCLASS wndClass = { CS_BYTEALIGNCLIENT, (WNDPROC)OnEvent, 0, 0, 0, NULL, NULL, NULL, NULL, TEXT(windowTitle) };
	wndClass.hInstance = GetModuleHandle(NULL);

	if (!RegisterClass(&wndClass))
		return;

	handler = CreateWindow(TEXT(windowTitle), TEXT(windowTitle), WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
		0, 0, 0, 0, NULL, NULL, wndClass.hInstance, NULL);
	if (handler == NULL)
		return;

	hdc = GetDC((handler));
	screenHDC = CreateCompatibleDC(hdc);
	//ReleaseDC(handler, hdc);

	BITMAPINFO bitmapInfo = { { sizeof(BITMAPINFOHEADER),windowWidth, windowHeight, 1, 32, BI_RGB, windowWidth * windowHeight * 4, 0, 0, 0, 0 } };
	LPVOID ptr;
	//�����豸�޹ص�λͼ
	HBITMAP bitmapHandler = CreateDIBSection(screenHDC, &bitmapInfo, DIB_RGB_COLORS, &ptr, 0, 0);
	if (bitmapHandler == NULL)
		return;

	HBITMAP screenObject = (HBITMAP)SelectObject(screenHDC, bitmapHandler);

	SetWindowPos(handler, NULL, 300, 200, windowWidth, windowHeight, (SWP_NOCOPYBITS | SWP_NOZORDER | SWP_SHOWWINDOW));

	ShowWindow(handler, SW_NORMAL);
	UpdateWindow(handler);
}

void CreateRenderDevice()
{
	device = new ApcDevice();
	device->InitDevice(screenHDC, windowWidth, windowHeight);
}

LRESULT OnEvent(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}

void Update()
{
	MSG msg = { 0 };
	while (msg.message != WM_QUIT)
	{
		/*static FLOAT fLastTime = (float)::timeGetTime();
		static FLOAT fCurrTime = (float)::timeGetTime();
		static FLOAT fTimeDelta = 0.0f;
		fCurrTime = (float)::timeGetTime();
		fTimeDelta = (fCurrTime - fLastTime) / 1000.0f;
		fLastTime = fCurrTime;*/

		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			DoRender();
		}
	}
}

void DoRender()
{
	Vector3 v1(0, 5, 1); Color c1(1.0f, 0, 0, 1.0f);
	Vector3 v2(4, 3, 1); Color c2(0, 1.0f, 0, 1.0f);
	Vector3 v3(4, 0, 1); Color c3(0, 0, 1.0f, 1.0f);
	Vertex p1(v1, c1);
	Vertex p2(v2, c2);
	Vertex p3(v3, c3);
	device->Clear();
	device->DrawPrimitive(p1, p2, p3);
	BitBlt(hdc, 0, 0, windowWidth, windowHeight, screenHDC, 0, 0, SRCCOPY);
}
