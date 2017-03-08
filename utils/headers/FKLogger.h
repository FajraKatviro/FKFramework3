#pragma once

//avaliable compile flags:
// * FK_DEBUG - enable this logger
// * FK_NO_CONSTRUCTORS - switch off object counter
// * FK_SILENT_CONSTRUCTORS - switch off object counter output
// * FK_NO_TODO - switch off todo macro

//avalibale macros:
// * FK_CONSTRUCTOR / FK_DESTRUCTOR - macro for object counting for QObject-derived objects. Place this macro in the very begin of every constructor/destructor
// * FK_CONSTRUCTOR_END / FK_DESTRUCTOR_END - optional complimentary macro to log successful constructor/destructor execution. Place this macro in the very beginning of every constructor/destructor
// * FK_MLOGV - log message with value
// * FK_LOG - log message with empty value
// * todo - use this mark for incomplete code. It will be replaced by a warning. If FK_DEBUG is off, compilation will fail instead.


#ifdef FK_DEBUG

#include <QDebug>
#include <QObject>
#include <QMap>
#include <QString>
#include <QVariant>
#include <QMutex>
#include <QMutexLocker>

class FKLogger{
    FKLogger(){}
#ifndef FK_NO_CONSTRUCTORS
    QMap<QString,int> objects;
    QMutex mutex;
public:
    void printObjectCounts()const{
        QMutexLocker locker(mutex);
        Q_UNUSED(locker)
        for(auto i = objects.constBegin(); i != objects.constEnd(); ++i){
            qDebug()<<"Existing objects:";
            qDebug()<<i.key()<<" : "<<i.value();
        }
    }
    void changeObjectCount(const QString& message, const QString& name,const int i){
        QMutexLocker locker(mutex);
        Q_UNUSED(locker)
        Q_UNUSED(message)
        int& val = objects[name];
        val += i;
#ifndef FK_SILENT_CONSTRUCTORS
        writeLog(message+name,i);
#endif
    }
#endif
public:
    static FKLogger& instance(){
        static FKLogger _instance;
        return _instance;
    }
    void writeLog(const QString description,const QVariant value)const{
        qDebug()<<description<<":\t\t"<<value;
     }
    void writeLog(const char* fileName,const int line,const QString description,const QVariant value)const{
        qDebug()<<fileName<<" line "<<line<<". "<<description<<":\t\t"<<value;
     }
};

#ifndef FK_NO_CONSTRUCTORS

#define FK_CONSTRUCTOR FKLogger::instance().changeObjectCount("Enter constructor ",this->metaObject()->className(),+1);
#define FK_DESTRUCTOR FKLogger::instance().changeObjectCount("Enter destructor ",this->metaObject()->className(),-1);
#ifndef FK_SILENT_CONSTRUCTORS
#define FK_CONSTRUCTOR_END FKLogger::instance().writeLog(QString("Exit constructor"), QVariant());
#define FK_DESTRUCTOR_END FKLogger::instance().writeLog(QString("Exit destructor"), QVariant());
#else
#define FK_CONSTRUCTOR_END
#define FK_DESTRUCTOR_END
#endif

#else

#define FK_CONSTRUCTOR
#define FK_DESTRUCTOR
#define FK_CONSTRUCTOR_END
#define FK_DESTRUCTOR_END

#endif

#define FK_MLOGV(description, value) FKLogger::writeLog(__FILE__,__LINE__,QString(description), value);
#define FK_MLOG(description) FKLogger::writeLog(__FILE__,__LINE__,QString(description), QVariant());

#ifndef FK_NO_TODO
#define todo qDebug("Incomplete code reached: %d line, %s",__LINE__,__FILE__)
#endif

#else //no FK_DEBUG

#define FK_CONSTRUCTOR
#define FK_DESTRUCTOR
#define FK_CONSTRUCTOR_END
#define FK_DESTRUCTOR_END
#define FK_MLOGV(description, value)
#define FK_MLOG(description)

#endif

