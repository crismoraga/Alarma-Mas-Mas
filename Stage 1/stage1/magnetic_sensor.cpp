#include "magnetic_sensor.h"

MagneticSensor::MagneticSensor(int z)
{
    //no sé que hacer con z
}

void MagneticSensor::setSensorOpen() {
    MagneticSensor::setClose(false);
}
void MagneticSensor::setSensorClose() {
    MagneticSensor::setClose(true);
}
