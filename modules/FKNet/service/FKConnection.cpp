#include "FKConnection.h"

#include "FKLogger.h"

FKConnection::FKConnection(QObject* parent, qint32 id):QObject(parent),_id(id){
    FK_CONSTRUCTOR
}

FKConnection::~FKConnection(){
    FK_DESTRUCTOR
}

void FKConnection::sendMessage(const qint32 messageType, const FKConnection::MessageContainer& message){
    emit messageSent(messageType,message.isonRepresentation());
}

qint32 FKConnection::getId() const{
    return _id;
}

void FKConnection::recieveMessage(const qint32 messageType, const QJsonObject message){
    emit messageRecieved(_id,messageType,message);
}

FKConnection::MessageContainer::MessageContainer(const QJsonObject& message):_jsonRepresentation(message){

}

FKConnection::MessageContainer::MessageContainer(const QByteArray& data):_jsonRepresentation(jsonFromData(data)),_byteRepresentation(data),_byteRepresentationPrepared(true){

}

const QJsonObject& FKConnection::MessageContainer::isonRepresentation() const{
    return _jsonRepresentation;
}

const QByteArray& FKConnection::MessageContainer::byteRepresentation() const{
    if(_byteRepresentationPrepared){
        return _byteRepresentation;
    }
    _byteRepresentation = dataFromJson(_jsonRepresentation);
    _byteRepresentationPrepared = true;
    return _byteRepresentation;
}

QJsonObject FKConnection::MessageContainer::jsonFromData(const QByteArray& data){
    todo;
    return QJsonObject();
}

QByteArray FKConnection::MessageContainer::dataFromJson(const QJsonObject& message){
    todo;
    return QByteArray();
}
