#include "pch.h" 
#include "AimpPlugin.h"
#include "AppInfo.h"

TChar* WINAPI AimpPlugin::InfoGet(int Index) {

    switch (Index)
    {
      case AIMP_PLUGIN_INFO_NAME:
        return const_cast<PWCHAR>(AppInfo::PluginName);
      case AIMP_PLUGIN_INFO_AUTHOR:
        return const_cast<PWCHAR>(AppInfo::Author);
      case AIMP_PLUGIN_INFO_SHORT_DESCRIPTION:
        return const_cast<PWCHAR>(AppInfo::Description);
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

void WINAPI AimpPlugin::SystemNotification(int NotifyID, IUnknown* Data){
    if (NotifyID == AIMP_SYSTEM_NOTIFICATION_SERVICE_ADDED) {
        if (Data) {
            this->player = nullptr;
            if (SUCCEEDED(Data->QueryInterface(IID_IAIMPServicePlayer, (void**)&this->player))) {
                player->Release();
            }
        }
	}
}