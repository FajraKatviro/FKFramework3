
TEMPLATE = aux

include(../paths/fkframeworkpath.pri)

headers.files = commonPaths.h \
                loadImageset.h \
                projectHelper.h \
                resourceLocation.h \
                selectBestSizeset.h \
                sizeString.h

headers.path = $$FK_FRAMEWORK_PATH/helpers

!isEmpty(FK_FRAMEWORK_PATH){
    INSTALLS += headers
}

