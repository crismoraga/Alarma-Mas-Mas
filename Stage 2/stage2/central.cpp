#include "central.h"

central::central()
{
    zones = new vector<MagneticSensor*>;
}

void central::revisarZonas(vector<Door *> doors, vector<Window *> windows){
    bool isClose = true;
    for (unsigned int i=0; i<doors.size(); i++) {
        isClose *= doors[i]->getState();
    }
    for (unsigned int i=0; i<windows.size(); i++) {
        isClose *= windows[i]->getState();
    }
    if(isClose)cout << "Zonas Cerradas"<< endl;
    else cout << "Alguna zona está abierta"<< endl;
}

void central::agregarSensor(MagneticSensor sensor){
    zones.push_back(sensor);
}
