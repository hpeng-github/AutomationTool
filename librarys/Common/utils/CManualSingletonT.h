/***
  *  µ¥ÀýÄ£°åÀà
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

        CManualSingletonT(const CManualSingletonT&) = delete;  // ½ûÖ¹¿½±´
        CManualSingletonT& operator = (const CManualSingletonT&) = delete;  // ½ûÖ¹¸³Öµ

    private:
        static TypeClass*               s_pInstance;
    };
}
#endif
