TEMPLATE = subdirs

SUBDIRS = \ #modules \
          tools \
          utils
          #samples_src

#samples_src.subdir = samples

OTHER_FILES = README.md \
              LICENSE \
              paths/README.md \
              paths/fkframeworkpath.pri \
              paths/fkframework.pri

deploy.CONFIG = recursive
QMAKE_EXTRA_TARGETS += deploy