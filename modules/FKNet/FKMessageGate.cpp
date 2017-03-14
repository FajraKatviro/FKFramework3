#include "FKMessageGate.h"

#include "FKLogger.h"

FKMessageGate::FKMessageGate(QObject* parent):FKMessageHandler(parent){
    FK_CONSTRUCTOR
}

FKMessageGate::~FKMessageGate(){
    FK_DESTRUCTOR
}

void FKMessageGate::processMessage(const QJsonObject message, const qint32 messageType){
    if(_mode == ListenToChannel){
        processMessage(message);
    }else{
        FK_MLOGV("Unexpected income message while listen to target",messageType)
    }
}

FKMessageGate::GateMode FKMessageGate::mode() const{
    return _mode;
}

QObject*FKMessageGate::target() const{
    return _target;
}

void FKMessageGate::setMode(FKMessageGate::GateMode mode){
    if(_mode != mode){
        _mode = mode;
        if(_target){
            _mode == ListenToTarget ? connectTarget(_target) : disconnectTarget(_target);
        }
        emit modeChanged();
    }
}

void FKMessageGate::setTarget(QObject* target){
    if(_target != target){
        if(_mode == ListenToTarget){
            if(_target){
                disconnectTarget(_target);
            }
            _target = target;
            if(target){
                connectTarget(target);
            }
        }else{
            _target = target;
        }
        emit targetChanged();
    }
}

void FKMessageGate::processMessage(QJsonObject message){
    Q_UNUSED(message)
}

void FKMessageGate::connectTarget(QObject* target){
    Q_UNUSED(target)
}

void FKMessageGate::disconnectTarget(QObject* target){
    Q_UNUSED(target)
}
