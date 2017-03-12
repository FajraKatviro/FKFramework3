TEMPLATE = lib
TARGET = FKNet
QT += qml quick
CONFIG += plugin c++11

TARGET = $$qtLibraryTarget($$TARGET)
uri = FKFramework.Net

# Input
SOURCES += \
    FKNet_plugin.cpp \
    FKMessageGate.cpp \
    FKMessageChannel.cpp \
    FKMessageHandler.cpp \
    FKRoomSession.cpp

HEADERS += \
    FKNet_plugin.h \
    FKMessageGate.h \
    FKMessageChannel.h \
    FKMessageHandler.h \
    FKRoomSession.h

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
