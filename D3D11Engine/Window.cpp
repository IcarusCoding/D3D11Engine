#include "Window.h"

Window::Window(const wchar_t* className) noexcept : className(className), hInst(GetModuleHandle(NULL)), graphics(new Graphics()) {
	WNDCLASSEX wc = {
		.cbSize = sizeof(WNDCLASSEX),
		.style = CS_OWNDC,
		.lpfnWndProc = sWndProc,
		.cbClsExtra = 0,
		.cbWndExtra = 0,
		.hInstance = hInst,
		.hIcon = nullptr,
		.hCursor = nullptr,
		.hbrBackground = nullptr,
		.lpszClassName = className,
		.hIconSm = nullptr
	};
	RegisterClassEx(&wc);
}

Window::~Window() {
	UnregisterClass(className, hInst);
	if (hWnd) {
		DestroyWindow(hWnd);
	}
}

void Window::Setup(const wchar_t* title, int width, int height, int x, int y, DWORD style) {
	hWnd = CreateWindowEx(0, className, title, style, x, y, width, height, nullptr, nullptr, hInst, this);
	ShowWindow(hWnd, true);
	graphics->AttachD3D11(hWnd);
}

Graphics* Window::getGraphics() {
	return graphics;
}

LRESULT Window::sWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	Window* winPtr;
	if (uMsg == WM_NCCREATE) {
		const LPCREATESTRUCT lcs = reinterpret_cast<LPCREATESTRUCT>(lParam);
		winPtr = reinterpret_cast<Window*>(lcs->lpCreateParams);
		SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG>(winPtr));
	}
	if (winPtr = reinterpret_cast<Window*>(GetWindowLongPtr(hWnd, GWLP_USERDATA))) {
		return winPtr->WndProc(hWnd, uMsg, wParam, lParam);
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

LRESULT Window::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg) {

	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}