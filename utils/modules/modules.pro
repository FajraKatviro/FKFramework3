
TEMPLATE = aux

include(../../paths/fkframeworkpath.pri)

utils.files = fkmodules.pri

utils.path = $$FK_UTILS_FOLDER

!isEmpty(FK_UTILS_FOLDER){
    INSTALLS += utils
}

