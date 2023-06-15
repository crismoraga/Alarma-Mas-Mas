#include "magneticsensor.h"

MagneticSensor::MagneticSensor(int z): Sensor(z) {
    view = new MagneticSensorView();
}
void MagneticSensor::setSensorOpen() {
    this->setClose(false);
}
void MagneticSensor::setSensorClose() {
   this->setClose(true);
}
MagneticSensorView * MagneticSensor::getView() {
    return view;
}
MagneticSensor::~MagneticSensor(){
    delete view;
}
