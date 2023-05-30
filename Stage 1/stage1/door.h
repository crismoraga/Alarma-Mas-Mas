#ifndef DOOR_H
#define DOOR_H
#include "magnetic_sensor.h"
class Door
{
private:
    Door(); // a door creation without sensor is not allowed.
public:
    Door(MagneticSensor sensor);
    void changeState();
private:
    MagneticSensor magneticSensor;
};

#endif // DOOR_H
