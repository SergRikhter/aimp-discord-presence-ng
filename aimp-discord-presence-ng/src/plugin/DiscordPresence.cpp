#include "pch.h" 
#include "DiscordPresence.h"

TChar* WINAPI DiscordPresence::InfoGet(int Index) {
    return 0; 
}


LongWord WINAPI DiscordPresence::InfoGetCategories() {
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