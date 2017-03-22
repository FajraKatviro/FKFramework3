#ifndef FKMESSAGEREDIRECT_H
#define FKMESSAGEREDIRECT_H

#include "FKMessageHandler.h"

class FKMessageRedirect : public FKMessageHandler{
    Q_OBJECT
    Q_PROPERTY(FKMessageChannel* targetChannel READ targetChannel WRITE setTargetChannel NOTIFY targetChannelChanged)
public:
    explicit FKMessageRedirect(QObject* parent = nullptr);
    ~FKMessageRedirect();

    FKMessageChannel* targetChannel()const;
    void setTargetChannel(FKMessageChannel* arg);

    virtual void processMessage(QJsonObject message, const qint32 messageType)override;

signals:
    void targetChannelChanged();

private:
    FKMessageChannel* _targetChannel = nullptr;
};

#endif // FKMESSAGEREDIRECT_H
