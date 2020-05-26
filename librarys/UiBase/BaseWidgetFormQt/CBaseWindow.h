#ifndef __ATB_LIBRARY_CBASEWINDOW_H__
#define __ATB_LIBRARY_CBASEWINDOW_H__

#include <UiEvent/CEventWidgetT.h>

namespace ATB
{
    static const int WINDOW_DEFULAT_WIDTH  = 900;
    static const int WINDOW_DEFULAT_HEIGHT = 600;

    class DLL_TRANS_BASEWIDGET CBaseWindow : public CEventWidgetT<QMainWindow>
    {
    public:
        CBaseWindow(
            QString qsTitle,
            QString qsWindowIcon,
            QWidget* parent = NULL,
            Qt::WindowFlags flags = 0
        );
        virtual ~CBaseWindow();

    protected:
        bool       m_bShown;
        QString    m_qsIcon;
    };
}
#endif