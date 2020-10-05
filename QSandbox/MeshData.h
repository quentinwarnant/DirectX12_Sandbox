#pragma once
#include "stdafx.h"

//Basic vertex data: position, normal, color & UV
struct Vertex
{
	Vertex(float posX, float posY, float posZ,
		float normalX, float normalY, float normalZ,
		float r, float g, float b, float a,
		float u, float v):	pos(posX,posY,posZ),
							normal(normalX, normalY, normalZ),
							color(r,g,b,a),
							uv(u, v){}
	DirectX::XMFLOAT3 pos;
	DirectX::XMFLOAT3 normal;
	DirectX::XMFLOAT4 color;
	DirectX::XMFLOAT2 uv;
	
};
