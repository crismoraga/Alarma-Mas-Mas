#include "magnetic_sensor.h"

MagneticSensor::MagneticSensor(int z):zone(z){
}

void MagneticSensor::setSensorOpen() {
    MagneticSensor::setClose(false);
}
void MagneticSensor::setSensorClose() {
    MagneticSensor::setClose(true);
}
