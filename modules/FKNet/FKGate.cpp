#include "FKGate.h"

#include "FKLogger.h"

FKGate::FKGate(QObject* parent):QObject(parent){
    FK_CONSTRUCTOR
}

FKGate::~FKGate(){
    FK_DESTRUCTOR
}
