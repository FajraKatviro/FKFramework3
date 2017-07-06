
TEMPLATE = aux

include(../paths/fkframeworkpath.pri)

utils.files = fkdeploy.pri \
              fkdeploy_mobile.pri \
              fkhelpers.pri \
              fkimageset.pri \
              fkmodules.pri

utils.path = $$FK_UTILS_FOLDER

INSTALLS += utils
