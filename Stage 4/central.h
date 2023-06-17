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
    //QTimer* getTimer();
    ~Central();
    QTimer* timer;
private slots:
    void checkZones();
private:
    void checkCloseZones(bool closeZones[]);
    vector<Sensor *> zones; // keep references to all sensors already installed in doors and windows.
    bool isClose;
};

#endif // CENTRAL_H
