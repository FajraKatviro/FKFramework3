#include "FKAccessGroup.h"

#include "FKLogger.h"

FKAccessGroup::FKAccessGroup(QObject *parent) : QObject(parent){
    FK_CONSTRUCTOR
}

FKAccessGroup::~FKAccessGroup(){
    FK_DESTRUCTOR
}

QSet<qint32> FKAccessGroup::access() const{
    return _access;
}

void FKAccessGroup::setAcceess(const QSet& access){
    if (access != _access) {
        _access = access;
        invalidateCache();
        emit accessChanged();
    }
}

QSet<qint32> FKAccessGroup::totalAccess() const{
    if(_totalAccessCache.isValid){
        return _totalAccessCache.value;
    }

    QSet<qint32> value(_access);
    for(auto group:_accessGroups){
        value.unite(group->totalAccess());
    }
    _totalAccessCache.value = value;
    _totalAccessCache.isValid = true;
    return value;
}

void FKAccessGroup::addDependentGroup(FKAccessGroup* object){
    _dependentAccessGroups.append(object);
    _dependentAccessCache.value = _dependentAccessGroups.toSet();
}

void FKAccessGroup::removeDependentGroup(FKAccessGroup* object){
    if(_dependentAccessGroups.removeOne(object)){
        _dependentAccessCache.value = _dependentAccessGroups.toSet();
    }
}

QList<qint32> FKAccessGroup::accessList() const{
    return _access.toList();
}

void FKAccessGroup::setAccessList(const QList<qint32> list){
    setAcceess(list.toSet());
}

QQmlListProperty<FKAccessGroup> FKAccessGroup::accessGroups(){
    return QQmlListProperty<FKAccessGroup>(this,nullptr,
                                           &FKAccessGroup::addAccessGroup,
                                           &FKAccessGroup::countAccessGroups,
                                           &FKAccessGroup::getAccessGroup,
                                           &FKAccessGroup::resetAccessGroups);
}

FKAccessGroup* FKAccessGroup::getAccessGroup(QQmlListProperty<FKAccessGroup>* property, int index){
    FKAccessGroup* object = qobject_cast<FKAccessGroup*>(property->object);
    if(object){
        return object->getAccessGroup(index);
    }else{
        FK_MLOG("Unable get access group qml property: no object")
        return nullptr;
    }
}

int FKAccessGroup::countAccessGroups(QQmlListProperty<FKAccessGroup>* property){
    FKAccessGroup* object = qobject_cast<FKAccessGroup*>(property->object);
    if(object){
        return object->countAccessGroups();
    }else{
        FK_MLOG("Unable count access group qml property: no object")
        return nullptr;
    }
}

void FKAccessGroup::addAccessGroup(QQmlListProperty<FKAccessGroup>* property, FKAccessGroup* group){
    FKAccessGroup* object = qobject_cast<FKAccessGroup*>(property->object);
    if(object){
        object->addAccessGroup(group);
    }else{
        FK_MLOG("Unable add access group qml property: no object")
        return nullptr;
    }
}

void FKAccessGroup::resetAccessGroups(QQmlListProperty<FKAccessGroup>* property){
    FKAccessGroup* object = qobject_cast<FKAccessGroup*>(property->object);
    if(object){
        object->resetAccessGroups();
    }else{
        FK_MLOG("Unable reset access group qml property: no object")
        return nullptr;
    }
}

FKAccessGroup* FKAccessGroup::getAccessGroup(const int index) const{
    return _accessGroups.at(index);
}

int FKAccessGroup::countAccessGroups() const{
    return _accessGroups.size();
}

void FKAccessGroup::addAccessGroup(FKAccessGroup* group){
    _accessGroups.append(group);
    group->addDependentGroup(this);
    invalidateCache();
}

void FKAccessGroup::resetAccessGroups(){
    for(auto group:_accessGroups){
        group->removeDependentGroup(this);
    }
    _accessGroups.clear();
    invalidateCache();
}

void FKAccessGroup::invalidateCache() const{
    if(_totalAccessCache.isValid){
        _totalAccessCache.isValid = false;
        for(auto group:_dependentAccessCache.value){
            group->invalidateCache();
        }
    }
}
