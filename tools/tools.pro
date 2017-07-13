TEMPLATE = subdirs

SUBDIRS += \
    \ #ImageManager \
    \ #PackageGenerator \
    \ #PackageManager \
    \ #DeployQML \
    \ #DeployDesktop \
    \ #DeployMobile \
    \ #ImagesetBuilder \
    helpers

deploy.CONFIG = recursive
QMAKE_EXTRA_TARGETS += deploy

