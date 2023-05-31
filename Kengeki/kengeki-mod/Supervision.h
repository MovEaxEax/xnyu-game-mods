#pragma once
typedef enum _D3DPRIMITIVETYPE {
    D3DPT_POINTLIST = 1,
    D3DPT_LINELIST = 2,
    D3DPT_LINESTRIP = 3,
    D3DPT_TRIANGLELIST = 4,
    D3DPT_TRIANGLESTRIP = 5,
    D3DPT_TRIANGLEFAN = 6,
    D3DPT_FORCE_DWORD = 0x7fffffff, /* force 32-bit size enum */
} D3DPRIMITIVETYPE;
typedef HRESULT(__stdcall* D3D9_DrawIndexedPrimitiveT)(void* pDevice, D3DPRIMITIVETYPE PrimitiveType, INT BaseVertexIndex, UINT MinVertexIndex, UINT NumVertices, UINT startIndex, UINT primCount);
D3D9_DrawIndexedPrimitiveT pD3D9_DrawIndexedPrimitive = nullptr;
typedef HRESULT(__stdcall* D3D9_SetVertexShaderT)(void* pDevice, void* pShader);
D3D9_SetVertexShaderT pD3D9_SetVertexShader = nullptr;

HRESULT __stdcall D3D9_DrawIndexedPrimitiveHook(void* pDevice, D3DPRIMITIVETYPE PrimitiveType, INT BaseVertexIndex, UINT MinVertexIndex, UINT NumVertices, UINT startIndex, UINT primCount)
{
    return 0;
}

HRESULT __stdcall D3D9_SetVertexShaderHook(void* pDevice, void* pShader)
{
    return 0;
}

EXTERN_DLL_EXPORT void ToggleSupervisionRoutine(bool isEnabled)
{

    //
    // Routine for supervision
    // 
    if (isEnabled)
    {
        pInstallGraphicHook("DrawIndexedPrimitive", D3D9_DrawIndexedPrimitiveHook, nullptr);
        pInstallGraphicHook("SetVertexShader", D3D9_SetVertexShaderHook, nullptr);
    }
    else
    {
        pRemoveGraphicHook("DrawIndexedPrimitive");
        pRemoveGraphicHook("SetVertexShader");
    }
}


