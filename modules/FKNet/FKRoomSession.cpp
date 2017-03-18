#include "FKRoomSession.h"

#include <QQmlComponent>
#include <QQmlEngine>

#include "FKRoomObject.h"

#include "FKLogger.h"

FKRoomSession::FKRoomSession(QObject *parent) : QObject(parent){
    FK_CONSTRUCTOR
}

FKRoomSession::~FKRoomSession(){
    FK_DESTRUCTOR
    unloadAvaliableComponents();
}

qint32 FKRoomSession::sessionId() const{
    return _sessionId;
}

QStringList FKRoomSession::avaliableComponents() const{
    return _avaliableComponents;
}

bool FKRoomSession::avaliableComponentsLoaded() const{
    return _avaliableComponentsLoaded;
}

void FKRoomSession::setAvaliableComponents(const QStringList componentNames){
    if(componentNames != _avaliableComponents){
        _avaliableComponents = componentNames;
        setAvaliableComponentsLoaded(false);
        emit avaliableComponentsChanged();
    }
}

void FKRoomSession::processReplicateEvent(qint32 object, qint32 componentIndex){
    todo;
}

void FKRoomSession::processDeleteEvent(qint32 object){
    todo;
}

void FKRoomSession::processPropertyEvent(qint32 object, qint32 subject, QVariant value){
    todo;
}

void FKRoomSession::processCallableEvent(qint32 object, qint32 subject, QVariant value){
    todo;
}

void FKRoomSession::requestActionEvent(qint32 object, qint32 subject, QVariant value){
    todo;
}

void FKRoomSession::requestSessionReplication(qint32 target){
    QList<qint32> targets;
    targets.append(target);
    for(auto obj: _roomObjects){
        obj->replicate(targets);
    }
    for(auto obj: _roomObjects){
        obj->updateProperties(targets);
    }
}

void FKRoomSession::requestReplicateEvent(qint32 object, qint32 componentIndex, QList<qint32> targets){
    filterTargets(targets);
    if(!targets.isEmpty()){
        emit replicationEvent(object,componentIndex,targets);
    }else{
        FK_MLOGV("Replicate event skipped due empty target list", object)
    }
}

void FKRoomSession::requestDeleteEvent(qint32 object, QList<qint32> targets){
    filterTargets(targets);
    if(!targets.isEmpty()){
        emit deletionEvent(object,targets);
    }else{
        FK_MLOGV("Delete event skipped due empty target list", object)
    }
}

void FKRoomSession::requestPropertyEvent(qint32 object, qint32 subject, QVariant value, QList<qint32> targets){
    filterTargets(targets);
    if(!targets.isEmpty()){
        emit propertyEvent(object,subject,value,targets);
    }else{
        FK_MLOGV("Property event skipped due empty target list", object)
    }
}

void FKRoomSession::requestCallableEvent(qint32 object, qint32 subject, QVariant value, QList<qint32> targets){
    filterTargets(targets);
    if(!targets.isEmpty()){
        emit callableEvent(object,subject,value,targets);
    }else{
        FK_MLOGV("Callable event skipped due empty target list", object)
    }
}

void FKRoomSession::processActionEvent(qint32 object, qint32 subject, QVariant value, qint32 requester){
    emit actionEvent(object,subject,value,requester);
}

void FKRoomSession::sessionGreeting(const qint32 session){
    todo;
}

void FKRoomSession::sessionLost(const qint32 session){
    todo;
}

void FKRoomSession::loadAvaliableComponents(){
    unloadAvaliableComponents();
    resetRoomSessionContext();
    QQmlEngine* engine = qmlEngine(this);
    for(auto componentName:_avaliableComponents){
        if(_componentObjects.contains(componentName)){
            FK_MLOGV("Dublicate component registration skipped",componentName)
            continue;
        }
        auto component = new QQmlComponent(engine, QString("qrc:/%1.qml").arg(componentName),QQmlComponent::Asynchronous);
        if (component->isLoading()){
            QObject::connect(component, SIGNAL(statusChanged(QQmlComponent::Status)), this, SLOT(onComponentObjectLoaded()));
        }
        _componentObjects.insert(componentName,component);
    }
    onComponentObjectLoaded();
}

void FKRoomSession::unloadAvaliableComponents(){
    for(auto i:_componentObjects){
        i->deleteLater();
    }
    _componentObjects.clear();
    setAvaliableComponentsLoaded(false);
}

QObject* FKRoomSession::createRoomObject(const QString componentName){
    FKRoomObject* object = instantiateRoomObject(componentName,_nextObjectIndex++);
    if(object){
        object->replicate(object->watchers());
    }
    return object;
}

QObject* FKRoomSession::createRoomObject(const qint32 componentIndex, const qint32 objectIndex){
     FKRoomObject* object = instantiateRoomObject(_avaliableComponents.at(componentIndex), objectIndex);
     return object;
}

void FKRoomSession::deleteRoomObject(const qint32 id){
    auto obj = _roomObjects.value(id, nullptr);
    if(obj){
        requestDeleteEvent(id, obj->watchers());
        obj->deleteLater();
    }
}

void FKRoomSession::discardRoomObject(const qint32 id){
    auto obj = _roomObjects.take(id);
    obj->deleteLater();
}

void FKRoomSession::filterTargets(QList<qint32>& targets){
    QMutableListIterator i(targets);
    while(i.hasNext()){
        i.next();
        if(!_roomSessions.value(i.value(),false)){
            i.remove();
        }
    }
}

FKRoomObject* FKRoomSession::instantiateRoomObject(const QString componentName, const qint32 objectIndex){
    if(!_avaliableComponentsLoaded){
        FK_MLOGV("Unable create object, room session components are not loaded",componentName)
        return nullptr;
    }
    auto componentIndex = _componentObjects.constFind(componentName);
    if(componentIndex != _componentObjects.constEnd()){
        auto component = componentIndex.value();
        QObject* obj = component->create(_qmlContext);
        FKRoomObject* roomObject = qobject_cast<FKRoomObject*>(obj);
        if(roomObject){
            QQmlEngine::setObjectOwnership(roomObject,QQmlEngine::CppOwnership);
            roomObject->setParent(this);
            roomObject->setComponentIndex(std::distance(_componentObjects.constBegin(), componentIndex));
            _roomObjects.insert(objectIndex,roomObject);
            roomObject->setSession(this,objectIndex);
            return roomObject;
        }else{
            //we get this case if component->create() or object cast fail
            obj->deleteLater();
            FK_MLOGV("Unable create room object for component",componentName)
            return nullptr;
        }
    }else{
        FK_MLOGV("Unable create object, no room session component found",componentName)
        return nullptr;
    }
}

void FKRoomSession::onComponentObjectLoaded(){
    for(auto i:_componentObjects){
        if(i->isLoading()){
            return;
        }
    }
    for(auto i:_componentObjects){
        if(i->isError()){
            FK_MLOGV("Room components loaded with errors",i->errors())
        }
    }
    setAvaliableComponentsLoaded(true);
}

void FKRoomSession::setAvaliableComponentsLoaded(const bool loaded){
    if(_avaliableComponentsLoaded != loaded){
        _avaliableComponentsLoaded = loaded;
        emit avaliableComponentsLoadedChanged();
    }
}

void FKRoomSession::resetRoomSessionContext(){
    _qmlContext = qmlContext(this);
    _nextObjectIndex = 0;
}

void FKRoomSession::deleteAllRoomObjects(){
    for(auto i:_roomObjects.keys()){
        deleteRoomObject(i);
    }
}

