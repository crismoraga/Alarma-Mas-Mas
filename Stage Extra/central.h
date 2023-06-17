#ifndef CENTRAL_H
#define CENTRAL_H
#include <QObject>
#include <vector>
#include <QTimer>
#include "sensor.h"
using namespace std; //needed by vector<>

class Central : public QObject
{
    Q_OBJECT
public:
    explicit Central(QObject *parent = nullptr);
    void addNewSensor(Sensor * ps);
    bool getIsClose();
    void setZone0Build(bool);
    void setIsTimer(bool);
    void stopTD();
    //QTimer* getTimer();
    ~Central();
    QTimer* timer;
    QTimer* timerAct;
    QTimer* timerDes;
signals:
    void zone0Open();

private slots:
    void checkZones();
    void changeZone0Build();
    void startTD();
private:
    void checkCloseZones(bool closeZones[]);
    vector<Sensor *> zones; // keep references to all sensors already installed in doors and windows.
    bool isClose;
    bool zone0build;
    bool isTimer;
};

#endif // CENTRAL_H
