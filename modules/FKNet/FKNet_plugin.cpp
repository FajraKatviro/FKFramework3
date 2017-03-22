#include "FKNet_plugin.h"

#include <QList>
#include <QMetaType>

#include "channel/FKMessageChannel.h"
#include "channel/FKMessageHandler.h"
#include "channel/FKMessageRedirect.h"
#include "channel/FKMessageGate.h"

#include "room/FKRoomSession.h"
#include "room/FKAccessGroup.h"
#include "room/FKRoomObject.h"
#include "room/FKRoomObjectComponent.h"
#include "room/FKRoomAction.h"
#include "room/FKRoomEvent.h"
#include "room/FKRoomProperty.h"

#include "service/FKNetSession.h"
#include "service/FKNetService.h"

#include <qqml.h>

void FKNetPlugin::registerTypes(const char *uri)
{
    qRegisterMetaType<QList<qint32>>();

    // @uri FKFramework.Net
    qmlRegisterType<FKMessageChannel>(uri, 1, 0, "FKMessageChannel");
    qmlRegisterType<FKMessageHandler>(uri, 1, 0, "FKMessageHandler");
    qmlRegisterType<FKMessageRedirect>(uri, 1, 0, "FKMessageRedirect");
    qmlRegisterType<FKMessageGate>(uri, 1, 0, "FKMessageGate");

    qmlRegisterType<FKRoomSession>(uri, 1, 0, "FKRoomSession");
    qmlRegisterType<FKAccessGroup>(uri, 1, 0, "FKAccessGroup");
    qmlRegisterType<FKRoomObject>(uri, 1, 0, "FKRoomObject");
    qmlRegisterType<FKRoomObjectComponent>(uri, 1, 0, "FKRoomObjectComponent");
    qmlRegisterType<FKRoomAction>(uri, 1, 0, "FKRoomAction");
    qmlRegisterType<FKRoomEvent>(uri, 1, 0, "FKRoomEvent");
    qmlRegisterType<FKRoomProperty>(uri, 1, 0, "FKRoomProperty");

    qmlRegisterType<FKNetSession>(uri, 1, 0, "FKNetSession");
    qmlRegisterType<FKNetService>(uri, 1, 0, "FKNetService");
}

