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
        emit channelChanged();
    }
}

void FKMessageHandler::processMessage(const QJsonObject message){
    emit this->message(message);
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

FKMessageChannel*FKMessageHandler::channel() const{
    return _channel;
}
