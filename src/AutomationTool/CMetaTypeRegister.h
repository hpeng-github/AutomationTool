/***
  * QT类型注册
  *
  * @since 2020.5.22
***/
#ifndef __ATC_AUTOMATIONTOOL_CMETATYPEREGISTER_H__
#define __ATC_AUTOMATIONTOOL_CMETATYPEREGISTER_H__

namespace ATC
{
    /***
      * 注册QT类型
    ***/
    void _registerMetaTypes();

    /***
      * 注册QML组件
    ***/
    void _registerMetaTypesQml();
}
#endif