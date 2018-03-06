#-------------------------------------------------
#
# Project created by QtCreator 2018-03-04T10:20:34
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = YobtaBit_bot
TEMPLATE = app
INCLUDEPATH += -I/usr/local/lib \ -I/usr/local/include \ -I/home/anatoliy/sourse_root/libqtelegram-aseman-edition/telegram   \ -I/usr/lib -I./libqtelegram-aseman-edition
LIBS += /usr/lib/libqtelegram-ae.so
include(./QtTelegramBot/QtTelegramBot.pri)

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        widget.cpp

HEADERS += \
        widget.h

FORMS += \
        widget.ui
