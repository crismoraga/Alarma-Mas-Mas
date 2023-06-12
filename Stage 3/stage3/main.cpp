#include "housewindow.h"
#include <QApplication>
#include <iostream>
#include <fstream>
#include <vector>
#include "door.h"
#include "doorview.h"
#include "central.h"
using namespace std;
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HouseWindow gui;  // gui: Graphical User Interface
    Central central;
    ifstream fin;
    int nDoors, nWindows;
    if (argc != 2) {
        cout << "Usage: "<<argv[0]<<" <configuration_file>" << endl;
        return -1;
    }
    fin.open(argv[1]);
    if (fin.fail()){
        cout << "Could not read file" << endl;
        return -2;
    }
    cout << "Argument:" << argv[1] << endl;
    fin >> nDoors;
    fin >> nWindows;
    cout << "nDoors:" << nDoors << " nWindows: " << nWindows << endl;
    for( int i=0; i<nDoors; i++) {
        int x, y, angle, zone;
        fin >> x >> y >> angle >> zone;
        MagneticSensor * sensor = new MagneticSensor(zone);
        DoorView * doorView = new DoorView(x,y,angle, sensor->getView());
        new Door(sensor, doorView);
        central.addNewSensor(sensor);
        gui.addHouseHollow(doorView);
    }
    gui.show();
    return a.exec();
}
