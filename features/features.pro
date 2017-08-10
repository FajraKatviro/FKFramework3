
TEMPLATE = aux

include(../paths/fkframeworkpath.pri)

fkfeatures.files = fkfeatures.pri

fkfeatures.path = $$FK_FRAMEWORK_PATH

INSTALLS += fkfeatures

deploy.depends = install
QMAKE_EXTRA_TARGETS += deploy

OTHER_FILES = README.md
