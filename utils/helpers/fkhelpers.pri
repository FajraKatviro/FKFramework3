
INCLUDEPATH += $$PWD

isEmpty(ICON){
        warning("ICON variable is not set, icon for unix platforms will be missing")
}
isEmpty(RC_ICONS){
        warning("RC_ICONS variable is not set, icon for windows platforms will be missing")
}
isEmpty(VERSION){
        warning("VERSION varibale is not set, application version information will be unavailable")
}
isEmpty(QMAKE_TARGET_COMPANY){
        warning("QMAKE_TARGET_COMPANY varibale is not set, maintainer information will be unavailable")
}
isEmpty(QMAKE_TARGET_PRODUCT){
        warning("QMAKE_TARGET_PRODUCT varibale is not set, application name information will be unavailable")
}

DEFINES += \
APP_VERSION=\"\\\"$$VERSION\\\"\" \
APP_MAINTAINER=\"\\\"$$QMAKE_TARGET_COMPANY\\\"\" \
APP_NAME=\"\\\"$$QMAKE_TARGET_PRODUCT\\\"\"
