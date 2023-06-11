#ifndef CENTRAL_H
#define CENTRAL_H
#include "door.h"
#include "window.h"
#include <iostream>
#include <vector>

using namespace std;

class central
{
public:
    central();
    void revisarZonas(vector<Door *> doors, vector<Window *> windows);
};

#endif // CENTRAL_H
