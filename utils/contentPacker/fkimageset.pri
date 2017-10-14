
isEmpty(ART_FOLDER){
    error("ART_FOLDER is not set")
}
isEmpty(ART_BUILD_FOLDER){
    error("ART_BUILD_FOLDER is not set")
}

ART_DEPLOY_FOLDER = "$$FK_CONST_APP_DATA_DESTINATION"

mac{
    !isEmpty(QMAKE_POST_LINK): QMAKE_POST_LINK += ";"
    QMAKE_POST_LINK += \
        $$quote(mkdir -p \"$$FK_CONST_APP_DATA_DESTINATION\") $$escape_expand(\n\t) \
        $$quote(cp -r \"$$ART_BUILD_FOLDER/bin/\"* \"$$FK_CONST_APP_DATA_DESTINATION\")
}

android{
    ANDROID_EXTRA_PLUGINS += $$files($$ART_DEPLOY_FOLDER)
}

imagesets.commands =   "$$system_path($$FK_UTILS_FOLDER/PackageManager)" "$$ART_FOLDER" --dir $$escape_expand(\n\t) \
                       "$$system_path($$FK_UTILS_FOLDER/PackageGenerator)"  "$$ART_FOLDER" "$$ART_BUILD_FOLDER" "$$ART_DEPLOY_FOLDER" --clean --add --qrc --rcc --dir --qtbin "$$[QT_INSTALL_BINS]" $$escape_expand(\n\t)
