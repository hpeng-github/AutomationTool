/***
  *  ����ģ����
  *
  *  @since  2020-5-14
***/

#ifndef _ATP_UTILS_CMANUALSINGLETONT_H_
#define _ATP_UTILS_CMANUALSINGLETONT_H_

namespace ATP
{
    template<class TypeClass>
    class CManualSingletonT
    {
    public:
        static inline TypeClass* instance();
        static void release();

        template<typename ...Args>
        static void initInstance(Args&&... args);
        
        explicit CManualSingletonT();
        ~CManualSingletonT();

        CManualSingletonT(const CManualSingletonT&) = delete;  // ��ֹ����
        CManualSingletonT& operator = (const CManualSingletonT&) = delete;  // ��ֹ��ֵ

    private:
        static TypeClass*               s_pInstance;
    };
}
#endif
