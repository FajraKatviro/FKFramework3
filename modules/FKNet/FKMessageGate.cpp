#include "FKMessageGate.h"

#include "FKMessageChannel.h"

#include "FKLogger.h"

FKMessageGate::FKMessageGate(QObject* parent):QObject(parent){
    FK_CONSTRUCTOR
}

FKMessageGate::~FKMessageGate(){
    FK_DESTRUCTOR
}

void FKMessageGate::processMessage(qint32 channel, qint32 messageType, QJsonObject message){
    auto targetChannel = _channels.value(channel,nullptr);
    if(targetChannel){
        targetChannel->processMessage(messageType,message);
    }else{
        FK_MLOGV("Unable process message: channel not found", channel)
    }
}

void FKMessageGate::emitMessage(qint32 channel, qint32 messageType, QJsonObject message){
    auto targetChannel = _channels.value(channel,nullptr);
    if(targetChannel){
        targetChannel->emitMessage(messageType,message);
    }else{
        FK_MLOGV("Unable emit message: channel not found", channel)
    }
}

QQmlListProperty<FKMessageChannel> FKMessageGate::channels(){
    return QQmlListProperty<FKMessageChannel>(this,nullptr,
                                           &FKMessageGate::addChannel,
                                           &FKMessageGate::countChannels,
                                           &FKMessageGate::getChannel,
                                           &FKMessageGate::clearChannels);
}

void FKMessageGate::addChannel(QQmlListProperty<FKMessageChannel>* property, FKMessageChannel* value){
    FKMessageGate* gate=qobject_cast<FKMessageGate*>(property->object);
    if(gate && value){
        if(gate->_channels.contains(value->channel())){
            FK_MLOGV("Unable add already existed channel",value->channel())
            return;
        }
        gate->_channels[value->channel()]=value;
        //emit channelsChanged();
    }else{
        FK_MLOG("Unable add channel to gate: invalid pointer")
    }
}

FKMessageChannel* FKMessageGate::getChannel(QQmlListProperty<FKMessageChannel>* property, int index){
    FKMessageGate* gate=qobject_cast<FKMessageGate*>(property->object);
    if(gate){
        if(index<0 || gate->_channels.size() <= index){
            FK_MLOGV("Invalid channel index",index)
            return nullptr;
        }
        return (gate->_channels.constBegin() + index).value();
    }else{
        FK_MLOG("Unable get channel at gate: invalid gate pointer")
        return nullptr;
    }
}

void FKMessageGate::clearChannels(QQmlListProperty<FKMessageChannel>* property){
    FKMessageGate* gate=qobject_cast<FKMessageGate*>(property->object);
    if(gate){
        gate->_channels.clear();
        //emit channelsChanged();
    }else{
        FK_MLOG("Unable clear channels at gate: invalid gate pointer")
    }
}

int FKMessageGate::countChannels(QQmlListProperty<FKMessageChannel>* property){
    FKMessageGate* gate=qobject_cast<FKMessageGate*>(property->object);
    if(gate){
        return gate->_channels.count();
    }else{
        FK_MLOG("Unable count channels at gate: invalid gate pointer")
        return 0;
    }
}



