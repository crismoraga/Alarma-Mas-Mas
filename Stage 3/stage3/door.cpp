#include "door.h"
#include "doorview.h"

Door::Door()
{

}
Door::Door(MagneticSensor * sensor, DoorView * v): magneticSensor(sensor), view(v){
    isClose=true;
    view->setDoorModel(this);
}
void Door::changeState() {
    if (isClose) {
        isClose = false;
        magneticSensor->setSensorOpen();
        view->setOpen();
    } else {
        isClose = true;
        magneticSensor->setSensorClose();
        view->setClose();
    }
}

