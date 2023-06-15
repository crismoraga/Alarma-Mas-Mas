#include "window.h"
#include "windowview.h"

Window::Window()
{

}

Window::Window(MagneticSensor * sensor, WindowView * v): magneticSensor(sensor), view(v){
    isClose=true;
    view->setWindowModel(this);
}
void Window::changeState() {
    if (isClose) {
        isClose = true;
        magneticSensor->setSensorClose();
    } else {
        isClose = false;
        magneticSensor->setSensorOpen();
    }
}
