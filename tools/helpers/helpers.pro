
TEMPLATE = aux

include(../../paths/fkframeworkpath.pri)

headers.files = commonPaths.h \
                loadImageset.h \
                projectHelper.h \
                resourceLocation.h \
                selectBestSizeset.h \
                sizeString.h

headers.path = $$FK_TOOLS_FOLDER/helpers

utils.files = fkhelpers.pri
utils.path = $$FK_TOOLS_FOLDER/helpers

!isEmpty(FK_UTILS_FOLDER){
    INSTALLS += headers utils
}

QMAKE_EXTRA_TARGETS += deploy
