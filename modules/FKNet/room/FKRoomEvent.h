#ifndef FKROOMEVENT_H
#define FKROOMEVENT_H

#include "FKRoomObjectComponent.h"

class FKRoomEvent : public FKRoomObjectComponent{
    Q_OBJECT
public:
    explicit FKRoomEvent(QObject* parent = nullptr);
    ~FKRoomEvent();
};

#endif // FKROOMEVENT_H
