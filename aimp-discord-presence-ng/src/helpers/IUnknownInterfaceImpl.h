#pragma once
#include "pch.h"
#include <atomic>
#include <unordered_map>
#include <Unknwn.h>
#include "GUIDHash.h"

using namespace std; 

template <typename Interfaces>
class IUnknownInterfaceImpl : public Interfaces
{
  protected:
    atomic<ULONG> RefCount{ 0 };
    unordered_map<GUID, void*, GUIDHash> interfaceMap;
  public:
    IUnknownInterfaceImpl() : RefCount(1) {}
    virtual ~IUnknownInterfaceImpl() = default;
    
    /**
     * IUnknown implementation.
     *
     * Increments the reference counter of the object.
     *
     * @return Current reference count after increment.
     */
    virtual ULONG WINAPI AddRef() override;

    /**
     * IUnknown implementation.
     *
     * Decrements the reference counter of the object.
     * When the counter reaches zero, the object is destroyed.
     *
     * @return Current reference count after decrement.
     */
    virtual ULONG WINAPI Release() override;

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
    virtual HRESULT WINAPI QueryInterface(REFIID iid, void** ppvObject) override;
};

template<typename Interfaces>
ULONG WINAPI IUnknownInterfaceImpl<Interfaces>::AddRef()
{
    return ++RefCount;
}

template<typename Interfaces>
ULONG WINAPI IUnknownInterfaceImpl<Interfaces>::Release()
{
    ULONG count = --RefCount;
    if (count == 0)
        delete this;
    return count;
}

template<typename Interfaces>
HRESULT WINAPI IUnknownInterfaceImpl<Interfaces>::QueryInterface(REFIID iid, void** ppvObject)
{
    if (!ppvObject)
        return E_POINTER;

    auto it = interfaceMap.find(iid);
    if (it != interfaceMap.end())
    {
        *ppvObject = it->second;
        AddRef();
        return S_OK;
    }

    return E_NOINTERFACE;
}
