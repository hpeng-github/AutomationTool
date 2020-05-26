/**
  *  定义父子控件之间简单的消息传递机制
  *
 **/

#ifndef __ATB_LIBRARYS_UIEVENT_CEVENTDELIVERER_H__
#define __ATB_LIBRARYS_UIEVENT_CEVENTDELIVERER_H__

namespace ATB
{
    class DLL_TRANS_UIEVENT CEventDeliverer
    {
    public:
        CEventDeliverer(CEventDeliverer* parent = NULL);
        virtual ~CEventDeliverer();

    protected:
        void deliverEvent(
            int nEventID,
            int nSenderID = 0,
            int nIntParam = 0,
            QString qsParam = "",
            void* pParam = NULL
        );

        void nrDeliverEvent(
            int nEventID,
            int nSenderID = 0,
            int nIntParam = 0,
            QString qsParam = "",
            void* pParam = NULL
        );

        virtual bool handleEvent(
            int nEventID,
            int nSenderID = 0,
            int nIntParam = 0,
            QString qsParam = "",
            void* pParam = NULL
        );

        CEventDeliverer*              m_pParentDeliverer;
    };
    DLL_TRANS_UIEVENT CEventDeliverer *castEventDeliverer(QWidget* pWidget);
}
#endif
