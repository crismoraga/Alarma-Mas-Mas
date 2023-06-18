#include "magneticsensor.h"

MagneticSensor::MagneticSensor(int z): Sensor(z){
    view = new MagneticSensorView();
}
void MagneticSensor::setSensorOpen() {
    MagneticSensor::setClose(false);
    view->setOpenView();
}
void MagneticSensor::setSensorClose() {
   MagneticSensor::setClose(true);
    view->setCloseView();
}
MagneticSensorView * MagneticSensor::getView() {
    return view;
}
MagneticSensor::~MagneticSensor(){
    delete view;
}
