#ifndef DOOR_H
#define DOOR_H
#include "magneticsensor.h"
class DoorView;

class Door
{
private:
    Door(); // door creation without sensor is not allowed.
public:
    Door(MagneticSensor * sensor, DoorView * v);
    void changeState();
private:
    MagneticSensor * magneticSensor;
    DoorView * view;
    bool isClose;
};

#endif // DOOR_H
