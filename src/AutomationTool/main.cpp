/**
 *
 *  ���������
 *  �˳������Ϊһ��С��ߣ���������
 *  ��qwidgetʵ������ܣ�С������qml
 *
**/

#include "CMainHelper.h"
#include "UiBase/BaseWidgetFormQt/CApplication.h"
#include <QtQuick/qquickview.h>

int main(int _Argc, char **_Argv)
{
    // ���ÿɴ��ļ������
    _setmaxstdio(1024 * 2);

    // ����app����
    ATB::CApplication app(_Argc, _Argv);

    ATC::CMainHelper::initInstance();
    ATC::CMainHelper::instance()->init();

    QQuickView viewer;
    viewer.setSource(QUrl::fromLocalFile("login.qml"));
    viewer.show();

    // ��ʼ��Ϣѭ��
    //app.connect(&app, SIGNAL(lastWindowClosed()), &app, SLOT(quit()));
    int nRet = app.exec();

}