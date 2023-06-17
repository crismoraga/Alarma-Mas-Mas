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
    Sensor::close = isClose;
    cout << "El sensor esta: "<< (close?"Abierto.":"Cerrado.") << endl;
}
