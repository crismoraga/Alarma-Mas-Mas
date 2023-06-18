#include <iostream>
#include <fstream>
#include <vector>
#include "door.h"
using namespace std;

int main(){
    ifstream fin;
    int nDoors, junk;
    vector<Door *> doors;
    
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
    fin >> junk;
    cout << "nDoors:" << nDoors << " junk: " << junk << endl;
    for( int i=0; i<nDoors; i++) {
        int zone;
        fin >> junk >> junk >> zone;
        doors.push_back(new Door(zone));
    }
    for (unsigned int i=0; i<doors.size(); i++) {
        doors[i]->changeState();
        doors[i]->changeState();
    }
}
