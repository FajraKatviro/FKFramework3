
include(../paths/fkframeworkpath.pri)

win32{
    deploy.commands = windeployqt --no-translations --qmldir "$$_PRO_FILE_PWD_" "$$FK_UTILS_FOLDER/$${TARGET}.exe"
}

QMAKE_EXTRA_TARGETS += deploy

unix:!android {
    runScript.path = "$$FK_UTILS_FOLDER"
    runScriptFile = $$runScript.path/$${TARGET}.sh
    runScript.extra = echo "./$${TARGET}" > $$runScriptFile; chmod +x $$runScriptFile
    INSTALLS += runScript
}

!ios:!android{
    target.path = "$$FK_UTILS_FOLDER"
    export(target.path)
    INSTALLS += target
    export(INSTALLS)
}


INCLUDEPATH += $$PWD/helpers
