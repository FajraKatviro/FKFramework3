
include(fktoolsfolder.pri)

isEmpty(ART_FOLDER){
    error("ART_FOLDER is not set")
}
isEmpty(ART_BUILD_FOLDER){
    error("ART_BUILD_FOLDER is not set")
}

ART_DEPLOY_FOLDER = "$$DESTDIR/constAppData"

mac{
    !isEmpty(QMAKE_POST_LINK): QMAKE_POST_LINK += ";"
    ios{
        QMAKE_POST_LINK += \
            $$quote(mkdir -p \"$CODESIGNING_FOLDER_PATH/constAppData\") $$escape_expand(\n\t) \
            $$quote(cp -r \"$$ART_BUILD_FOLDER/bin/\"* \"$CODESIGNING_FOLDER_PATH/constAppData\")
    }else{
        QMAKE_POST_LINK += \
            $$quote(mkdir -p \"$$DESTDIR/$${TARGET}.app/Contents/Resources/constAppData\") $$escape_expand(\n\t) \
            $$quote(cp -r "$$ART_BUILD_FOLDER/bin/*" \"$$DESTDIR/$${TARGET}.app/Contents/Resources/constAppData\")
    }
}

android{
    ANDROID_EXTRA_PLUGINS += $$files($$ART_DEPLOY_FOLDER)
}

imagesets.commands =   "$$system_path($$FK_TOOLS_FOLDER/PackageManager)" "$$ART_FOLDER" --dir $$escape_expand(\n\t) \
                       "$$system_path($$FK_TOOLS_FOLDER/PackageGenerator)"  "$$ART_FOLDER" "$$ART_BUILD_FOLDER" "$$ART_DEPLOY_FOLDER" --clean --add --qrc --rcc --dir $$escape_expand(\n\t)

first.depends += qmake

QMAKE_EXTRA_TARGETS += first imagesets
