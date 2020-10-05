struct VS_OUT
{
	float4 pos : SV_POSITION;
	float4 color : COLOR;
};

float4 main(VS_OUT i) : SV_TARGET
{
	return i.color;
}