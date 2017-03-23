#ifndef FKCONNECTION_H
#define FKCONNECTION_H

#include <QObject>

#include "FKNet_global.h"

class FK_NET_EXPORT FKConnection : public QObject{
    Q_OBJECT
public:
    explicit FKConnection(QObject* parent = 0);
    ~FKConnection();

};

#endif // FKCONNECTION_H
