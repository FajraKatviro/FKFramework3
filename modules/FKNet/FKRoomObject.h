#ifndef FKROOMOBJECT_H
#define FKROOMOBJECT_H

#include "FKAccessGroup.h"

#include <QSet>

class FKRoomSession;
class FKRoomEvent;
class FKRoomAction;
class FKRoomProperty;

class FKRoomObject : public FKAccessGroup{
    Q_OBJECT
public:
    explicit FKRoomObject(QObject *parent = 0);
    ~FKRoomObject();

    void discard();

    void addRoomEvent(FKRoomEvent* ev);
    void addRoomAction(FKRoomAction* ac);
    void addRoomProperty(FKRoomProperty* prop);

    void removeRoomEvent(FKRoomEvent* ev);
    void removeRoomAction(FKRoomAction* ac);
    void removeRoomProperty(FKRoomProperty* prop);

    virtual void replicate(const QSet<qint32>& watchers)const;
    void applyProperties(const QSet<qint32>& watchers)const;

    void setComponentIndex(const int index);
    void setSession(FKRoomSession* session, const qint32 id, const bool selfManaged = false);

private:
    QList<FKRoomEvent*> _roomEvents;
    QList<FKRoomAction*> _roomActions;
    QList<FKRoomProperty*> _roomProperties;
    FKRoomSession* _session;
    int _componentIndex = -1;
    qint32 _id = -1;
    bool _selfManaged = false;
};

#endif // FKROOMOBJECT_H
