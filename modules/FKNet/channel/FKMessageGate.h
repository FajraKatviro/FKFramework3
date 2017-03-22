#ifndef FKMESSAGEGATE_H
#define FKMESSAGEGATE_H

#include "FKMessageHandler.h"

class FKMessageGate : public FKMessageHandler{
    Q_OBJECT
    Q_PROPERTY(GateMode mode READ mode WRITE setMode NOTIFY modeChanged)
    Q_PROPERTY(QObject* target READ target WRITE setTarget NOTIFY targetChanged)
public:
    FKMessageGate(QObject* parent = nullptr);
    ~FKMessageGate();

    enum GateMode{
        ListenToChannel,
        ListenToTarget
    };
    Q_ENUM(GateMode)

    virtual void processMessage(const QJsonObject message, const qint32 messageType)final;

    GateMode mode()const;
    QObject* target()const;

    void setMode(GateMode mode);
    void setTarget(QObject* target);

signals:
    void modeChanged();
    void targetChanged();

private:
    virtual void processMessage(QJsonObject message);
    virtual void connectTarget(QObject* target);
    virtual void disconnectTarget(QObject* target);

    GateMode _mode = ListenToChannel;
    QObject* _target = nullptr;
};

#endif // FKMESSAGEGATE_H
