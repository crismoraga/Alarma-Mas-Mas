#include "sensor.h"
#include <iostream>
using namespace std;
Sensor::Sensor(int z, bool close){
    this->close = close;
    zone = z;
}
bool Sensor::isClose() const {
    return Sensor::close;
}
int Sensor::getZone() const {
    return Sensor::zone;
}
void Sensor::setClose(bool isClose) {
    //cambiamos su estado al pedido
    Sensor::close = isClose;
    cout << "Sensor is "<< (close?"close.":"open.") << endl;
}
