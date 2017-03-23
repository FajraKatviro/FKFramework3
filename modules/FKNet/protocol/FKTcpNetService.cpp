#include "FKTcpNetService.h"

#include "FKLogger.h"

FKTcpNetService::FKTcpNetService(QObject* parent):FKNetService(parent){
    FK_CONSTRUCTOR
}

FKTcpNetService::~FKTcpNetService(){
    FK_DESTRUCTOR
}
