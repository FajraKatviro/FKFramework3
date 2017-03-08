#pragma once

#include <QObject>

class FKGate : public QObject{
    Q_OBJECT
public:
    FKGate(QObject *parent = 0);
    ~FKGate();
};
