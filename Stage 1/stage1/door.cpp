#include "door.h"

Door::Door()
{
    //Door::magneticSensor = *new MagneticSensor();
}

Door::Door(MagneticSensor sensor) : magneticSensor(sensor){
}
void Door::changeState()
{
    if (magneticSensor.isClose())
       magneticSensor.setSensorOpen();
        else
            magneticSensor.setSensorClose();
}

