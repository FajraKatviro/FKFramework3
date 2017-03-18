#ifndef FKROOMOBJECT_H
#define FKROOMOBJECT_H

#include "FKAccessGroup.h"

#include <QSet>

class FKRoomEvent;
class FKRoomAction;
class FKRoomProperty;

class FKRoomObject : public FKAccessGroup{
    Q_OBJECT
public:
    explicit FKRoomObject(QObject *parent = 0);
    ~FKRoomObject();

    void addRoomEvent(FKRoomEvent* ev);
    void addRoomAction(FKRoomAction* ac);
    void addRoomProperty(FKRoomProperty* prop);

    void removeRoomEvent(FKRoomEvent* ev);
    void removeRoomAction(FKRoomAction* ac);
    void removeRoomProperty(FKRoomProperty* prop);

    void replicate(const QSet<qint32>& watchers)const;

private:
    QList<FKRoomEvent*> _roomEvents;
    QList<FKRoomAction*> _roomActions;
    QList<FKRoomProperty*> _roomProperties;
};

#endif // FKROOMOBJECT_H
