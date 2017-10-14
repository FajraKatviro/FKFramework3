#ifndef FK_PROJECT_HELPER
#define FK_PROJECT_HELPER

#include <QCoreApplication>

namespace FKUtility{

        //Use this function to import application properties from project file to application object
        void replicateApplicationInfoFromProject(){
                QCoreApplication::setApplicationName(APP_NAME);
                QCoreApplication::setApplicationVersion(APP_VERSION);
                QCoreApplication::setOrganizationName(APP_MAINTAINER);
        }

}

#endif
