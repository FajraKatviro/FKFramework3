#ifndef FKROOMPROPERTY_H
#define FKROOMPROPERTY_H

#include "FKRoomObjectComponent.h"

class FKRoomProperty : public FKRoomObjectComponent{
    Q_OBJECT
public:
    explicit FKRoomProperty(QObject* parent = nullptr);
    ~FKRoomProperty();
};

#endif // FKROOMPROPERTY_H
