TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        door.cpp \
        magnetic_sensor.cpp \
        main.cpp \
        sensor.cpp

HEADERS += \
    door.h \
    magnetic_sensor.h \
    sensor.h

DISTFILES += \
    config.txt
