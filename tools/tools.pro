TEMPLATE = subdirs

SUBDIRS += \
    imageManager \
    \ #PackageGenerator \
    \ #PackageManager \
    \ #DeployQML \
    \ #DeployDesktop \
    \ #DeployMobile \
    imagesetBuilder \
    helpers

deploy.CONFIG = recursive
QMAKE_EXTRA_TARGETS += deploy

