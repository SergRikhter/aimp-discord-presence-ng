#pragma once
#include <atomic>
#include <Unknwn.h>

using namespace std; 

class ComObject : public IUnknown
{
  protected:
    std::atomic<ULONG> RefCount{ 1 };

  public:
    virtual ~ComObject() = default;
    
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
  virtual HRESULT WINAPI QueryInterface(REFIID riid, void** ppvObject) override;
};