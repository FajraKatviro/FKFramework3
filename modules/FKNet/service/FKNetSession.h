#ifndef FKNETSESSION_H
#define FKNETSESSION_H

#include <QObject>

class FKNetSession : public QObject{
    Q_OBJECT
public:
    explicit FKNetSession(QObject* parent = 0);
    ~FKNetSession();

};

#endif // FKNETSESSION_H
