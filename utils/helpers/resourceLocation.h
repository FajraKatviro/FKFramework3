#ifndef RESOURCELOCATION_H
#define RESOURCELOCATION_H

#include <QString>
#include <QMap>
#include <QDir>
#include <QFileInfo>
#include <QResource>

#include "commonPaths.h"

namespace FKUtility {

    //use this class to load resources from package
    //each package can contain multiple resource (*.rcc) files
    //provide package name to constructor and then load resource from that package
    //do not use file extensions when load resources
    //package includes both 'bundled' and downloaded resources and select downloaded if both exist
    struct ResourceLocator{
        ResourceLocator(const QString& package=QString("universalResources")):_package(package){
            read(dataDir());
            read(dlcDir());
        }

        //target package name
        inline QString pacakge()const{
            return _package;
        }

        //founded resource files and their paths
        inline QMap<QString,QString> resourceFiles()const{
            return _resources;
        }


        enum Result{
            loadingSuccess,
            resourceNotFound,
            loadingFailed
        };

        //use this function to load resource from the package
        //use resource name (without extension)
        Result load(const QString& resource)const{
            auto i=_resources.constFind(resource + ".rcc");
            if(i==_resources.constEnd()){
                return resourceNotFound;
            }
            if(!QResource::registerResource(i.value())){
                return loadingFailed;
            }
            return loadingSuccess;
        }
    private:
        void read(QDir dir){
            if(!dir.cd(_package))
                return;
            QFileInfoList resourceFiles=dir.entryInfoList(QDir::Files);
            foreach(QFileInfo resourceFile,resourceFiles){
                _resources[resourceFile.fileName()]=resourceFile.canonicalFilePath();
            }
        }
        const QString _package;
        QMap<QString,QString> _resources;
    };
}

#endif // RESOURCELOCATION_H
