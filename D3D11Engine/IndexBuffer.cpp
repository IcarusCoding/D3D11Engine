#include "IndexBuffer.h"

using std::vector;

IndexBuffer::IndexBuffer(Graphics& graphics, const vector<unsigned short>& indices) : amount(indices.size()) {
	D3D11_BUFFER_DESC desc = {
		.ByteWidth = UINT(amount * sizeof(unsigned short)),
		.Usage = D3D11_USAGE_DEFAULT,
		.BindFlags = D3D11_BIND_INDEX_BUFFER,
		.CPUAccessFlags = 0,
		.MiscFlags = 0,
		.StructureByteStride = sizeof(unsigned short)
	};
	D3D11_SUBRESOURCE_DATA data = {
		.pSysMem = indices.data(),
		.SysMemPitch = 0,
		.SysMemSlicePitch = 0
	};
	GetDevice(graphics)->CreateBuffer(&desc, &data, &pIndexBuffer);
}

void IndexBuffer::Attach(Graphics& graphics) noexcept {
	GetDeviceContext(graphics)->IASetIndexBuffer(pIndexBuffer.Get(), DXGI_FORMAT_R16_UINT, 0);
}

UINT IndexBuffer::GetAmount() const noexcept {
	return amount;
}
