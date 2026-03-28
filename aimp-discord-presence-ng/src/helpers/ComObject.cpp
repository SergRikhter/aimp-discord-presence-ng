#include "pch.h"
#include "ComObject.h"
#include "apiPlugin.h"

template<typename T>
BOOL ComObject<T>::isOurRIID(REFIID iid)
{
    return false;
}

template <class T>
ULONG WINAPI ComObject<T>::AddRef()
{
	return ++this->RefCount;
}

template <class T>
ULONG WINAPI ComObject<T>::Release()
{
	ULONG count = --this->RefCount;
	if (count == 0) {
		delete this;
	}
	return count;
}

template <class T>
HRESULT WINAPI ComObject<T>::QueryInterface(REFIID iid, void** ppvObject)
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

template class ComObject<IAIMPPlugin>;