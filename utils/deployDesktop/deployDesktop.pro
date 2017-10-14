
TEMPLATE = aux

include(../../paths/fkframeworkpath.pri)

scriptFiles.files = buildConfig.txt \
                Install.wxs \
                nixDeploy.sh \
                nixdeployqt.sh \
                nixRun.sh \
		target.desktop \
		winDeploy.bat \
                DEBIAN

scriptFiles.path = $$FK_UTILS_FOLDER/deployDesktop

utils.files = fkdeploy.pri
utils.path = $$FK_UTILS_FOLDER/deployDesktop

INSTALLS += scriptFiles utils

unix:!android {
    deploy.commands = chmod +x "$${scriptFiles.path}/nixDeploy.sh"; chmod +x "$${scriptFiles.path}/nixdeployqt.sh"
}
deploy.depends = install
QMAKE_EXTRA_TARGETS += deploy
