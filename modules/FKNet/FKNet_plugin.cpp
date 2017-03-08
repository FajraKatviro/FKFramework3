#include "FKNet_plugin.h"
#include "FKGate.h"

#include <qqml.h>

void FKNetPlugin::registerTypes(const char *uri)
{
    // @uri FKFramework.Net
    qmlRegisterType<FKGate>(uri, 1, 0, "FKGate");
}

