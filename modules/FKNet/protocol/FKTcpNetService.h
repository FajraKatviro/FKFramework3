#ifndef FKTCPNETSERVICE_H
#define FKTCPNETSERVICE_H

#include "FKNetService.h"

class FKTcpNetService : public FKNetService{
    Q_OBJECT
public:
    explicit FKTcpNetService(QObject* parent = nullptr);
    ~FKTcpNetService();
};

#endif // FKTCPNETSERVICE_H
