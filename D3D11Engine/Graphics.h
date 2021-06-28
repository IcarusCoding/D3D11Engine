#pragma once

#include <d3d11.h>
#include <wrl.h>
#include <vector>

#pragma comment(lib, "d3d11.lib")

class Window;

class Graphics {

	friend class Attachable;
	friend class Window;

private:
	Microsoft::WRL::ComPtr<ID3D11Device> pDevice;
	Microsoft::WRL::ComPtr<IDXGISwapChain> pSwapChain;
	Microsoft::WRL::ComPtr<ID3D11DeviceContext> pDeviceContext;
	Microsoft::WRL::ComPtr<ID3D11RenderTargetView> pTarget;

	Graphics() noexcept;
	~Graphics() noexcept;

	void AttachD3D11(HWND hWnd);

public:
	void EndFrame();

};

