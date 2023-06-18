#include "central.h"
#include <iostream>

Central::Central(QObject *parent)
    : QObject(parent), timer(new QTimer(this)), timerAct(new QTimer(this)), timerDes(new QTimer(this)) {
    connect(timer, SIGNAL(timeout()), this, SLOT(checkZones()));
    connect(timerAct, SIGNAL(timeout()), this, SLOT(changeZone0Build()));
    connect(this, SIGNAL(zone0Open()), this, SLOT(startTD()));
    connect(timerDes, SIGNAL(timeout()), this, SLOT(stopTD()));

    timerAct->start(5000);
    timer ->start(200);
    isTimer = true;
    isClose = true;
    zone0build = true;
}
void Central::addNewSensor(Sensor * ps){
    zones.push_back(ps);
}
void Central::checkZones() {
    bool closeZones[2];
    isClose = true;
    if(isTimer){//Si timer true, revisara, si no, no lo hara
        checkCloseZones(closeZones);
        if(!zone0build){//Si es falso, se chequeara normalemte
            if (!closeZones[0] || !closeZones[1]){
                cout << "Alguna zona está abierta." << endl;
                isClose = false;
            }else{
                isClose = true;
            }
        }else{// si es verdadero, solo chequeara solo la zona 2
            if (!closeZones[1]){
                cout << "Zona 1 está abierta." << endl;
                isClose = false;
            }else{
                isClose = true;
            }
        }
    }
}
void Central::checkCloseZones(bool closeZones[]) {
    closeZones[0]= closeZones[1] = true;
    for (uint i=0; i< zones.size(); i++)
        if(zones[i]->getZone() == 0)closeZones[0] *=zones[i]->isClose();
        else closeZones[1]*=zones[i]->isClose();
    if(!closeZones[0]) emit zone0Open();
}

bool Central::getIsClose(){
    return isClose;
}
void Central::changeZone0Build(){
    zone0build = false;
    checkZones();//llamará a check zones inmediatamente
}
void Central::setZone0Build(bool b){
    zone0build = b;
}
void Central::setIsTimer(bool b){
    isTimer = b;
}

void Central::startTD(){
    timerDes->start();
    zone0build =true;
}

void Central::stopTD(){
    zone0build = false;
    checkZones();
}

Central::~Central(){
    delete timer;
}
