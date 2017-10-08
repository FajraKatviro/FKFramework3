
FK_CONST_APP_DATA_DESTINATION = $$DESTDIR/constAppData

mac{
    ios{
        FK_CONST_APP_DATA_DESTINATION = $CODESIGNING_FOLDER_PATH/constAppData
    }else{
        FK_CONST_APP_DATA_DESTINATION = $$DESTDIR/$${TARGET}.app/Contents/Resources/constAppData
    }
}

contains(FK, mobile):include(utils/deployMobile/fkdeploy_mobile.pri)
contains(FK, deploy):include(utils/deployDesktop/fkdeploy.pri)
contains(FK, imageset):include(utils/contentPacker/fkimageset.pri)
contains(FK, content):include(utils/contentPacker/fkcontent.pri)
contains(FK, modules):include(utils/modules/fkmodules.pri)
contains(FK, helpers):include(utils/helpers/fkhelpers.pri)

fkpreprocess.depends = imagesets
fkpostprocess.depends = deploy

QMAKE_EXTRA_TARGETS += fkpreprocess fkpostprocess imagesets deploy
