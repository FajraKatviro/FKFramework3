
TEMPLATE = aux

include(../../paths/fkframeworkpath.pri)

utils.files = fkimageset.pri
utils.path = $$FK_TOOLS_FOLDER/imagesetBuilder

INSTALLS += utils

QMAKE_EXTRA_TARGETS += deploy