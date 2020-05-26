#include <UiBase/BaseWidgetFormQt/CBaseWindow.h>

namespace ATB
{
    CBaseWindow::CBaseWindow(
        QString qsTitle,
        QString qsWindowIcon,
        QWidget *parent /*= NULL*/,
        Qt::WindowFlags flags /*= 0*/
    )
        : CEventWidgetT<QMainWindow>(parent, flags)
        , m_qsIcon(qsWindowIcon)
        , m_bShown(false)
    {
        setWindowTitle(qsTitle);
        setAttribute(Qt::WA_DeleteOnClose, false);
        setWindowIcon(QIcon(":/" + m_qsIcon));
    }

    CBaseWindow::~CBaseWindow()
    {

    }
}