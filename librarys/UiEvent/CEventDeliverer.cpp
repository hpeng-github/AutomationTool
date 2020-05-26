#include <UiEvent/CEventDeliverer.h>
#include <UiBase/BaseWidgetFormQt/CBaseWindow.h>

namespace ATB
{
    CEventDeliverer::CEventDeliverer(CEventDeliverer* parent/* = NULL*/)
        : m_pParentDeliverer(parent)
    {

    }

    CEventDeliverer::~CEventDeliverer()
    {

    }

    void CEventDeliverer::deliverEvent(
        int nEventID,
        int nSenderID /*= 0*/,
        int nIntParam /*= 0*/,
        QString qsParam /*= ""*/,
        void* pParam /*= NULL */)
    {
        if (NULL != m_pParentDeliverer
            && !m_pParentDeliverer->handleEvent(nEventID, nSenderID, nIntParam, qsParam, pParam))
        {
            m_pParentDeliverer->deliverEvent(nEventID, nSenderID, nIntParam, qsParam, pParam);
        }
    }

    void CEventDeliverer::nrDeliverEvent(
        int nEventID,
        int nSenderID /*= 0*/,
        int nIntParam /*= 0*/,
        QString qsParam /*= ""*/,
        void* pParam /*= NULL */)
    {
        if (NULL != m_pParentDeliverer)
        {
            m_pParentDeliverer->handleEvent(nEventID, nSenderID, nIntParam, qsParam, pParam);
        }
    }

    bool CEventDeliverer::handleEvent(int nEventID,
        int nSenderID /*= 0*/,
        int nIntParam /*= 0*/,
        QString qsParam /*= ""*/,
        void* pParam /*= NULL */)
    {
        return false;
    }

    CEventDeliverer* castEventDeliverer(QWidget* pWidget)
    {
        return dynamic_cast<CEventDeliverer*>(pWidget);
    }
}
