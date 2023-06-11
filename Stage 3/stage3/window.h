#ifndef WINDOW_H
#define WINDOW_H
#include "magnetic_sensor.h"

class Window
{
public:
    Window(MagneticSensor sensor);
    void changeState();
    bool getState();
private:
    Window();
    MagneticSensor magneticSensor;

};

#endif // WINDOW_H
