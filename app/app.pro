QT       += core gui thelib
SHARE_APP_NAME = theApp

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14
TARGET = theApp

# Include the-libs build tools
include(/usr/share/the-libs/pri/buildmaster.pri)

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    page1/page1.cpp \
    page2/page2.cpp \
    page2/popover/page2_popover.cpp

HEADERS += \
    mainwindow.h \
    page1/page1.h \
    page2/page2.h \
    page2/popover/page2_popover.h

FORMS += \
    mainwindow.ui \
    page1/page1.ui \
    page2/page2.ui \
    page2/popover/page2_popover.ui

unix {
    target.path = /usr/bin/

    desktop.path = /usr/share/applications
    desktop.files = com.zumid.theApp.desktop

    icon.path = /usr/share/icons/hicolor/scalable/apps/
    icon.files = icons/theApp.svg

    INSTALLS += target desktop icon
}

# Turn off stripping as this causes the install to fail :(
QMAKE_STRIP = echo

RESOURCES += \
    resources.qrc

DISTFILES += \
    com.zumid.theApp.desktop