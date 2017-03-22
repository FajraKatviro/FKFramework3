#ifndef FKNETSERVICE_H
#define FKNETSERVICE_H

#include <QObject>

class FKNetService : public QObject{
    Q_OBJECT
public:
    explicit FKNetService(QObject* parent = 0);
    ~FKNetService();

};

#endif // FKNETSERVICE_H
