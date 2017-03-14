#pragma once

#include <QObject>

#include <QQmlListProperty>
#include <QJsonObject>

class FKMessageHandler;

class FKMessageChannel : public QObject{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<FKMessageHandler> messageHandlers READ messageHandlers NOTIFY messageHandlersChanged)
    Q_PROPERTY(FKMessageHandler* defaultHandler READ defaultHandler WRITE setDefaultHandler NOTIFY defaultHandlerChanged)
    Q_PROPERTY(QQmlListProperty<FKMessageChannel> incomeChannels READ incomeChannels NOTIFY incomeChannelsChanged)
    Q_CLASSINFO("DefaultProperty","messageHandlers")
public:
    explicit FKMessageChannel(QObject *parent = 0);
    ~FKMessageChannel();

public slots:
    void processMessage(qint32 messageType, QJsonObject message);
    void emitMessage(qint32 messageType, QJsonObject message);

signals:
    void messageHandlersChanged();
    void defaultHandlerChanged();
    void incomeChannelsChanged();

    void outcomeMessage(qint32 messageType, QJsonObject message);

private:
    QQmlListProperty<FKMessageHandler> messageHandlers();
    FKMessageHandler* defaultHandler()const;
    void setDefaultHandler(FKMessageHandler* handler);

    QQmlListProperty<FKMessageChannel> incomeChannels();

    static void addMessageHandler(QQmlListProperty<FKMessageHandler>* property, FKMessageHandler* value);
    static FKMessageHandler* getMessageHandler(QQmlListProperty<FKMessageHandler>* property, int index);
    static void clearMessageHandlers(QQmlListProperty<FKMessageHandler>* property);
    static int countMessageHandlers(QQmlListProperty<FKMessageHandler>* property);

    static void addIncomeChannel(QQmlListProperty<FKMessageChannel>* property, FKMessageChannel* value);
    static FKMessageChannel* getIncomeChannel(QQmlListProperty<FKMessageChannel>* property, int index);
    static void clearIncomeChannels(QQmlListProperty<FKMessageChannel>* property);
    static int countIncomeChannels(QQmlListProperty<FKMessageChannel>* property);

    QMap<qint32,FKMessageHandler*> _messageHandlers;
    FKMessageHandler* _defaultHandler = nullptr;
    QList<FKMessageChannel*> _incomeChannels;
};

