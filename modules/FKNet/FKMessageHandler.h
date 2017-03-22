#pragma once

#include <QObject>
#include <QJsonObject>

class FKMessageChannel;

class FKMessageHandler : public QObject{
    Q_OBJECT
    Q_PROPERTY(bool consumeMessages READ consumeMessages WRITE setConsumeMessages NOTIFY consumeMessagesChanged)
    Q_PROPERTY(qint32 messageType READ messageType WRITE setMessageType NOTIFY messageTypeChanged)
public:
    explicit FKMessageHandler(QObject* parent = 0);
    ~FKMessageHandler();

    void setChannel(FKMessageChannel* channel);
    virtual void processMessage(QJsonObject message, const qint32 messageType);

    qint32 messageType()const;
    void setMessageType(const qint32 messageType);

    bool consumeMessages()const;
    void setConsumeMessages(const bool arg);

signals:
    void messageTypeChanged();
    void consumeMessagesChanged();

    void message(QJsonObject message, qint32 messageType);

protected:
    FKMessageChannel* channel()const;

private:
    FKMessageChannel* _channel = nullptr;
    qint32 _messageType = 0;
    bool _consumeMessages = true;
};
