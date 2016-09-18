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




//#define VIDEO_ONCE   // test for video Widget only!

//#define LIVE_VIDEO

//#define DIRECTOR_VIDEO

int main(int argc, char *argv[])
{
#ifdef Q_OS_WIN32
    QTextCodec::setCodecForTr(QTextCodec::codecForName("utf8"));
#endif
#if defined(Q_OS_LINUX) || defined(Q_OS_UNIX)
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf8"));
#endif

    QApplication app(argc, argv);

    // Singletion for App
    if(isRunning())
    {
       QMessageBox::warning(0,"1","2",0,0);
      return 0;
    }


    // make it internationalization
    QTranslator translator;
    translator.load(QString(":/cfg/director_zh"));
    app.installTranslator(&translator);

    // load qss
    QLoadSkin::setGlobalStyle(":/skin/dir1.qss");

//Test

#ifdef VIDEO_ONCE
    QVideoWidget w;
    w.setWindowTitle(MainWindow::tr("DirectorPlatform"));
    w.show();
#endif



#ifdef LIVE_VIDEO

    QLiveWidget w;
    w.setWindowTitle(MainWindow::tr("DirectorPlatform"));
    w.resize(SCREEN_WIDTH_FIT,SCREEN_HEIGHT_FIT);
    w.show();
#endif


#if 0
    QWidget w;
    QVideoWidget *video=new QVideoWidget();
    QLabel *lab=new QLabel("123456789");
    lab->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Fixed);
    lab->setAlignment(Qt::AlignCenter);
    QVBoxLayout *CC=new QVBoxLayout;
    QHBoxLayout *hb=new QHBoxLayout;
    hb->setSpacing(0);
    hb->addWidget(lab);
    QRect re=CC->geometry();
    re.setHeight(30);
    hb->setGeometry(re);
    QVBoxLayout *vb=new QVBoxLayout;
    CC->setSpacing(0);
    CC->addLayout(hb,1);
    CC->addLayout(vb,10);
    vb->addWidget(video);
    w.setLayout(CC);

    //video->show();
    w.show();

#endif

#ifdef DIRECTOR_VIDEO
    QDirWidget w;
    w.resize(200,200);
    w.show();
#endif


    MainWindow w;
    w.setWindowIcon(QIcon(":/skin/icon1.png"));
    w.setWindowTitle(MainWindow::tr("DirectorPlatform"));
    w.resize(800,800);
    w.show();

    return app.exec();

}
