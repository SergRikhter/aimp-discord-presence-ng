#include "apiPlugin.h"
#include "apiPlayer.h"
#include "ComObject.h"

class AimpPlugin : public ComObject<IAIMPPlugin>
{
    protected: 
    IAIMPServicePlayer* player = nullptr;
    public:
        AimpPlugin() = default;
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
        TChar* WINAPI InfoGet(int Index);

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
        LongWord WINAPI InfoGetCategories() override;

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
        HRESULT WINAPI Initialize(IAIMPCore* Core) override;

        /**
         * IAIMPPlugin implementation.
         *
         * Finalizes the plugin before the DLL is unloaded.
         * Called only if Initialize() returned S_OK.
         *
         * @return Operation status.
         */
        HRESULT WINAPI Finalize() override;

        /**
         * IAIMPPlugin implementation.
         *
         * Handles system notifications from the player core.
         *
         * @param NotifyID   Notification identifier.
         * @param Data       Optional notification data.
         */
        void WINAPI SystemNotification(int NotifyID, IUnknown* Data) override;
 };