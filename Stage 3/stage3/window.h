#ifndef WINDOW_H
#define WINDOW_H
#include "magneticsensor.h"
class WindowView;

class Window
{
private:
    Window();
public:
    Window(MagneticSensor * sensor, WindowView * v);
    void changeState();
private:
    MagneticSensor * magneticSensor;
    WindowView * view;
    bool isClose;
};

#endif // WINDOW_H
