/***
  * 登陆对话框基类
  * 
  * @since 2020.5.22
***/
#ifndef __ATC_LOGINDIALOG_ILOGINDIALOG_H__
#define __ATC_LOGINDIALOG_ILOGINDIALOG_H__

namespace ATC
{
    class DLL_TRANS_LOGINDIALOG ILoginDialog : public QObject
    {
    public:
        ILoginDialog(QObject* parent = NULL);
        virtual ~ILoginDialog();
    };
}
#endif