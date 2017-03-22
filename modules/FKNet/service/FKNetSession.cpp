#include "FKNetSession.h"

#include "FKLogger.h"

FKNetSession::FKNetSession(QObject* parent) : QObject(parent){
    FK_CONSTRUCTOR
}

FKNetSession::~FKNetSession(){
    FK_DESTRUCTOR
}
