#include "window.h"

Window::Window()
{
}

Window::Window(MagneticSensor sensor) : magneticSensor(sensor){
}

void Window::changeState()
{
    if (magneticSensor.isClose())
        magneticSensor.setSensorOpen();
    else
        magneticSensor.setSensorClose();
}

bool Window::getState(){
    return magneticSensor.isClose();
}
