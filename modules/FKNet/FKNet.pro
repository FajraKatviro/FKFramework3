TEMPLATE = lib
TARGET = FKNet
QT += qml quick
CONFIG += plugin c++11

TARGET = $$qtLibraryTarget($$TARGET)
uri = FKFramework.Net

DEFINES += FK_DEBUG

# Input
SOURCES += \
    FKNet_plugin.cpp \
    channel/FKMessageChannel.cpp \
    channel/FKMessageHandler.cpp \
    channel/FKMessageRedirect.cpp \
    channel/FKMessageGate.cpp \
    room/FKRoomSession.cpp \
    room/FKRoomObject.cpp \
    room/FKAccessGroup.cpp \
    room/FKRoomObjectComponent.cpp \
    room/FKRoomEvent.cpp \
    room/FKRoomAction.cpp \
    room/FKRoomProperty.cpp

HEADERS += \
    FKNet_plugin.h \
    channel/FKMessageChannel.h \
    channel/FKMessageHandler.h \
    channel/FKMessageRedirect.h \
    channel/FKMessageGate.h \
    room/FKRoomSession.h \
    room/FKRoomObject.h \
    room/FKAccessGroup.h \
    room/FKRoomObjectComponent.h \
    room/FKRoomEvent.h \
    room/FKRoomAction.h \
    room/FKRoomProperty.h

INCLUDEPATH += ../../utils/headers

DISTFILES = qmldir

#!equals(_PRO_FILE_PWD_, $$OUT_PWD) {
#    copy_qmldir.target = $$OUT_PWD/qmldir
#    copy_qmldir.depends = $$_PRO_FILE_PWD_/qmldir
#    copy_qmldir.commands = $(COPY_FILE) \"$$replace(copy_qmldir.depends, /, $$QMAKE_DIR_SEP)\" \"$$replace(copy_qmldir.target, /, $$QMAKE_DIR_SEP)\"
#    QMAKE_EXTRA_TARGETS += copy_qmldir
#    PRE_TARGETDEPS += $$copy_qmldir.target
#}

qmldir.files = qmldir
#unix {
    installPath = $$[QT_INSTALL_QML]/$$replace(uri, \\., /)
    qmldir.path = $$installPath
    target.path = $$installPath
    INSTALLS += target qmldir
#}

RESOURCES += \
    qml.qrc
