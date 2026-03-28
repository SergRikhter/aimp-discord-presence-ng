#include "pch.h"
#include "IUnknownInterfaceImpl.h"
#include "apiPlugin.h"

template<typename T>
BOOL IUnknownInterfaceImpl<T>::isOurRIID(REFIID iid)
{
    return false;
}

template <class T>
ULONG WINAPI IUnknownInterfaceImpl<T>::AddRef()
{
	return ++this->RefCount;
}

template <class T>
ULONG WINAPI IUnknownInterfaceImpl<T>::Release()
{
	ULONG count = --this->RefCount;
	if (count == 0) {
		delete this;
	}
	return count;
}

template <class T>
HRESULT WINAPI IUnknownInterfaceImpl<T>::QueryInterface(REFIID iid, void** ppvObject)
{
    if (!ppvObject)
        return E_POINTER;

    if (IID_IUnknown == iid || isOurRIID(iid))
    {
        *ppvObject = this;
        AddRef();
        return S_OK;
    }
    *ppvObject = nullptr;
    return E_NOINTERFACE;
}

template class IUnknownInterfaceImpl<IAIMPPlugin>;