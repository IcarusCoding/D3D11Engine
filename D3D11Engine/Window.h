#pragma once

#include <Windows.h>
#include <iostream>

#include "Graphics.h"

class Window {

private:
	const wchar_t* className;
	const HINSTANCE hInst;
	HWND hWnd;
	Graphics* graphics = nullptr;

	static LRESULT CALLBACK sWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

public:
	Window(const wchar_t* className) noexcept;
	~Window();
	void Setup(const wchar_t* title, int width = 800, int height = 500, 
		int x = CW_USEDEFAULT, int y = CW_USEDEFAULT, DWORD style = WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU);
	Graphics* getGraphics();

};

