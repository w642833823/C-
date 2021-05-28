QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

DEFINES += QT_MESSAGELOGCONTEXT


SOURCES += \
    dialog.cpp \
    main.cpp \
    widget.cpp

HEADERS += \
    dialog.h \
    widget.h

FORMS += \
    dialog.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
