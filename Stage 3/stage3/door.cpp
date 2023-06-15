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
        isClose = true;
        magneticSensor->setSensorClose();
        view->setClose();
    } else {
        isClose = false;
        magneticSensor->setSensorOpen();
        view->setOpen();
    }
}

