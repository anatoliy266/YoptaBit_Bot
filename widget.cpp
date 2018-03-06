#include "widget.h"
#include "ui_widget.h"
#include <ctime>

using namespace Telegram;

#define TOKEN "550521659:AAGSxeSkIXNXdwhfxeJRDkpd1b88vo_vyL0"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    NetManager = new QNetworkAccessManager();
    connect(NetManager, &QNetworkAccessManager::finished, this, &Widget::onResult);
    NetManager->get(QNetworkRequest(QUrl("https://blockchain.info/ru/ticker")));
    bot = new Telegram::Bot(TOKEN, true, 500, 4);
    connect(bot, SIGNAL(message(Message)), this, SLOT(newMessage(Message)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::onResult(QNetworkReply *reply) {
    if(!reply->error()) {
        QJsonDocument document = QJsonDocument::fromJson(reply->readAll());
        root = document.object();
        esukablya("USD");
    }
    reply->deleteLater();
}

void Widget::newMessage(Message message)
{
    if (bot && message.type == Telegram::Message::TextType) {
        if (message.string == "/esukablya") {
        Message btc;
        btc.string = "Текущий курс битка к доллару: 1 BTC =" + cash + " " + symbol + ". Последняя сделка купли валюты стоила " + buy + " " + symbol + ". Последняя сделака продажи валюты стоила " + sell + " " + symbol;
        bot->sendMessage(message.from.id, btc.string);
        };
    };
}

void Widget::esukablya(QString currency) {
    QJsonValue jv = root.value(currency);
    if (jv.isObject()) {
        QJsonObject usd = jv.toObject();
        ui->textEdit->append(QString::number(usd.value("15m").toDouble()) + " " + usd.value("symbol").toString());
        symbol = usd.value("symbol").toString();
        cash = QString::number(usd.value("15m").toDouble());
        buy = QString::number(usd.value("buy").toDouble());
        sell = QString::number(usd.value("sell").toDouble());
    }
}
