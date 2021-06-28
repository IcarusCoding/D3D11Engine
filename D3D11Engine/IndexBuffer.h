#pragma once

#include "Attachable.h"

class IndexBuffer : public Attachable {

public:
	IndexBuffer(Graphics& graphics, const std::vector<unsigned short>& indices);
	void Attach(Graphics& graphics) noexcept override;
	UINT GetAmount() const noexcept;

protected:
	UINT amount;
	Microsoft::WRL::ComPtr<ID3D11Buffer> pIndexBuffer;

};