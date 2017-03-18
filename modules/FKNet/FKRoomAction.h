#ifndef FKROOMACTION_H
#define FKROOMACTION_H

#include "FKRoomObjectComponent.h"

class FKRoomAction : public FKRoomObjectComponent{
    Q_OBJECT
public:
    explicit FKRoomAction(QObject* parent = nullptr);
    ~FKRoomAction();
};

#endif // FKROOMACTION_H
