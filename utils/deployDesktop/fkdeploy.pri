
isEmpty(DESTDIR){
        error("DESTDIR variable not set, deploy tool would fail")
}
isEmpty(DEPLOY_BUILD_FOLDER){
        error("DEPLOY_BUILD_FOLDER variable not set, deploy tool would fail")
}
isEmpty(LICENSE){
        win32:error("LICENSE variable not set, deploy for windows would fail")
        else:warning("LICENSE variable not set, deploy for windows would fail")
}
isEmpty(UPGRADE_CODE){
        win32:error("UPGRADE_CODE variable not set, deploy for windows would fail")
        else:warning("UPGRADE_CODE variable not set, deploy for windows would fail")
}
isEmpty(SHORT_DESCRIPTION){
        unix:!android:!mac:error("SHORT_DESCRIPTION variable not set, deploy for linux would fail")
        else:warning("SHORT_DESCRIPTION variable not set, deploy for linux would fail")
}
isEmpty(LONG_DESCRIPTION){
        unix:!android:!mac:error("LONG_DESCRIPTION variable not set, deploy for linux would fail")
        else:warning("LONG_DESCRIPTION variable not set, deploy for linux would fail")
}
isEmpty(LONG_DESCRIPTION){
        unix:!android:!mac:error("LONG_DESCRIPTION variable not set, deploy for linux would fail")
        else:warning("LONG_DESCRIPTION variable not set, deploy for linux would fail")
}
isEmpty(QMAKE_TARGET_PRODUCT){
        unix:!android:!mac:error("QMAKE_TARGET_PRODUCT variable not set, deploy for linux would fail")
}
isEmpty(QMAKE_TARGET_COMPANY){
        unix:!android:!mac:error("QMAKE_TARGET_PRODUCT variable not set, deploy for linux would fail")
}
isEmpty(VERSION){
        unix:!android:!mac:error("VERSION variable not set, deploy for linux would fail")
}

win32{
    INSTALL_ICON = $$RC_ICONS
}else{
    INSTALL_ICON = $$ICON
}

!exists($$DEPLOY_BUILD_FOLDER){
    mkpath($$DEPLOY_BUILD_FOLDER)
}

!mac:!android{ # win/linux
    ATTRIBUTELIST =
    ATTRIBUTELIST += NAME=$$QMAKE_TARGET_PRODUCT
    ATTRIBUTELIST += FOLDER=$$DESTDIR
    ATTRIBUTELIST += VERSION=$$VERSION
    ATTRIBUTELIST += INSTALL_ICON=$$INSTALL_ICON
    ATTRIBUTELIST += COMPANY=$$QMAKE_TARGET_COMPANY
    ATTRIBUTELIST += LICENSE=$$LICENSE
    ATTRIBUTELIST += UPGRADE_CODE=$$UPGRADE_CODE
    ATTRIBUTELIST += TARGET=$$TARGET
    ATTRIBUTELIST += SHORT_DESCRIPTION=$$SHORT_DESCRIPTION
    ATTRIBUTELIST += LONG_DESCRIPTION=$$LONG_DESCRIPTION
    DEPLOY_BUILD_CONFIG_FILE = $$DEPLOY_BUILD_FOLDER/buildConfig.txt
    write_file($$DEPLOY_BUILD_CONFIG_FILE,ATTRIBUTELIST)
}

win32{
    deploy.commands = windeployqt --no-translations --qmldir "$$_PRO_FILE_PWD_" "$$DESTDIR" $$escape_expand(\n\t) \
        "$$PWD/winDeploy.bat" "$$system_path($$DEPLOY_BUILD_CONFIG_FILE)" "$$system_path($$DEPLOY_BUILD_FOLDER)"
}else:mac{
    !ios{
        deploy.commands = macdeployqt "$$DESTDIR/$${TARGET}.app" -dmg -always-overwrite -appstore-compliant -qmldir="$$_PRO_FILE_PWD_" $$escape_expand(\n\t) \
            mv "$$DESTDIR/$${TARGET}.dmg" "$$DEPLOY_BUILD_FOLDER/$${QMAKE_TARGET_PRODUCT}.dmg"
    }else{
        deploy.commands = echo Target not supported by FKDeploy tool. Please, use iosdeployqt instead
    }
}else:!android{
    deploy.commands = "$$PWD/nixdeployqt.sh" "$${TARGET}" "$$DESTDIR" "$$PWD/../" "$$_PRO_FILE_PWD_" $$escape_expand(\n\t) \
        "$$PWD/nixDeploy.sh" "$$DEPLOY_BUILD_CONFIG_FILE" "$$DEPLOY_BUILD_FOLDER"
}else{
    deploy.commands = echo Target not supported by FKDeploy tool. Please, use androiddeployqt instead
}




