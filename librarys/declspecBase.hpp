#ifndef __ATB_LIBRARY_DECLSPECBASE_HPP__
#define __ATB_LIBRARY_DECLSPECBASE_HPP__

/**
 *  __declspec(dllexport)：用于Windows中的动态库中，声明导出函数、类、对象等供外面调用，省略给出.def文件。即将函数、类等声明为导出函数，供其它程序调用，作为动态库的对外接口函数、类等。
 *                         .def文件(模块定义文件)是包含一个或多个描述各种DLL属性的Module语句的文本文件。.def文件或__declspec(dllexport)都是将公共符号导入到应用程序或从DLL导出函数。
 *                         如果不提供__declspec(dllexport)导出DLL函数，则DLL需要提供.def文件。
 *
 *  __declspec(dllimport): 用于Windows中，从别的动态库中声明导入函数、类、对象等供本动态库或exe文件使用。当你需要使用DLL中的函数时，往往不需要显示地导入函数，编译器可自动完成。
 *                         不使用__declspec(dllimport)也能正确编译代码，但使用__declspec(dllimport)使编译器可以生成更好的代码。编译器之所以能够生成更好的代码，是因为它可以确定函数是否存在于DLL中，
 *                         这使得编译器可以生成跳过间接寻址级别的代码，而这些代码通常会出现在跨DLL边界的函数调用中。声明一个导入函数，是说这个函数是从别的DLL导入。一般用于使用某个DLL的exe中。
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