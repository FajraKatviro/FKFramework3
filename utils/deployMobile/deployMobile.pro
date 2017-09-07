
TEMPLATE = aux

include(../../paths/fkframeworkpath.pri)

mobileHelpers.files = Info.plist \
                android_splashScreen \
                ios_splashScreen

mobileHelpers.path = $$FK_UTILS_FOLDER/deployMobile

utils.files = fkdeploy_mobile.pri
utils.path = $$FK_UTILS_FOLDER/deployMobile

INSTALLS += mobileHelpers utils

deploy.depends = install
QMAKE_EXTRA_TARGETS += deploy
