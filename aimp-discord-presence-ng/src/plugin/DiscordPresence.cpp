#include "pch.h" 
#include "DiscordPresence.h"

HRESULT WINAPI DiscordPresence::InfoGet(int Index, IAIMPString** Value) {
    return E_NOTIMPL; 
}


DWORD WINAPI DiscordPresence::InfoGetCategories() {
    return 0;
}


HRESULT WINAPI DiscordPresence::Initialize(IAIMPCore* Core) {
    return S_OK;
}


HRESULT WINAPI DiscordPresence::Finalize() {
    return S_OK;
}


void WINAPI DiscordPresence::SystemNotification(int NotifyID, IUnknown* Data) {

}