#include "MainWindow.h"
#include "PlatformConfig.h"
#include "QLiveWidget.h"
#include "QVideoWidget.h"
#include "QDirWidget.h"

#include <QApplication>
#include <QTextCodec>
#include <QTranslator>

/*
 * cross platform*/


#if defined(Q_OS_WIN32)
#include <windows.h>
bool isRunning()
{
    HANDLE m_hmutex=CreateMutex(NULL,FALSE,L"DirectorPlatform");
    if(GetLastError()==ERROR_ALREADY_EXISTS)
    {
        CloseHandle(m_hmutex);
        m_hmutex = NULL;
        return true;
    }
    else
    {
        return false;
    }
}
#endif

#if defined (Q_OS_LINUX) || defined(Q_OS_UNIX)
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
bool isRunning()
{
    const char file_name[]="/tmp/lockfile";
    int fd = open(file_name,O_WRONLY|O_CREAT,0644);
    int flock = lockf(fd,F_TLOCK,0);
    if(fd==-1)
    {
        return true;
    }
    if(flock==-1)
    {
        return true;
    }
    return false;
}
#endif




int main(int argc, char *argv[])
{
#ifdef Q_OS_WIN32
    QTextCodec::setCodecForTr(QTextCodec::codecForName("utf8"));
#endif
#if defined(Q_OS_LINUX) || defined(Q_OS_UNIX)
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf8"));
#endif

    QApplication app(argc, argv);

    // make it internationalization
    QTranslator translator;
    translator.load(QString(":/cfg/director_zh"));
    app.installTranslator(&translator);
    // Singletion for App
    if(isRunning())
    {
       QMessageBox::warning(0,QObject::tr("tip"),QObject::tr("App is opend"),0,0);
      return 0;
    }


    // load qss
    QLoadSkin::setGlobalStyle(":/skin/dir1.qss");

//Test


    MainWindow w;
    w.setWindowIcon(QIcon(":/skin/icon1.png"));
    w.setWindowTitle(MainWindow::tr("DirectorPlatform"));
    w.resize(800,800);
    w.show();

    return app.exec();

}
