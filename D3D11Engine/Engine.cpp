#include "Engine.h"

using std::cout;

Engine::Engine() noexcept : ptrWindow(nullptr), frameCounter(FPSCounter()) {}

Engine::~Engine() noexcept {}

Window* Engine::Init(const wchar_t* className) noexcept {
	return ptrWindow = new Window(className);
}

DWORD Engine::Start() noexcept {
	MSG msg;
	while (true) {
		while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
			if (msg.message == WM_QUIT) {
				return msg.wParam;
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		if (GetAsyncKeyState(VK_ESCAPE)) {
			break;
		}
		Tick();
	}
	return -1;
}

void Engine::AllocateConsole() noexcept {
	FILE* file;
	AllocConsole();
	freopen_s(&file, "CONOUT$", "w", stdout);
}

void Engine::Tick() noexcept {
	frameCounter.Tick();
	ptrWindow->getGraphics()->EndFrame();
	if (frameCounter.HasSecondPassed()) {
		cout << "FPS: " << frameCounter.GetFrames() << "\n";
		frameCounter.Reset();
	}
}