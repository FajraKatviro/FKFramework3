#include "FKRoomObject.h"

#include "FKRoomEvent.h"
#include "FKRoomAction.h"
#include "FKRoomProperty.h"

#include "FKLogger.h"

FKRoomObject::FKRoomObject(QObject *parent) : QObject(parent){
    FK_CONSTRUCTOR
}

FKRoomObject::~FKRoomObject(){
    FK_DESTRUCTOR
}

void FKRoomObject::addRoomEvent(FKRoomEvent* ev){
    ev->setIndex(_roomEvents.size());
    _roomEvents.append(ev);
}

void FKRoomObject::addRoomAction(FKRoomAction* ac){
    ac->setIndex(_roomActions.size());
    _roomActions.append(ac);
}

void FKRoomObject::addRoomProperty(FKRoomProperty* prop){
    prop->setIndex(_roomProperties.size());
    _roomProperties.append(prop);
}

void FKRoomObject::removeRoomEvent(FKRoomEvent* ev){
    ev->resetIndex();
    _roomEvents.removeOne(ev);
}

void FKRoomObject::removeRoomAction(FKRoomAction* ac){
    ac->resetIndex();
    _roomActions.removeOne(ac);
}

void FKRoomObject::removeRoomProperty(FKRoomProperty* prop){
    prop->resetIndex();
    _roomProperties.removeOne(prop);
}

void FKRoomObject::replicate(const QSet<qint32>& watchers) const{
    todo;
}
