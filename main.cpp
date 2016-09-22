#include "View/MainWindow.h"
#include "View/PlatformConfig.h"
#include "View/QLiveWidget.h"
#include "Model/QVideoWidget.h"
#include "View/QDirWidget.h"
#include "Model/QYoohooMainWindow.h"
#include <QApplication>
#include <QTextCodec>
#include <QTranslator>

#include <QTextStream>
#include <QMutex>
#include <QDir>
#include <QDateTime>


#include "View/QSystemSettingWidget.h"


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


void outputMessage(QtMsgType type, const char* msg)
{
    static QMutex mutex;
    mutex.lock();

    QString text;
    switch(type)
    {
    case QtDebugMsg:
        text = QString("Debug:");
        break;

    case QtWarningMsg:
        text = QString("Warning:");
        break;

    case QtCriticalMsg:
        text = QString("Critical:");
        break;

    case QtFatalMsg:
        text = QString("Fatal:");
    }

    QString current_date_time = QDateTime::currentDateTime().toString("hh:mm:ss ddd");
    QString current_date = QString("(%1)").arg(current_date_time);
    QString message = QString("%1 %2 %3").arg(text).arg(msg).arg(current_date);

    QDir dir;
    if(!dir.exists(LOG_FILE_DIR))
    {
        dir.mkdir(LOG_FILE_DIR);
    }

    QFile file(QString(LOG_FILE_DIR)+"/"+QDateTime::currentDateTime().toString("yyyy-MM-dd")+".txt");
    file.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream text_stream(&file);
    text_stream << message << "\r\n";
    file.flush();
    file.close();

    mutex.unlock();
}



int main(int argc, char *argv[])
{
#ifdef Q_OS_WIN32
    QTextCodec::setCodecForTr(QTextCodec::codecForName("utf8"));
#endif
#if defined(Q_OS_LINUX) || defined(Q_OS_UNIX)
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf8"));
#endif

    QApplication app(argc, argv);

    //make logFile
    qInstallMsgHandler(outputMessage);



    // make it internationalization
    QTranslator translator;
    qDebug("translator complete");
    translator.load(QString(":/cfg/director_zh"));
    app.installTranslator(&translator);
    qDebug("translator complete");
    // Singletion for App
    if(isRunning())
    {
       QMessageBox::warning(0,QObject::tr("tip"),QObject::tr("App is opened"),0,0);
      return 0;
    }
    // load qss
    QLoadSkin::setGlobalStyle(":/skin/dir1.qss");
    qDebug("load skin file complete");

//Test


//    MainWindow *h = new MainWindow;
//    QYoohooMainWindow w;
//    w.setTitleToYoohoo(MainWindow::tr("DirectorPlatform"));
//    w.addWidgetToYoohoo(h);
//    //w.setWindowFlags(Qt::FramelessWindowHint);
//    w.setWindowIcon(QIcon(":/skin/icon1.png"));
//    w.resize(800,800);
//    w.show();

    QSettingWidget w;
    w.show();

    return app.exec();


}
