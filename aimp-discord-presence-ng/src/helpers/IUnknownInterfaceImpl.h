#pragma once
#include <atomic>
#include <Unknwn.h>

using namespace std; 
template <typename T>

class IUnknownInterfaceImpl : public T
{
  private:
    ULONG RefCount;

  public:
   IUnknownInterfaceImpl() : RefCount(0) {}
  
   virtual BOOL isOurRIID(REFIID iid);

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

// Template method implementations must be visible at the point of instantiation.
template<class T>
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
