#include "FKNet_plugin.h"

#include <QList>
#include <QMetaType>

#include "FKMessageGate.h"
#include "FKMessageChannel.h"
#include "FKMessageHandler.h"

#include <qqml.h>

void FKNetPlugin::registerTypes(const char *uri)
{
    qRegisterMetaType<QList<qint32>>();
    // @uri FKFramework.Net
    qmlRegisterType<FKMessageGate>(uri, 1, 0, "FKMessageGate");
    qmlRegisterType<FKMessageChannel>(uri, 1, 0, "FKMessageChannel");
    qmlRegisterType<FKMessageHandler>(uri, 1, 0, "FKMessageHandler");
}

