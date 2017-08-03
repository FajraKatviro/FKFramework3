
TEMPLATE = aux

include(../paths/fkframeworkpath.pri)

fkfeatures.files = fkfeatures.pri

fkfeatures.path = $$FK_FRAMEWORK_PATH

INSTALLS += fkfeatures

QMAKE_EXTRA_TARGETS += deploy

OTHER_FILES = README.md
