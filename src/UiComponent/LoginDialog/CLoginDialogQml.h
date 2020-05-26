#ifndef __ATC_LOGINDIALOG_CLOGINDIALOG_H__
#define __ATC_LOGINDIALOG_CLOGINDIALOG_H__

#include "ILoginDialog.h"

namespace ATC
{
    class DLL_TRANS_LOGINDIALOG CLoginGuiQml : public ILoginDialog
    {
        Q_OBJECT
    public:
        CLoginGuiQml(QObject* parent = NULL);
        ~CLoginGuiQml();

    Q_SIGNALS:
        void sig_test();
    };
}

#endif
