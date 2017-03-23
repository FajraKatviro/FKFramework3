#include "Protocol_plugin.h"

#include "FKTcpNetService.h"

#include <qqml.h>

void ProtocolPlugin::registerTypes(const char *uri)
{
    // @uri FKFramework.Net.Protocols
    qmlRegisterType<FKTcpNetService>(uri, 1, 0, "FKTcpNetService");
}

