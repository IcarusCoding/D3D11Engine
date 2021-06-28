#pragma once

#include "Window.h"
#include "FPSCounter.h"

class Engine {

private:
	Window* ptrWindow;
	FPSCounter frameCounter;
	
	void Tick() noexcept;

public:
	Engine() noexcept;
	~Engine() noexcept;

	Window* Init(const wchar_t* className) noexcept;
	DWORD Start() noexcept;
	void AllocateConsole() noexcept;

};

