#include "Graphics.h"

namespace wrl = Microsoft::WRL;

using wrl::ComPtr;

Graphics::Graphics() noexcept {}

Graphics::~Graphics() noexcept {}

void Graphics::AttachD3D11(HWND hWnd) {
	RECT r;
	GetClientRect(hWnd, &r);
	
	D3D_FEATURE_LEVEL fLevel = D3D_FEATURE_LEVEL_11_0;
	DXGI_SWAP_CHAIN_DESC desc = {
			.BufferDesc = {
				.Width = 0,
				.Height = 0,
				.RefreshRate = {
					.Numerator = 0,
					.Denominator = 0
				},
				.Format = DXGI_FORMAT_B8G8R8A8_UNORM,
				.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED,
				.Scaling = DXGI_MODE_SCALING_UNSPECIFIED
			},
			.SampleDesc = {
				.Count = 1,
				.Quality = 0
			},
			.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT,
			.BufferCount = 1,
			.OutputWindow = hWnd,
			.Windowed = TRUE,
			.SwapEffect = DXGI_SWAP_EFFECT_DISCARD,
			.Flags = 0
	};
	HRESULT h = D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, D3D11_CREATE_DEVICE_DEBUG, nullptr, 0,
		D3D11_SDK_VERSION, &desc, &pSwapChain, &pDevice, nullptr, &pDeviceContext);
	ComPtr<ID3D11Resource> pBackBuffer;
	pSwapChain->GetBuffer(0, __uuidof(ID3D11Resource), &pBackBuffer);
	pDevice->CreateRenderTargetView(pBackBuffer.Get(), nullptr, &pTarget);
}

void Graphics::EndFrame() {
	pSwapChain->Present(1, 0);
}
