#include "magneticsensor.h"

MagneticSensor::MagneticSensor(int z): ??? {
    view = new MagneticSensorView();
}
void MagneticSensor::setSensorOpen() {
    ??
}
void MagneticSensor::setSensorClose() {
   ??
}
MagneticSensorView * MagneticSensor::getView() {
    return view;
}
MagneticSensor::~MagneticSensor(){
    delete view;
}
