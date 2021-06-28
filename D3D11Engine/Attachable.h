#pragma once

#include "Graphics.h"

class Attachable {

protected:
	static Microsoft::WRL::ComPtr<ID3D11DeviceContext> GetDeviceContext(Graphics& graphics) noexcept;
	static Microsoft::WRL::ComPtr<ID3D11Device> GetDevice(Graphics& graphics) noexcept;

public:
	virtual void Attach(Graphics& graphics) noexcept = 0;
	virtual ~Attachable() = default;

};