#pragma once

#include <QObject>
#include <QJsonObject>

class FKMessageChannel;

class FKMessageHandler : public QObject{
    Q_OBJECT
    Q_PROPERTY(FKMessageChannel* channel READ channel NOTIFY channelChanged)
    Q_PROPERTY(qint32 messageType READ messageType WRITE setMessageType NOTIFY messageTypeChanged)
public:
    explicit FKMessageHandler(QObject* parent = 0);
    ~FKMessageHandler();

    void setChannel(FKMessageChannel* channel);
    virtual void processMessage(const QJsonObject message);

    qint32 messageType()const;
    void setMessageType(const qint32 messageType);

signals:
    void channelChanged();
    void messageTypeChanged();

    void message(QJsonObject message);

private:
    FKMessageChannel* channel()const;

    FKMessageChannel* _channel = nullptr;
    qint32 _messageType = 0;
};
