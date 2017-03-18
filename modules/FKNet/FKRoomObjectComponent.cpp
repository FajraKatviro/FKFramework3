#include "FKRoomObjectComponent.h"

#include "FKLogger.h"

FKRoomObjectComponent::FKRoomObjectComponent(QObject* parent):FKAccessGroup(parent){
    FK_CONSTRUCTOR
}

FKRoomObjectComponent::~FKRoomObjectComponent(){
    FK_DESTRUCTOR
}

void FKRoomObjectComponent::setIndex(const qint32 index){
    _index = index;
}

void FKRoomObjectComponent::resetIndex(){
    _index = -1;
}

qint32 FKRoomObjectComponent::index() const{
    return _index;
}

QQmlListProperty<QObject> FKRoomObjectComponent::roomObjectComponentChildren(){
    return QQmlListProperty<QObject>(this,nullptr,
                                     &FKRoomObjectComponent::addRoomObjectComponentChild,
                                     &FKRoomObjectComponent::countRoomObjectComponentChildren,
                                     &FKRoomObjectComponent::getRoomObjectComponentChild,
                                     &FKRoomObjectComponent::resetRoomObjectComponentChildren);
}

void FKRoomObjectComponent::addRoomObjectComponentChild(QQmlListProperty<QObject>* property, QObject* child){
    FKRoomObjectComponent* object = qobject_cast<FKRoomObjectComponent*>(property->object);
    if(object){
        object->_roomObjectChildren.append(child);
    }else{
        FK_MLOG("Unable add room object component children qml property: no object")
    }
}

int FKRoomObjectComponent::countRoomObjectComponentChildren(QQmlListProperty<QObject>* property){
    FKRoomObjectComponent* object = qobject_cast<FKRoomObjectComponent*>(property->object);
    if(object){
        return object->_roomObjectChildren.count();
    }else{
        FK_MLOG("Unable count room object component children qml property: no object")
    }
}

QObject* FKRoomObjectComponent::getRoomObjectComponentChild(QQmlListProperty<QObject>* property, int index){
    FKRoomObjectComponent* object = qobject_cast<FKRoomObjectComponent*>(property->object);
    if(object){
        return object->_roomObjectChildren.at(index);
    }else{
        FK_MLOG("Unable get room object component children qml property: no object")
    }
}

void FKRoomObjectComponent::resetRoomObjectComponentChildren(QQmlListProperty<QObject>* property){
    FKRoomObjectComponent* object = qobject_cast<FKRoomObjectComponent*>(property->object);
    if(object){
        object->_roomObjectChildren.clear();
    }else{
        FK_MLOG("Unable reset room object component children qml property: no object")
    }
}
