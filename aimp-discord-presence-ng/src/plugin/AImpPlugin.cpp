#include "pch.h" 
#include "AimpPlugin.h"
#include <string>

static const wchar_t* Name = L"AIMP Discord Presence NG";
static const wchar_t* Author = L"Mr.Secret";
static const wchar_t* Description = L"AIMP plugin for displaying current track in Discord Rich Presence.";

TChar* WINAPI AimpPlugin::InfoGet(int Index) {

    switch (Index)
    {
      case AIMP_PLUGIN_INFO_NAME:
        return const_cast<PWCHAR>(Name);
      case AIMP_PLUGIN_INFO_AUTHOR:
        return const_cast<PWCHAR>(Author);
      case AIMP_PLUGIN_INFO_SHORT_DESCRIPTION:
        return const_cast<PWCHAR>(Description);
     break;
    }
    return 0;
}


LongWord WINAPI AimpPlugin::InfoGetCategories() {
    return AIMP_PLUGIN_CATEGORY_ADDONS;
}


HRESULT WINAPI AimpPlugin::Initialize(IAIMPCore* Core) {
    Core->RegisterExtension(IID_IAIMPServiceFileFormats, this);
    return S_OK;
}


HRESULT WINAPI AimpPlugin::Finalize() {
    return S_OK;
}


void WINAPI AimpPlugin::SystemNotification(int NotifyID, IUnknown* Data) {

}