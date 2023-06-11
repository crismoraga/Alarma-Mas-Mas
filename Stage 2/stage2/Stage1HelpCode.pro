TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        central.cpp \
        door.cpp \
        magnetic_sensor.cpp \
        main.cpp \
        sensor.cpp \
        window.cpp

HEADERS += \
    central.h \
    door.h \
    magnetic_sensor.h \
    sensor.h \
    window.h

DISTFILES += \
    config.txt \
