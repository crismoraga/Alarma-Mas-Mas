#include "magneticsensor.h"

MagneticSensor::MagneticSensor(int z): Sensor(z){
    view = new MagneticSensorView();
}
void MagneticSensor::setSensorOpen() {
    MagneticSensor::setClose(false);
    //quizá algo con la view?
}
void MagneticSensor::setSensorClose() {
   MagneticSensor::setClose(true);
    //quizá algo con la view?
}
MagneticSensorView * MagneticSensor::getView() {
    return view;
}
MagneticSensor::~MagneticSensor(){
    delete view;
}
