#ifndef __ATB_LIBRARY_APPLICATION_H__
#define __ATB_LIBRARY_APPLICATION_H__

namespace ATB
{
    class DLL_TRANS_BASEWIDGET CApplication : public QApplication
    {
    public:
        CApplication(int &argc, char **argv);
        ~CApplication();
    
    };
}
#endif