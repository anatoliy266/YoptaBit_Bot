#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QObject>
#include <QLoggingCategory>
#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QHttpPart>
#include <QEventLoop>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QMimeDatabase>
#include <QTimer>
#include <stdio.h>

#include "qttelegrambot.h"

using namespace Telegram;


namespace Ui {
class Widget;
}

//\\\\\\\\\\\\//
class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void esukablya (QString currency);

private slots:
    void onResult(QNetworkReply *reply);
    void newMessage(Message message);
private:
    Ui::Widget *ui;
    QNetworkAccessManager *NetManager;
    Telegram::Bot *bot;
    QString count, cash, sell, buy, symbol;
    QJsonObject root;
};
//\\\\\\\\\\\\\\\\//


#endif // WIDGET_H
