#include <iostream>
#include <fstream>
#include <vector>
#include "door.h"
using namespace std;

int main(int argc, char * argv[]) {
    ifstream fin;
    int nDoors, junk;
    vector<Door *> doors;
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
