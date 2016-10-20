#-------------------------------------------------
#
# Project created by QtCreator 2016-09-09T14:30:32
#
#-------------------------------------------------


QT       += core gui
QT       += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Directorplatform
TEMPLATE = app

ICON +=icon1.png
TRANSLATIONS +=director_zh.ts \
               director_en.ts

#CONFIG += c++11

QMAKE_CXXFLAGS += -std=c++0x

SOURCES += main.cpp\
    Model/QYoohooMainWindow.cpp \
    View/MainWindow.cpp \
    View/QCtrlWindow.cpp \
    View/QDirWidget.cpp \
    View/QFunctionWidget.cpp \
    View/QLiveWidget.cpp \
    Model/QButton.cpp \
    Model/QVideoWidget.cpp \
    View/QSystemSettingWidget.cpp \
    View/QLuboSettingWidget.cpp \
    Model/TipDialog.cpp \
    Model/MutiSocket.cpp \
    Model/ConfigFile.cpp

HEADERS  += \
    Model/QYoohooMainWindow.h \
    View/MainWindow.h \
    View/PlatformConfig.h \
    View/QCtrlWindow.h \
    View/QDirWidget.h \
    View/QFunctionWidget.h \
    View/QLiveWidget.h \
    Model/QButton.h \
    Model/QVideoWidget.h \
    View/QSystemSettingWidget.h \
    View/QLuboSettingWidget.h \
    Model/TipDialog.h \
    Model/MutiSocket.h \
    Model/ConfigFile.h

RESOURCES += \
    src.qrc

RC_FILE +=app.rc
OTHER_FILES +=
