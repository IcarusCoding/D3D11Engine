#include "Engine.h"

using std::cout;

int APIENTRY WinMain(_In_ HINSTANCE hInst, _In_opt_ HINSTANCE hPrevInst, _In_ LPSTR lpCmdLine, _In_ int nCmdShow) {
	Engine eng;
	eng.AllocateConsole();
	Window* win = eng.Init(L"engine");
	win->Setup(L"ENGINNNNNEEEE D3D1111111");
	return eng.Start();
}
