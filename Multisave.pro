QT += widgets core gui
CONFIG += qt release
CONFIG += lrelease

HEADERS = src/*.h
SOURCES = src/*.cpp

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
    DEPLOY_COMMAND = windeployqt
}
macx {
    DEPLOY_COMMAND = macdeployqt
}

CONFIG( debug, debug|release ) {
    # debug
    DEPLOY_TARGET = $$shell_quote($$shell_path($${OUT_PWD}/debug/$${TARGET}$${TARGET_CUSTOM_EXT}))
} else {
    # release
    DEPLOY_TARGET = $$shell_quote($$shell_path($${OUT_PWD}/release/$${TARGET}$${TARGET_CUSTOM_EXT}))
}

QMAKE_POST_LINK = $${DEPLOY_COMMAND} $${DEPLOY_TARGET}