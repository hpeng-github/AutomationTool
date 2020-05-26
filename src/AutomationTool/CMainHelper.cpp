#include "CMainHelper.h"
#include "CMetaTypeRegister.h"
#include <Common/utils/CManualSingletonT.hpp>

IMPL_SINGLETON_PARAM(ATC::CMainHelper);

namespace ATC
{
    CMainHelper::CMainHelper()
    {

    }

    CMainHelper::~CMainHelper()
    {

    }

    void CMainHelper::init()
    {
        _register();
    }

    void CMainHelper::_register()
    {
        _registerMetaTypes();
        _registerMetaTypesQml();
    }

}