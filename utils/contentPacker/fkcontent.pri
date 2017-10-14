
large_resource_compiler.output   = "$$system_path($${FK_CONST_APP_DATA_DESTINATION}/universalResources/${QMAKE_FILE_IN_BASE}.rcc)"
large_resource_compiler.commands = "$$system_path($$[QT_INSTALL_BINS]/rcc)" --binary --no-compress "${QMAKE_FILE_NAME}" -o "${QMAKE_FILE_OUT}"
large_resource_compiler.CONFIG = no_link target_predeps
large_resource_compiler.input = CONTENT

QMAKE_EXTRA_COMPILERS += large_resource_compiler


raw_content_compiler.output = "$$system_path($${FK_CONST_APP_DATA_DESTINATION}/rawContent/${QMAKE_FILE_BASE}${QMAKE_FILE_EXT})"
raw_content_compiler.commands = $(COPY_FILE) ${QMAKE_FILE_IN} ${QMAKE_FILE_OUT}
raw_content_compiler.CONFIG = no_link target_predeps
raw_content_compiler.input = RAW_CONTENT


QMAKE_EXTRA_COMPILERS += raw_content_compiler
