#pragma once

#include <QObject>

#include <QQmlListProperty>
#include <QJsonObject>

class FKMessageChannel;

class FKMessageGate : public QObject{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<FKMessageChannel> channels READ channels NOTIFY channelsChanged)
    Q_CLASSINFO("DefaultProperty","channels")
public:
    FKMessageGate(QObject *parent = 0);
    ~FKMessageGate();

protected:
    void processMessage(qint32 channel, qint32 messageType, QJsonObject message);
    void emitMessage(qint32 channel, qint32 messageType, QJsonObject message);

signals:
    void channelsChanged();

private:
    QQmlListProperty<FKMessageChannel> channels();

    static void addChannel(QQmlListProperty<FKMessageChannel>* property, FKMessageChannel* value);
    static FKMessageChannel* getChannel(QQmlListProperty<FKMessageChannel>* property, int index);
    static void clearChannels(QQmlListProperty<FKMessageChannel>* property);
    static int countChannels(QQmlListProperty<FKMessageChannel>* property);

    QMap<qint32,FKMessageChannel*> _channels;
};
