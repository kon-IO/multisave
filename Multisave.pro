QT += widgets core gui

CONFIG += qt release
CONFIG += lrelease

TRANSLATIONS = translations/multisave_el_GR.ts

# Thanks https://forum.qt.io/topic/86615/build-project-including-all-libs
isEmpty(TARGET_EXT) {
    win32 {
        TARGET_CUSTOM_EXT = .exe
    }
    macx {
        TARGET_CUSTOM_EXT = .app
    }
} else {
    TARGET_CUSTOM_EXT = $${TARGET_EXT}
}

win32 {
    HEADERS = src\*.h
    SOURCES = src\*.cpp
    DEPLOY_COMMAND = windeployqt
}
macx {
    HEADERS = src/*.h
    SOURCES = src/*.cpp
    DEPLOY_COMMAND = macdeployqt
}

CONFIG( debug, debug|release ) {
    # debug
    DEPLOY_TARGET = $$shell_quote($$shell_path($${OUT_PWD}/debug/$${TARGET}$${TARGET_CUSTOM_EXT}))
} else {
    # release
    DEPLOY_TARGET = $$shell_quote($$shell_path($${OUT_PWD}/release/$${TARGET}$${TARGET_CUSTOM_EXT}))
}

win32 {
	QMAKE_POST_LINK = $${DEPLOY_COMMAND} --no-translations --no-virtualkeyboard $${DEPLOY_TARGET}
}
macx {
	QMAKE_POST_LINK = $${DEPLOY_COMMAND} --no-translations --no-virtualkeyboard $${DEPLOY_TARGET}
}