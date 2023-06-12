#ifndef MAGNETICSENSOR_H
#define MAGNETICSENSOR_H
#include "sensor.h"
#include "magneticsensorview.h"

class MagneticSensor: public Sensor
{
public:
    MagneticSensor(int z=0);
    ~MagneticSensor();
    void setSensorOpen();
    void setSensorClose();
    MagneticSensorView * getView();
private:
    MagneticSensorView * view;
};

#endif // MAGNETICSENSOR_H
