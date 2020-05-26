/**
  *  �¼�����ģ����
  *
 **/

#ifndef __ATB_LIBRARYS_UIEVENT_CEVENTWIDGET_T_H__
#define __ATB_LIBRARYS_UIEVENT_CEVENTWIDGET_T_H__

#include <UiEvent/eventDef.h>
#include <UiEvent/CEventDeliverer.h>
#include <QtWidgets/qwidget.h>

namespace ATB
{
    typedef boost::function<void(QWidget*)> EnumWidgetFunc;

    // ����qt�ؼ����캯����ͬ����������ʽʵ����
    template <class TWidget>
    class CEventWidgetT : public TWidget, public CEventDeliverer
    {
    public:
        CEventWidgetT(QWidget* parent, Qt::WindowFlags f = 0)
            : TWidget(parent)
            , CEventDeliverer(castEventDeliverer(parent))
            , m_pInnerWidget(NULL)
            , m_nInnerLeftSpace(0)
            , m_nInnerTopSpace(0)
            , m_nInnerRightSpace(0)
            , m_nInnerBottomSpace(0)
            , m_bInnerStrech(false)
            , m_bInShow(false)
        {
            // ����ط�û�㶮ΪɶҪ��һ��TWidget::�ſ��Ա��
            TWidget::setWindowFlags(f);
        }

        /**
         *  ����Ψһ�ڲ��ؼ��������Զ�����������
         *  @param  pWidget         Ψһ�ڲ��ؼ�
         *  @param  nLeftSpace      ��߾�
         *  @param  nTopSpace       �ϱ߾�
         *  @param  nRightSpace     �ұ߾�
         *  @param  nBottomSpace    �±߾�
         */
        void setInnerStretchWidget(QWidget* pWidget, int nLeftSpace = 0, int nTopSpace = 0, int nRightSpace = 0, int nBottomSpace = 0)
        {
            m_pInnerWidget = pWidget;
            m_nInnerLeftSpace = nLeftSpace;
            m_nInnerTopSpace = nTopSpace;
            m_nInnerRightSpace = nRightSpace;
            m_nInnerBottomSpace = nBottomSpace;
            m_bInnerStrech = true;
            if (NULL != pWidget)
            {
                setChild(pWidget);
            }
        }

        /**
         *  ����Ψһ�ڲ��ؼ�����Զ�Թ̶���С���в���
         *  @param  pWidget         Ψһ�ڲ��ؼ�
         */
        void setInnerFixWidget(QWidget* pWidget)
        {
            m_pInnerWidget = pWidget;
            m_nInnerLeftSpace = -1;
            m_nInnerTopSpace = -1;
            m_nInnerRightSpace = -1;
            m_nInnerBottomSpace = -1;
            m_bInnerStrech = false;
            if (NULL != pWidget)
            {
                setChild(pWidget);
            }
        }

        void setChild(QWidget* pWidget)
        {
            if (NULL != pWidget)
            {
                pWidget->setParent(this);
            }
        }

        void grabMouseSafely()
        {
            TWidget::grabMouse();
        }

        /**
         *  �Ƿ���ĳ���ӿؼ�
         *  @param  pWidget         �ӿؼ�
         *  @return                 �Ƿ����ӿؼ�
         */
        bool hasChildWidget(const QWidget* pWidget) const
        {
            return hasChildWidget(this, pWidget);
        }

        /**
         *  ĸ�ؼ��Ƿ���ĳ���ӿؼ�
         *  ��static��hasChildWidget�ĵݹ�ʵ��
         *  @param  pParentWidget   ĸ�ؼ�
         *  @param  pChildWidget    �ӿؼ�
         *  @return                 ĸ�ؼ��Ƿ����ӿؼ�
         */
        static bool hasChildWidget(const QWidget* pParentWidget, const QWidget*pChildWidget)
        {
            if (NULL != pChildWidget)
            {
                QWidget* pOneWidget = pChildWidget->parentWidget();
                while (NULL != pOneWidget)
                {
                    if (pOneWidget == pParentWidget)
                    {
                        return true;
                    }
                    pOneWidget = pOneWidget->parentWidget();
                }
            }
            return false;
        }

        /**
         *  �ݹ�Կؼ����������ӿؼ���ͬ���Ĳ���
         *  @param  pWidget         �ؼ�
         *  @param  func            ��������
         */
        static void enumChildrenRecursive(QWidget* pWidget, EnumWidgetFunc func)
        {
            func(pWidget);
            if (NULL != pWidget)
            {
                QObjectList list = pWidget->children();
                foreach(QObject* pObject, list)
                {
                    QWidget* pQWidget = dynamic_cast<QWidget*>(pObject);
                    if (NULL != pQWidget)
                    {
                        enumChildrenRecursive(pQWidget, func);
                    }
                }
            }
        }

        /**
         *  ��showEvent��hideEventǿ���������ص�ǰwidget�Ƿ�ɼ�����Ϣ
         */
        bool isInShow() const
        {
            return m_bInShow;
        }

    protected:
        void focusInEvent(QFocusEvent* e)
        {
            TWidget::focusInEvent(e);

            deliverEvent(EVT_BASE_WIDGET_ACTIVE, 0, 0, "", this);
        }

        void resizeEvent(QResizeEvent* e)
        {
            TWidget::resizeEvent(e);

            resetInnerWidgetGeometry(e->size());
        }

        void showEvent(QShowEvent* e)
        {
            TWidget::showEvent(e);

            m_bInShow = true;
        }

        void hideEvent(QHideEvent* e)
        {
            TWidget::hideEvent(e);

            m_bInShow = false;
        }

        void resetInnerWidgetGeometry(QSize size)
        {
            if (NULL != m_pInnerWidget)
            {
                if (m_bInnerStrech)
                {
                    m_pInnerWidget->setGeometry(
                        m_nInnerLeftSpace,
                        m_nInnerTopSpace,
                        size.width() - m_nInnerLeftSpace - m_nInnerRightSpace,
                        size.height() - m_nInnerTopSpace - m_nInnerBottomSpace
                    );
                }
                else
                {
                    m_pInnerWidget->move(
                        (size.width() - m_pInnerWidget->width()) / 2,
                        (size.height() - m_pInnerWidget->height()) / 2
                    );
                }
            }
        }

        void changeEvent(QEvent *e)
        {
            TWidget::changeEvent(e);

            if (QEvent::ParentChange == e->type())
            {
                m_pParentDeliverer = castEventDeliverer(TWidget::parentWidget());
                int a = 0;
            }
        }

        QWidget*                m_pInnerWidget;
        int                     m_nInnerLeftSpace;
        int                     m_nInnerTopSpace;
        int                     m_nInnerRightSpace;
        int                     m_nInnerBottomSpace;
        bool                    m_bInnerStrech;
        bool                    m_bInShow;
    };
}

#endif