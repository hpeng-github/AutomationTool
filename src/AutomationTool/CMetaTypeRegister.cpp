#include "CMetaTypeRegister.h"
#include <UiComponent/LoginDialog/CLoginDialogQml.h>

namespace ATC
{
    void _registerMetaTypes()
    {

    }

    void _registerMetaTypesQml()
    {
        qmlRegisterType<CLoginGuiQml>("atc.qml.CLoginDialogQml", 1, 0, "CLoginGuiQml");
    }
}