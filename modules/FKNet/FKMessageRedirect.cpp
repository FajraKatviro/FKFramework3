#include "FKMessageRedirect.h"

#include "FKLogger.h"

#include "FKMessageChannel.h"

FKMessageRedirect::FKMessageRedirect(QObject* parent):FKMessageHandler(parent){
    FK_CONSTRUCTOR
}

FKMessageRedirect::~FKMessageRedirect(){
    FK_DESTRUCTOR
}

FKMessageChannel* FKMessageRedirect::targetChannel() const{
    return _targetChannel;
}

void FKMessageRedirect::setTargetChannel(const FKMessageChannel* arg){
    if(_targetChannel != arg){
        _targetChannel = arg;
        emit targetChannelChanged();
    }
}

void FKMessageRedirect::processMessage(const QJsonObject message, const qint32 messageType){
    if(_targetChannel){
        _targetChannel->processMessage(messageType,message);
    }else{
        FK_MLOGV("Unable redirect message: no target channel specified",messageType)
    }
    FKMessageHandler::processMessage(message,messageType);
}
