#include "CManualSingletonT.h"

namespace ATP
{
    template<class TypeClass>
    CManualSingletonT<TypeClass>::CManualSingletonT()
    {

    }

    template<class TypeClass>
    CManualSingletonT<TypeClass>::~CManualSingletonT()
    { 
        release();
    }

    template<class TypeClass>
    inline TypeClass* CManualSingletonT<TypeClass>::instance()
    {
        return s_pInstance;
    }

    template<class TypeClass>
    template<typename ...Args>
    void CManualSingletonT<TypeClass>::initInstance(Args&&... args)
    {
        if (NULL == s_pInstance)
        {
            s_pInstance = new TypeClass(std::forward<Args>(args)...);
        }
    }

    template<class TypeClass>
    void CManualSingletonT<TypeClass>::release()
    {
        if (NULL != s_pInstance)
        {
            delete s_pInstance;
            s_pInstance = NULL;
        }
    }

#define IMPL_SINGLETON_PARAM(class_) \
    namespace ATP \
    { \
        template<> class_* CManualSingletonT<class_>::s_pInstance = NULL; \
    } \
    template class ATP::CManualSingletonT<class_>
}