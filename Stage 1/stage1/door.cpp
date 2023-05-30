#include "door.h"

Door::Door()
{

}
Door::Door(MagneticSensor sensor): ???{ //no sé que mas puede heredar
}
void Door::changeState()
{
    if (magneticSensor.isClose())
       magneticSensor.setSensorOpen();
        else
            magneticSensor.setSensorClose();
}

