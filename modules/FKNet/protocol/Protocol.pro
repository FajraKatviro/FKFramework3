TEMPLATE = lib
TARGET = Protocol
QT += qml quick network
CONFIG += plugin c++11

TARGET = $$qtLibraryTarget($$TARGET)
uri = FKFramework.Net.Protocols

# Input
SOURCES += \
    Protocol_plugin.cpp \
    FKTcpNetService.cpp \
    FKTcpConnection.cpp

HEADERS += \
    Protocol_plugin.h \
    FKTcpNetService.h \
    FKTcpConnection.h

DISTFILES = qmldir

INCLUDEPATH += \
    ../../../utils/headers \
    ../service \
    ../

LIBS += -L$$[QT_INSTALL_QML]/FKFramework/Net -lFKNet

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
