#include "FKConnection.h"

#include "FKLogger.h"

FKConnection::FKConnection(QObject* parent) : QObject(parent){
    FK_CONSTRUCTOR
}

FKConnection::~FKConnection(){
    FK_DESTRUCTOR
}
