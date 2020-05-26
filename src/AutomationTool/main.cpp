/**
 *
 *  主程序入口
 *  此程序仅作为一个小玩具，用来练手
 *  用qwidget实现主框架，小界面用qml
 *
**/

#include "CMainHelper.h"
#include "UiBase/BaseWidgetFormQt/CApplication.h"
#include <QtQuick/qquickview.h>

int main(int _Argc, char **_Argv)
{
    // 设置可打开文件句柄数
    _setmaxstdio(1024 * 2);

    // 建立app对象
    ATB::CApplication app(_Argc, _Argv);

    ATC::CMainHelper::initInstance();
    ATC::CMainHelper::instance()->init();

    QQuickView viewer;
    viewer.setSource(QUrl::fromLocalFile("login.qml"));
    viewer.show();

    // 开始消息循环
    //app.connect(&app, SIGNAL(lastWindowClosed()), &app, SLOT(quit()));
    int nRet = app.exec();

}