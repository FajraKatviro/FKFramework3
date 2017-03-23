#ifndef FKCONNECTION_H
#define FKCONNECTION_H

#include <QObject>

#include <QJsonObject>
#include <QByteArray>

#include "FKNet_global.h"

class FK_NET_EXPORT FKConnection : public QObject{
    Q_OBJECT
public:
    explicit FKConnection(QObject* parent = 0, qint32 id = -1);
    ~FKConnection();

    class MessageContainer{
    public:
        MessageContainer(const QJsonObject& message);
        MessageContainer(const QByteArray& data);
        const QJsonObject& isonRepresentation()const;
        const QByteArray& byteRepresentation()const;
    private:
        static QJsonObject jsonFromData(const QByteArray& data);
        static QByteArray dataFromJson(const QJsonObject& message);
        const QJsonObject _jsonRepresentation;
        mutable QByteArray _byteRepresentation;
        mutable bool _byteRepresentationPrepared = false;
    };

    virtual void sendMessage(const qint32 messageType,const FKConnection::MessageContainer& message);

    qint32 getId()const;

protected slots:
    void recieveMessage(const qint32 messageType,const QJsonObject message);

signals:
    void messageSent(const qint32 messageType,const QJsonObject message);
    void messageRecieved(const qint32 connectionId, const qint32 messageType, const QJsonObject message);

private:
    qint32 _id;
};

#endif // FKCONNECTION_H
