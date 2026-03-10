#include "pch.h"
#include "ComObject.h"

ULONG __stdcall ComObject::AddRef()
{
	return ++this->RefCount;
}

ULONG __stdcall ComObject::Release()
{
	ULONG count = --this->RefCount;
	if (count == 0) {
		delete this;
	}
	return count;
}

HRESULT WINAPI ComObject::QueryInterface(REFIID riid, void** ppvObject) 
{
    if (!ppvObject)
        return E_POINTER;

    if (riid == IID_IUnknown)
    {
        *ppvObject = static_cast<IUnknown*>(this);
        AddRef();
        return S_OK;
    }

    *ppvObject = nullptr;
    return E_NOINTERFACE;
}