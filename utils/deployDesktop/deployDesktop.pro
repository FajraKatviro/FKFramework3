
TEMPLATE = aux

include(../../paths/fkframeworkpath.pri)

scriptFiles.files = buildConfig.txt \
                Install.wxs \
                nixDeploy.sh \
                nixdepouqt.sh \
                nixRun.sh \
		target.desktop \
		winDeploy.bat \
		DEBIAN/control \
		DEBIAN/copyright \
		DEBIAN/rules

scriptFiles.path = $$FK_UTILS_FOLDER/deployDesktop

utils.files = fkdeploy.pri
utils.path = $$FK_UTILS_FOLDER/deployDesktop

INSTALLS += scriptFiles utils

deploy.depends = install
QMAKE_EXTRA_TARGETS += deploy
