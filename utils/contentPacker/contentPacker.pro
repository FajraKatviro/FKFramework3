
TEMPLATE = aux

include(../../paths/fkframeworkpath.pri)

utils.files = fkimageset.pri
utils.path = $$FK_UTILS_FOLDER/contentPacker

INSTALLS += utils

QMAKE_EXTRA_TARGETS += deploy
