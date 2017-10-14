#ifndef COMMONPATH_H
#define COMMONPATH_H

#include <QString>
#include <QDir>
#include <QStandardPaths>

namespace FKUtility {

    //use this function to get 'bundled' resources location
    QDir dataDir(){
        QString path(QStandardPaths::locate(QStandardPaths::AppDataLocation, "constAppData", QStandardPaths::LocateDirectory));
        if(path.isEmpty()){
#ifdef Q_OS_ANDROID
            path="assets:/constAppData";
#else
            path="./constAppData";
#endif
        }
        return QDir(path);
    }

    //use this function to get downloaded resources location
    QDir dlcDir(){
        return QDir(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/dlc");
    }

    //use this function to get persistent data storage location
    QDir storageDir(){
        return QDir(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/storage");
    }
}

#endif // COMMONPATH_H
