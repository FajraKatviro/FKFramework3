#include "FKNet_plugin.h"

#include <QList>
#include <QMetaType>

#include "FKMessageChannel.h"
#include "FKMessageHandler.h"
#include "FKMessageRedirect.h"
#include "FKMessageGate.h"
#include "FKRoomSession.h"

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
}

