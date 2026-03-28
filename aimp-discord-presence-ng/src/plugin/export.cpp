#include "pch.h"
#include "AimpPlugin.h"
#include "apiPlugin.h"


extern "C" __declspec(dllexport)
HRESULT WINAPI AIMPPluginGetHeader(IAIMPPlugin** Header)
{
    if (!Header)
        return E_INVALIDARG;

    *Header = new AimpPlugin();
    return S_OK;
}