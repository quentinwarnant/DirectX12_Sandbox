struct VS_IN
{
	float3 pos : POSITION;
	float3 normal : NORMAL;
	float4 color: COLOR;
	float2 uv : UV;
};

struct VS_OUT
{
	float4 pos : SV_POSITION;
	float4 color : COLOR;
};

VS_OUT main(VS_IN i )
{
	VS_OUT o;
	o.pos = float4(i.pos, 1.0);
	o.color = i.color;
	
	return o;
}