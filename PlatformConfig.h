#ifndef PLATFORMCONFIG_H
#define PLATFORMCONFIG_H

#include <QDesktopWidget>
#include <QApplication>
#include <QList>
#include <QLabel>
#include <QString>
#include <QPushButton>
#include <QWidget>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QIcon>
#include <QFile>
#include <QTextCodec>
#include <cstdio>

#define FIT   (100)
#define SCREEN_WIDTH                  (QApplication::desktop()->width())
#define SCREEN_HEIGHT                 (QApplication::desktop()->height())

#define SCREEN_WIDTH_FIT              (SCREEN_WIDTH-FIT)
#define SCREEN_HEIGHT_FIT             (SCREEN_HEIGHT-FIT)

#define log(...)                      printf(__VA_ARGS__);
#define Qlog(...)                     qDebug(__VA_ARGS__);


#ifdef Q_OS_WIN32
#define LOG_FILE_DIR                 ("C:\\Windows\\System32\\winevt\\Logs")
#elif defined(Q_OS_UNIX) || defined(Q_OS_LINUX)
#define LOG_FILE_DIR                 ("/var/log")
#else
#define LOG_FILE_DIR                 ("../log")
#endif

#endif // PLATFORMCONFIG_H
