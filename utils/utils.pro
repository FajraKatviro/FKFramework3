TEMPLATE = subdirs

SUBDIRS += \
    \ #ImageManager \
    \ #PackageGenerator \
    \ #PackageManager \
    \ #DeployQML \
    \ #DeployDesktop \
    \ #DeployMobile \
    \ #contentPacker \
    helpers

deploy.CONFIG = recursive
QMAKE_EXTRA_TARGETS += deploy

OTHER_FILES = README.md
