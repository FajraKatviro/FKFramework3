#include "FKMessageHandler.h"

#include "FKLogger.h"

FKMessageHandler::FKMessageHandler(QObject *parent) : QObject(parent){
    FK_CONSTRUCTOR
}

FKMessageHandler::~FKMessageHandler(){
    FK_DESTRUCTOR
}

void FKMessageHandler::setChannel(FKMessageChannel* channel){
    if(channel != _channel){
        _channel = channel;
    }
}

void FKMessageHandler::processMessage(const QJsonObject message, const qint32 messageType){
    emit this->message(message, messageType);
}

qint32 FKMessageHandler::messageType() const{
    return _messageType;
}

void FKMessageHandler::setMessageType(const qint32 messageType){
    if(_messageType != messageType){
        _messageType = messageType;
        emit messageTypeChanged();
    }
}

bool FKMessageHandler::consumeMessages() const{
    return _consumeMessages;
}

void FKMessageHandler::setConsumeMessages(const bool arg){
    if(_consumeMessages != arg){
        _consumeMessages = arg;
        emit consumeMessagesChanged();
    }
}

FKMessageChannel*FKMessageHandler::channel() const{
    return _channel;
}
