QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    central.cpp \
    door.cpp \
    doorview.cpp \
    housewindow.cpp \
    magneticsensor.cpp \
    magneticsensorview.cpp \
    main.cpp \
    sensor.cpp \
    window.cpp \
    windowview.cpp

HEADERS += \
    central.h \
    door.h \
    doorview.h \
    housewindow.h \
    magneticsensor.h \
    magneticsensorview.h \
    sensor.h \
    window.h \
    windowview.h

FORMS += \
    housewindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    config.txt
