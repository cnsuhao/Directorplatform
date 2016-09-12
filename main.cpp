#include "mainwindow.h"
#include "PlatformConfig.h"
#include "QLiveWidget.h"
#include "QVideoWidget.h"
#include "QDirWidget.h"

#include <QApplication>
#include <QTextCodec>
#include <QTranslator>

class QLoadSkin
{
public:
    static void setStyle(const QString &style)
    {
        QFile qss(style);
        qss.open(QFile::ReadOnly);
        qApp->setStyleSheet(qss.readAll());
        qss.close();
    }
};





//#define VIDEO_ONCE   // test for video Widget only!

//#define LIVE_VIDEO

#define DIRECTOR_VIDEO

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
#ifdef Q_OS_WIN32
    QTextCodec::setCodecForTr(QTextCodec::codecForName("utf8"));
#endif
#if defined(Q_OS_LINUX) || defined(Q_OS_UNIX)
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf8"));
#endif

    // make it internationalization
    QTranslator translator;
    translator.load(QString(":/cfg/director_zh"));
    app.installTranslator(&translator);

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



    return app.exec();

}
