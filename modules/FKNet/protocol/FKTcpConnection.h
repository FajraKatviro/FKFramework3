#ifndef FKTCPCONNECTION_H
#define FKTCPCONNECTION_H

#include "FKConnection.h"

class FKTcpConnection : public FKConnection{
    Q_OBJECT
public:
    explicit FKTcpConnection(QObject* parent = nullptr);
    ~FKTcpConnection();
};

#endif // FKTCPCONNECTION_H
