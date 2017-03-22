#include "FKNetService.h"

#include "FKLogger.h"

FKNetService::FKNetService(QObject* parent) : QObject(parent){
    FK_CONSTRUCTOR
}

FKNetService::~FKNetService(){
    FK_DESTRUCTOR
}
