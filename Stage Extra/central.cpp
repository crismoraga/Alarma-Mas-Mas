#include "central.h"
#include <iostream>

Central::Central(QObject *parent)
    : QObject(parent), timer(new QTimer(this)) {
    connect(timer, SIGNAL(timeout()), this, SLOT(checkZones()));
    timer ->start(200);
}
void Central::addNewSensor(Sensor * ps){
    zones.push_back(ps);
}
void Central::checkZones() {
    bool closeZones[2];
    checkCloseZones(closeZones);
    if (!closeZones[0] || !closeZones[1])
        cout << "Alguna zona está abierta." << endl;
}
void Central::checkCloseZones(bool closeZones[]) {
    closeZones[0]= closeZones[1] = true;
    for (uint i=0; i< zones.size(); i++)
        if(zones[i]->getZone() == 0)closeZones[0] *=zones[i]->isClose();
        else closeZones[1]*=zones[i]->isClose();
}
Central::~Central(){
    delete timer;
}
