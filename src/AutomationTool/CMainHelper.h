/***
  *  Ö÷º¯Êý¸¨ÖúÀà
  *
  *  @since  2020-5-14
***/

#ifndef _ATC__AUTOMATIONTOOL_CMAINHELPER_H_
#define _ATC__AUTOMATIONTOOL_CMAINHELPER_H_

#include <common/utils/CManualSingletonT.h>

namespace ATC
{
    class CMainHelper : public ATP::CManualSingletonT<CMainHelper>
    {
    public:
        CMainHelper();
        ~CMainHelper();

        void init();

    private:
        void _register();
    };

}

#endif
