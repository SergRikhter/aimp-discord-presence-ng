#pragma once
#include "apiPlugin.h"

class DiscordPresence
{
    class Plugin : public IAIMPPlugin
    {
    private:
        ULONG FRefCount = 1;

    public:
        /**
         * IUnknown implementation.
         *
         * Increments the reference counter of the object.
         *
         * @return Current reference count after increment.
         */
        ULONG WINAPI AddRef();

        /**
         * IUnknown implementation.
         *
         * Decrements the reference counter of the object.
         * When the counter reaches zero, the object is destroyed.
         *
         * @return Current reference count after decrement.
         */
        ULONG WINAPI Release();

        /**
         * IUnknown implementation.
         *
         * Retrieves a pointer to the requested interface if supported.
         *
         * @param riid        Identifier of the requested interface.
         * @param ppvObject   Receives a pointer to the interface.
         *
         * @return S_OK if the interface is supported, otherwise E_NOINTERFACE.
         */
        HRESULT WINAPI QueryInterface(REFIID riid, void** ppvObject);

        /**
         * IAIMPPlugin implementation.
         *
         * Returns information about the plugin such as name, author,
         * or description.
         *
         * @param Index   Information identifier:
         *                AIMP_PLUGIN_INFO_NAME
         *                AIMP_PLUGIN_INFO_AUTHOR
         *                AIMP_PLUGIN_INFO_SHORT_DESCRIPTION
         *                AIMP_PLUGIN_INFO_FULL_DESCRIPTION
         *
         * @param Value   Receives a pointer to an IAIMPString object
         *                containing the requested information.
         *
         * @return S_OK on success.
         */
        HRESULT WINAPI InfoGet(int Index, IAIMPString** Value);

        /**
         * IAIMPPlugin implementation.
         *
         * Returns the plugin category used for sorting in the
         * plugin manager UI.
         *
         * @return One or a combination of:
         *         AIMP_PLUGIN_CATEGORY_ADDONS
         *         AIMP_PLUGIN_CATEGORY_DECODERS
         *         AIMP_PLUGIN_CATEGORY_VISUALS
         *         AIMP_PLUGIN_CATEGORY_DSP
         */
        DWORD WINAPI InfoGetCategories();

        /**
         * IAIMPPlugin implementation.
         *
         * Initializes the plugin and provides access to the
         * program core services.
         *
         * @param Core   Interface to the application core.
         *
         * @return S_OK if initialization was successful.
         */
        HRESULT WINAPI Initialize(IAIMPCore* Core);

        /**
         * IAIMPPlugin implementation.
         *
         * Finalizes the plugin before the DLL is unloaded.
         * Called only if Initialize() returned S_OK.
         *
         * @return Operation status.
         */
        HRESULT WINAPI Finalize();

        /**
         * IAIMPPlugin implementation.
         *
         * Handles system notifications from the player core.
         *
         * @param NotifyID   Notification identifier.
         * @param Data       Optional notification data.
         */
        void WINAPI SystemNotification(int NotifyID, IUnknown* Data);
    };
};