#include "sensor.h"
#include <iostream>
using namespace std;
Sensor::Sensor(int z, bool close){
   ???
}
bool Sensor::isClose() const {
    ??
}
int Sensor::getZone() const {
    ??
}
void Sensor::setClose(bool isClose) {
    ??
    cout << "Sensor is "<< (close?"close.":"open.") << endl;
}
