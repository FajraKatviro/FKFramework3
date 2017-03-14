#include "FKMessageChannel.h"

#include "FKMessageHandler.h"

#include "FKLogger.h"

FKMessageChannel::FKMessageChannel(QObject* parent) : QObject(parent){
    FK_CONSTRUCTOR
}

FKMessageChannel::~FKMessageChannel(){
    FK_DESTRUCTOR
}

void FKMessageChannel::processMessage(qint32 messageType, QJsonObject message){
    auto handler = _messageHandlers.value(messageType,_defaultHandler);
    if(handler){
        handler->processMessage(message,messageType);
        if(!handler->consumeMessages()){
            emitMessage(messageType,message);
        }
    }else{
        emitMessage(messageType,message);
    }
}

void FKMessageChannel::emitMessage(qint32 messageType, QJsonObject message){
    emit outcomeMessage(messageType,message);
}

QQmlListProperty<FKMessageHandler> FKMessageChannel::messageHandlers(){
    return QQmlListProperty<FKMessageHandler>(this,nullptr,
                                              &FKMessageChannel::addMessageHandler,
                                              &FKMessageChannel::countMessageHandlers,
                                              &FKMessageChannel::getMessageHandler,
                                              &FKMessageChannel::clearMessageHandlers);
}

FKMessageHandler*FKMessageChannel::defaultHandler() const{
    return _defaultHandler;
}

void FKMessageChannel::setDefaultHandler(FKMessageHandler* handler){
    if(_defaultHandler != handler){
        if(_defaultHandler){
            _defaultHandler->setChannel(nullptr);
        }
        _defaultHandler = handler;
        if(_defaultHandler){
            _defaultHandler->setChannel(this);
        }
        emit defaultHandlerChanged();
    }
}

QQmlListProperty<FKMessageChannel> FKMessageChannel::incomeChannels(){
    return QQmlListProperty<FKMessageChannel>(this,nullptr,
                                              &FKMessageChannel::addIncomeChannel,
                                              &FKMessageChannel::countIncomeChannels,
                                              &FKMessageChannel::getIncomeChannel,
                                              &FKMessageChannel::clearIncomeChannels);
}

void FKMessageChannel::addMessageHandler(QQmlListProperty<FKMessageHandler>* property, FKMessageHandler* value){
    FKMessageChannel* channel=qobject_cast<FKMessageChannel*>(property->object);
    if(channel && value){
        if(channel->_messageHandlers.contains(value->messageType())){
            FK_MLOGV("Unable add already registered message type",value->messageType())
            return;
        }
        channel->_messageHandlers[value->messageType()]=value;
        value->setChannel(channel);
        //emit messageHandlersChanged();
    }else{
        FK_MLOG("Unable add message handler to channel: invalid pointer")
    }
}

FKMessageHandler* FKMessageChannel::getMessageHandler(QQmlListProperty<FKMessageHandler>* property, int index){
    FKMessageChannel* channel=qobject_cast<FKMessageChannel*>(property->object);
    if(channel){
        if(index<0 || channel->_messageHandlers.size() <= index){
            FK_MLOGV("Invalid message handler index",index)
            return nullptr;
        }
        return (channel->_messageHandlers.constBegin() + index).value();
    }else{
        FK_MLOG("Unable get message handler at channel: invalid channel pointer")
        return nullptr;
    }
}

void FKMessageChannel::clearMessageHandlers(QQmlListProperty<FKMessageHandler>* property){
    FKMessageChannel* channel=qobject_cast<FKMessageChannel*>(property->object);
    if(channel){
        for(FKMessageHandler* h:channel->_messageHandlers){
            h->setChannel(nullptr);
        }
        channel->_messageHandlers.clear();
        //emit messageHandlersChanged();
    }else{
        FK_MLOG("Unable clear message handlers at channel: invalid channel pointer")
    }
}

int FKMessageChannel::countMessageHandlers(QQmlListProperty<FKMessageHandler>* property){
    FKMessageChannel* channel=qobject_cast<FKMessageChannel*>(property->object);
    if(channel){
        return channel->_messageHandlers.count();
    }else{
        FK_MLOG("Unable count message handlers at channel: invalid channel pointer")
        return 0;
    }
}

void FKMessageChannel::addIncomeChannel(QQmlListProperty<FKMessageChannel>* property, FKMessageChannel* value){
    FKMessageChannel* channel=qobject_cast<FKMessageChannel*>(property->object);
    if(channel && value){
        if(channel->_incomeChannels.contains(value)){
            FK_MLOGV("Unable add income channel multiple times",value->channel())
            return;
        }
        channel->_incomeChannels.append(value);
        connect(value,SIGNAL(outcomeMessage(qint32,QJsonObject)),channel,SLOT(processMessage(qint32,QJsonObject)));
        //emit incomeChannelsChanged();
    }else{
        FK_MLOG("Unable add income channel to channel: invalid pointer")
    }
}

FKMessageChannel* FKMessageChannel::getIncomeChannel(QQmlListProperty<FKMessageChannel>* property, int index){
    FKMessageChannel* channel=qobject_cast<FKMessageChannel*>(property->object);
    if(channel){
        if(index<0 || channel->_incomeChannels.size() <= index){
            FK_MLOGV("Invalid income channel index",index)
            return nullptr;
        }
        return channel->_incomeChannels.at(index);
    }else{
        FK_MLOG("Unable get income channel at channel: invalid channel pointer")
        return nullptr;
    }
}

void FKMessageChannel::clearIncomeChannels(QQmlListProperty<FKMessageChannel>* property){
    FKMessageChannel* channel=qobject_cast<FKMessageChannel*>(property->object);
    if(channel){
        for(FKMessageChannel* c:channel->_incomeChannels){
            disconnect(c,SIGNAL(outcomeMessage(qint32,QJsonObject)),channel,SLOT(processMessage(qint32,QJsonObject)));
        }
        channel->_incomeChannels.clear();
        //emit incomeChannelsChanged();
    }else{
        FK_MLOG("Unable clear income channels at channel: invalid channel pointer")
    }
}

int FKMessageChannel::countIncomeChannels(QQmlListProperty<FKMessageChannel>* property){
    FKMessageChannel* channel=qobject_cast<FKMessageChannel*>(property->object);
    if(channel){
        return channel->_incomeChannels.count();
    }else{
        FK_MLOG("Unable count income channels at channel: invalid channel pointer")
        return 0;
    }
}


