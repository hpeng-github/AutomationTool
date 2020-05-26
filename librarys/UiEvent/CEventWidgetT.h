/**
  *  事件传递模板类
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

    // 由于qt控件构造函数不同，这里用隐式实例化
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
            // 这个地方没搞懂为啥要加一下TWidget::才可以编过
            TWidget::setWindowFlags(f);
        }

        /**
         *  设置唯一内部控件，用于自动调整其区域
         *  @param  pWidget         唯一内部控件
         *  @param  nLeftSpace      左边距
         *  @param  nTopSpace       上边距
         *  @param  nRightSpace     右边距
         *  @param  nBottomSpace    下边距
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
         *  设置唯一内部控件，永远以固定大小居中布局
         *  @param  pWidget         唯一内部控件
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
         *  是否有某个子控件
         *  @param  pWidget         子控件
         *  @return                 是否有子控件
         */
        bool hasChildWidget(const QWidget* pWidget) const
        {
            return hasChildWidget(this, pWidget);
        }

        /**
         *  母控件是否有某个子控件
         *  非static的hasChildWidget的递归实现
         *  @param  pParentWidget   母控件
         *  @param  pChildWidget    子控件
         *  @return                 母控件是否有子控件
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
         *  递归对控件及其所有子控件作同样的操作
         *  @param  pWidget         控件
         *  @param  func            操作函数
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
         *  和showEvent、hideEvent强关联，返回当前widget是否可见的信息
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