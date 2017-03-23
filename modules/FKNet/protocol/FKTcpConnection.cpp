#include "FKTcpConnection.h"

#include "FKLogger.h"

FKTcpConnection::FKTcpConnection(QObject* parent):FKConnection(parent){
    FK_CONSTRUCTOR
}

FKTcpConnection::~FKTcpConnection(){
    FK_DESTRUCTOR
}
