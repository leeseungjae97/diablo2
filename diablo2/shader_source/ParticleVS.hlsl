#include "global.hlsli"


struct VSIn
{
    float3 LocalPos : POSITION;
    uint Instance : SV_InstanceID;
    float4 Color : COLOR;
};

struct VSOut
{
    float4 LocalPos : SV_Position;
    uint Instance : SV_InstanceID;
    float4 Color : COLOR;
};



VSOut main(VSIn In)
{
    VSOut Out = (VSOut) 0.0f;
    Out.LocalPos = float4(In.LocalPos, 1.0f);
    Out.Instance = In.Instance;
    Out.Color = In.Color;
    //float3 worldPos = (In.pos.xyz) + WorldMatrix._41_42_43 + particles[In.Instance].position.xyz;
    
    //float4 worldPos = mul(float4(In.pos, 1.0f), mWorld);
    //worldPos.xyz += particles[In.Instance].position.xyz;
    
    //float4 viewPos = mul(worldPos, mView);
    //Out.pos = mul(viewPos, mProjection);
    
    return Out;
}