#include <iostream>
#include <fstream>
#include <vector>
#include "central.h"
#include "door.h"
#include "window.h"

using namespace std;

int main(){
    ifstream fin;
    int nDoors, nWindows, zona=0, zone=0;
    vector<Door *> doors;
    vector<Window *> windows;

    
    if (argc != 2) {
        cout << "Usage: "<<argv[0]<<" <configuration_file>" << endl;
        return -1;
    }
    fin.open(argv[1]);

    //fin.open("C:/Users/Moragax3/Desktop/Tarea3 Poo/stage1/config.txt");
    if (fin.fail()){
        cout << "Could not read file" << endl;
        return -2;
    }
    cout << "Argument:" << "config.txt" << endl;
    fin >> nDoors;
    fin >> nWindows;

    cout << "nDoors:" << nDoors << " nWindows: " << nWindows << endl;

    for( int i=0; i<nDoors; i++) {
        fin >> zona >> zona >> zona >> zone;
        doors.push_back(new Door(zone));
    }
    for (int i = 0; i < nWindows; i++) {
        fin >> zona >> zona >> zona >> zone;
        windows.push_back(new Window(zone));
    }

    for (unsigned int i=0; i<doors.size(); i++) {
        doors[i]->changeState();
        doors[i]->changeState();
    }
    for (unsigned int i=0; i<windows.size(); i++) {
        windows[i]->changeState();
        windows[i]->changeState();
    }

    central *c = new central();
    c->revisarZonas(doors, windows);
    doors[0]->changeState();
    c->revisarZonas(doors, windows);
    delete c;


}
