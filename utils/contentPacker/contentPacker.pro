
TEMPLATE = aux

include(../../paths/fkframeworkpath.pri)

utils.files = fkimageset.pri fkcontent.pri
utils.path = $$FK_UTILS_FOLDER/contentPacker

INSTALLS += utils

deploy.depends = install
QMAKE_EXTRA_TARGETS += deploy
