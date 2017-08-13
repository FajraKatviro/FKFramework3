
TEMPLATE = aux

include(../../paths/fkframeworkpath.pri)

mobileHelpers.files = Info.plist \
		android_splashScreen/drawable-hdpi/logo.png \
		android_splashScreen/drawable-xhdpi/logo.png \
		android_splashScreen/drawable-xxhdpi/logo.png \
		ios_splashScreen/LaunchImage-iOS7@2x.png \
		ios_splashScreen/LaunchImage-iOS7-568h@2x.png \
		ios_splashScreen/LaunchImage-iOS7-Landscape.png \
		ios_splashScreen/LaunchImage-iOS7-Landscape@2x.png \
		ios_splashScreen/LaunchImage-iOS7-Portrait.png \
		ios_splashScreen/LaunchImage-iOS7-Portrait@2x.png \

mobileHelpers.path = $$FK_UTILS_FOLDER/deployMobile

utils.files = fkdeploy_mobile.pri
utils.path = $$FK_UTILS_FOLDER/deployMobile

INSTALLS += mobileHelpers utils

deploy.depends = install
QMAKE_EXTRA_TARGETS += deploy
