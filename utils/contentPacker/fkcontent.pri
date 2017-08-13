
large_resource_compiler.output   = "$$system_path($${DESTDIR}/constAppData/universalResources/${QMAKE_FILE_IN_BASE}.rcc)"
large_resource_compiler.commands = "$$system_path($$[QT_INSTALL_BINS]/rcc)" --binary --no-compress "${QMAKE_FILE_NAME}" -o "${QMAKE_FILE_OUT}"
large_resource_compiler.CONFIG = no_link target_predeps
large_resource_compiler.input = CONTENT

QMAKE_EXTRA_COMPILERS += large_resource_compiler