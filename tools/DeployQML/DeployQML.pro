QT += core
QT -= gui

CONFIG += c++11

TARGET = DeployQML
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

DESTDIR = $$PWD/../../bin

include(../deployment.pri)