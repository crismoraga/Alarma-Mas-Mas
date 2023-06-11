#ifndef DOOR_H
#define DOOR_H
#include "magnetic_sensor.h"
class Door
{
private:
    Door(); // a door creation without sensor is not allowed.
    MagneticSensor magneticSensor;
public:
    Door(MagneticSensor sensor);
    void changeState();
    bool getState();
};

#endif // DOOR_H
