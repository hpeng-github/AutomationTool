#ifndef __ATB_LIBRARY_DECLSPECBASE_HPP__
#define __ATB_LIBRARY_DECLSPECBASE_HPP__

/**
 *  __declspec(dllexport)������Windows�еĶ�̬���У����������������ࡢ����ȹ�������ã�ʡ�Ը���.def�ļ��������������������Ϊ����������������������ã���Ϊ��̬��Ķ���ӿں�������ȡ�
 *                         .def�ļ�(ģ�鶨���ļ�)�ǰ���һ��������������DLL���Ե�Module�����ı��ļ���.def�ļ���__declspec(dllexport)���ǽ��������ŵ��뵽Ӧ�ó�����DLL����������
 *                         ������ṩ__declspec(dllexport)����DLL��������DLL��Ҫ�ṩ.def�ļ���
 *
 *  __declspec(dllimport): ����Windows�У��ӱ�Ķ�̬�����������뺯�����ࡢ����ȹ�����̬���exe�ļ�ʹ�á�������Ҫʹ��DLL�еĺ���ʱ����������Ҫ��ʾ�ص��뺯�������������Զ���ɡ�
 *                         ��ʹ��__declspec(dllimport)Ҳ����ȷ������룬��ʹ��__declspec(dllimport)ʹ�������������ɸ��õĴ��롣������֮�����ܹ����ɸ��õĴ��룬����Ϊ������ȷ�������Ƿ������DLL�У�
 *                         ��ʹ�ñ��������������������Ѱַ����Ĵ��룬����Щ����ͨ��������ڿ�DLL�߽�ĺ��������С�����һ�����뺯������˵��������Ǵӱ��DLL���롣һ������ʹ��ĳ��DLL��exe�С�
**/

#ifdef TRANS_STATIC_BASEWIDGET
    #define DLL_TRANS_BASEWIDGET
#else
    #ifdef TRANS_EXPORT_BASEWIDGET
        #define DLL_TRANS_BASEWIDGET __declspec(dllexport)
    #else
        #define DLL_TRANS_BASEWIDGET __declspec(dllimport)
    #endif
#endif

#ifdef TRANS_STATIC_UIEVENT
    #define DLL_TRANS_UIEVENT
#else
    #ifdef TRANS_EXPORT_UIEVENT
        #define DLL_TRANS_UIEVENT __declspec(dllexport)
    #else
        #define DLL_TRANS_UIEVENT __declspec(dllimport)
    #endif
#endif

#endif // __ATB_LIBRARY_DECLSPECBASE_HPP__