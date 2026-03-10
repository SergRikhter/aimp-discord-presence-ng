#include "DiscordPresence.h"
#include "apiPlugin.h"
#include "pch.h"

extern "C"
__declspec(dllexport)
HRESULT WINAPI AIMPPluginGetHeader(IAIMPPlugin** Header)
{
    if (!Header) return E_INVALIDARG;

    *Header = new DiscordPresence();
    return S_OK;
}