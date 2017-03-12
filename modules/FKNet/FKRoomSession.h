#pragma once

#include <QObject>
#include <QVariant>
#include <QStringList>
#include <QMap>
#include <QHash>
#include <QList>
#include <QJsonObject>

class QQmlComponent;
class QQmlContext;

class FKRoomObject;

class FKRoomSession : public QObject{
    Q_OBJECT
    Q_PROPERTY(qint32 sessionId READ sessionId NOTIFY sessionIdChanged)
    Q_PROPERTY(QStringList avaliableComponents READ avaliableComponents WRITE setAvaliableComponents NOTIFY avaliableComponentsChanged)
    Q_PROPERTY(bool avaliableComponentsLoaded READ avaliableComponentsLoaded NOTIFY avaliableComponentsLoadedChanged)
public:
    explicit FKRoomSession(QObject *parent = 0);
    ~FKRoomSession();

    qint32 sessionId()const;
    QStringList avaliableComponents()const;
    bool avaliableComponentsLoaded()const;

    void setAvaliableComponents(const QStringList componentNames);

    void enableSession(const qint32 session);
    void disableSession(const qint32 session);

    //client-side
    //void processReplicateEvent(qint32 object, qint32 componentIndex);
    //void processDeleteEvent   (qint32 object);
    //void processPropertyEvent (qint32 object, qint32 subject, QVariant value);
    //void processCallableEvent (qint32 object, qint32 subject, QVariant value);
    //void requestActionEvent   (qint32 object, qint32 subject, QVariant value);

    //server-side
    void requestReplicateEvent(qint32 object, qint32 componentIndex,          QList<qint32> targets);
    void requestDeleteEvent   (qint32 object,                                 QList<qint32> targets);
    void requestPropertyEvent (qint32 object, qint32 subject, QVariant value, QList<qint32> targets);
    void requestCallableEvent (qint32 object, qint32 subject, QVariant value, QList<qint32> targets);
    void processActionEvent   (qint32 object, qint32 subject, QVariant value, qint32 requester);

public slots:
    void loadAvaliableComponents();
    void unloadAvaliableComponents();

    QObject* createRoomObject(const QString componentName);
    void deleteRoomObject(const qint32 id);

signals:
    void sessionIdChanged();
    void avaliableComponentsChanged();
    void avaliableComponentsLoadedChanged();

    void replicationEvent(qint32 object, qint32 componentIndex,          QList<qint32> targets);
    void deletionEvent   (qint32 object,                                 QList<qint32> targets);
    void propertyEvent   (qint32 object, qint32 subject, QVariant value, QList<qint32> targets);
    void callableEvent   (qint32 object, qint32 subject, QVariant value, QList<qint32> targets);
    void actionEvent     (qint32 object, qint32 subject, QVariant value, qint32 requester);

private slots:
    void onComponentObjectLoaded();

private:
    void setAvaliableComponentsLoaded(const bool loaded);
    void resetRoomSessionContext();
    void deleteAllRoomObjects();
    void requestSessionReplication(qint32 target);

    QObject* createRoomObject(const qint32 componentIndex, const qint32 objectIndex); //this overload used for client-side auto-replication only
    FKRoomObject* instantiateRoomObject(const QString componentName, const qint32 objectIndex);
    void discardRoomObject(const qint32 id);

    void filterTargets(QList<qint32>& targets);

    qint32 _sessionId = -1;
    bool _avaliableComponentsLoaded = false;
    QStringList _avaliableComponents;
    QMap<QString,QQmlComponent*> _componentObjects;
    QHash<qint32,FKRoomObject*> _roomObjects;
    QQmlContext* _qmlContext = nullptr;
    qint32 _nextObjectIndex = 0;

    QMap<qint32,bool> _roomSessions;
};

class FKRoomAccess;
class FKRoomObjectProperties;
class FKRoomObjectAction;
class FKRoomObjectEvent;
